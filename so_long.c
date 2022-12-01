/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:30:15 by chchin            #+#    #+#             */
/*   Updated: 2022/07/29 14:30:23 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(t_game *g, t_map *m, int x, int y)
{
	if (m->map[y][x] == 'V' || m->map[y][x] == 'H')
	{
		ft_printf("You Lose!");
		free_game(m, g);
	}
	else if (m->collected == m->c.data)
	{
		ft_printf("You won in %d steps!", m->moves);
		free_game(m, g);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		init_map(&game.map);
		get_map_size(&game.map, argv[1]);
		check_map(argv[1], &game.map);
		game_init(&game.map, &game, argv[1]);
		mlx_hook(game.win, 17, 0, &quit_game, &game);
		mlx_key_hook(game.win, &key_press, &game);
		mlx_loop(game.mlx);
	}
	ft_putstr_fd("Please try:\n./so_long [map file]\n", 2);
	return (0);
}
