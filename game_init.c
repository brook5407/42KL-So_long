/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:03:38 by chchin            #+#    #+#             */
/*   Updated: 2022/08/03 15:03:39 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*initialize the map value */
void	init_map(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->x = 0;
	map->y = 0;
	map->px = 0;
	map->moves = 0;
	map->collected = 0;
	map->f0.data = 0;
	map->w1.data = 0;
	map->p.data = 0;
	map->e.data = 0;
	map->c.data = 0;
	map->p.dir = 0;
	map->p.cont = 0;
	map->map = NULL;
}

/* calculate the vertical and horizontal size of map */
void	get_map_size(t_map *map, char *path)
{
	char		*line;
	int			height;
	const int	fd = open(path, O_RDONLY);

	line = get_next_line(fd);
	height = 0;
	if (line == NULL)
	{
		free(line);
		close(fd);
		return ;
	}
	map->x = ft_strlen(line) - 1;
	map->width = map->x * 45;
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	map->y = height;
	map->height = map->y * 45;
	free(line);
	close(fd);
}

//initialize the game
void	game_init(t_map *m, t_game *g, char *argv)
{
	int			y;
	const int	fd = open(argv, O_RDONLY);

	y = 0;
	m->map = malloc(sizeof(char *) * m->y + 1);
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, m->width, m->height + 30, "so_long");
	while (y < m->y)
		m->map[y++] = get_next_line(fd);
	game_draw(m, g);
}
