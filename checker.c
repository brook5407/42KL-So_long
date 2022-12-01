/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:03:04 by chchin            #+#    #+#             */
/*   Updated: 2022/08/01 15:03:07 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* error if the map is not end with .ber*/
static void	check_filename(const char *path)
{
	int			i;
	const int	fd = open(path, O_RDONLY);

	i = ft_strlen(path);
	if (ft_strncmp(path + i - 4, ".ber", 4) != 0 || fd < 0)
		error_filename();
}

/* error if the map is not rectangular, not cover by wall(1)
 * or has empty newline */
static void	check_map_format(const char *path, t_map *map)
{
	char		*line;
	int			i;
	int			j;
	const int	fd = open(path, O_RDONLY);

	i = 0;
	while (i++ < map->y)
	{
		line = get_next_line(fd);
		if ((int)ft_strlen(line) - 1 != map->x && i < map->y)
			error_rectangular();
		if ((int)ft_strlen(line) != map->x && i == map->y)
			error_rectangular();
		if (i == 1 || i == map->y)
		{
			j = 0;
			while (j < map->x)
				if (line[j++] != '1')
					error_wall();
		}
		else if (line[0] != '1' || line[map->x - 1] != '1')
			error_wall();
		free(line);
	}
	close(fd);
}

static void	check_character(t_map *map, char *line)
{
	while (*line != '\n' && *line)
	{
		if (*line == '1')
			map->w1.data++;
		else if (*line == '0')
			map->f0.data++;
		else if (*line == 'C')
			map->c.data++;
		else if (*line == 'E')
			map->e.data++;
		else if (*line == 'P')
			map->p.data++;
		else if (*line == 'V')
			map->v.data++;
		else if (*line == 'H')
			map->h.data++;
		else
			error_element();
		line++;
	}
}

/* error if the map is no exit/ no collectible/ no player
 * or more than 1 player */
static void	check_sprites_format(const char *path, t_map *map)
{
	char		*line;
	int			i;
	const int	fd = open(path, O_RDONLY);

	i = 0;
	while (i++ < map->y)
	{
		line = get_next_line(fd);
		check_character(map, line);
		free(line);
	}
	close(fd);
	error_sprites(map);
}

/* error if the map has newline */
void	check_map(char *path, t_map *map)
{
	int		i;
	char	*line;
	int		fd;

	check_filename(path);
	fd = open(path, O_RDONLY);
	i = 0;
	while (i++ < (map->y - 1))
	{
		line = get_next_line(fd);
		free(line);
	}
	line = get_next_line(fd);
	if (ft_strchr(line, '\n'))
	{
		ft_putstr_fd("Error\nEmpty newline detected\n", STDERR_FILENO);
		exit(STDERR_FILENO);
	}
	free(line);
	close(fd);
	check_map_format(path, map);
	check_sprites_format(path, map);
}
