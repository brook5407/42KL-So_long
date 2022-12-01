/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:38:55 by chchin            #+#    #+#             */
/*   Updated: 2022/08/08 09:38:57 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_player_map(t_map *map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= 4)
	{
		while (j <= 4)
			mlx_destroy_image(game->mlx, map->p.a[i][j++].img);
		i++;
	}
	i = 0;
	while (i < map->y)
		free(map->map[i++]);
	free(map->map);
}

void	free_game(t_map *map, t_game *game)
{
	free_player_map(map, game);
	if (map->f0.img)
		mlx_destroy_image(game->mlx, map->f0.img);
	if (map->w1.img)
		mlx_destroy_image(game->mlx, map->w1.img);
	if (map->c.img)
		mlx_destroy_image(game->mlx, map->c.img);
	if (map->e.img)
		mlx_destroy_image(game->mlx, map->e.img);
	if (map->e.img2)
		mlx_destroy_image(game->mlx, map->e.img2);
	if (map->v.img)
		mlx_destroy_image(game->mlx, map->v.img);
	if (map->v.img2)
		mlx_destroy_image(game->mlx, map->v.img2);
	if (map->h.img)
		mlx_destroy_image(game->mlx, map->h.img);
	if (map->h.img2)
		mlx_destroy_image(game->mlx, map->h.img2);
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}

int	quit_game(t_game *g)
{
	free_game(&g->map, g);
	return (0);
}
