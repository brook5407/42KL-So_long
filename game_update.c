/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:52:27 by chchin            #+#    #+#             */
/*   Updated: 2022/08/08 09:52:28 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy_vertical(t_game *g, t_map *m)
{
	int	x;
	int	y;

	x = -1;
	while (++x < m->x)
	{
		y = -1;
		while (++y < m->y)
		{
			if (m->map[y][x] == 'V' && (m->map[y + 1][x] == 'P'
				|| m->map[y - 1][x] == 'P'))
				end_game(g, m, x, y);
			if (m->map[y][x] == 'V' && m->map[y - 1][x] == '0')
			{
				m->map[y - 1][x] = 'V';
				m->map[y][x] = '0';
			}
			else if (m->map[y][x] == 'V' && m->map[y + 1][x] == '0')
			{
				m->map[y + 1][x] = 'V';
				m->map[y++][x] = '0';
			}
		}
	}
	m->v.data++;
}

void	move_enemy_horizontal(t_game *g, t_map *m)
{
	int	x;
	int	y;

	y = -1;
	while (++y < m->y)
	{
		x = -1;
		while (++x < m->x)
		{
			if (m->map[y][x] == 'H' && (m->map[y][x - 1] == 'P'
				|| m->map[y][x + 1] == 'P'))
				end_game(g, m, x, y);
			if (m->map[y][x] == 'H' && m->map[y][x - 1] == '0')
			{
				m->map[y][x - 1] = 'H';
				m->map[y][x] = '0';
			}
			else if (m->map[y][x] == 'H' && m->map[y][x + 1] == '0')
			{
				m->map[y][x + 1] = 'H';
				m->map[y][x++] = '0';
			}
		}
	}
	m->h.data++;
}

static void	dir_player(int keycode, t_map *m)
{
	if (keycode == KEY_A)
		m->p.dir = 2;
	else if (keycode == KEY_W)
		m->p.dir = 1;
	else if (keycode == KEY_S)
		m->p.dir = 0;
	else if (keycode == KEY_D)
		m->p.dir = 3;
}

static void	move_player(t_game *g, t_map *m, int x, int y)
{
	const int	new_pos_x = m->p.pos.x + x;
	const int	new_pos_y = m->p.pos.y + y;

	if (m->map[new_pos_y][new_pos_x] == '0')
	{
		m->map[m->p.pos.y][m->p.pos.x] = '0';
		m->map[new_pos_y][new_pos_x] = 'P';
		m->p.pos.x = new_pos_x;
		m->p.pos.y = new_pos_y;
		move_enemy_vertical(g, m);
		move_enemy_horizontal(g, m);
	}
	else if (m->map[new_pos_y][new_pos_x] == 'C')
	{
		m->map[m->p.pos.y][m->p.pos.x] = '0';
		m->map[new_pos_y][new_pos_x] = 'P';
		m->p.pos.x = new_pos_x;
		m->p.pos.y = new_pos_y;
		move_enemy_vertical(g, m);
		move_enemy_horizontal(g, m);
		m->collected++;
	}
	else if (ft_strchr("EVH", m->map[new_pos_y][new_pos_x]))
		end_game(g, m, new_pos_x, new_pos_y);
}

int	key_press(int keycode, t_game *g)
{
	if (keycode == KEY_ESC)
	{
		free_game(&g->map, g);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_A || keycode == KEY_D || keycode == KEY_S
		|| keycode == KEY_W)
	{
		g->map.moves++;
		mlx_clear_window(g->mlx, g->win);
		if (keycode == KEY_A)
			move_player(g, &g->map, -1, 0);
		else if (keycode == KEY_W)
			move_player(g, &g->map, 0, -1);
		else if (keycode == KEY_S)
			move_player(g, &g->map, 0, 1);
		else if (keycode == KEY_D)
			move_player(g, &g->map, 1, 0);
		dir_player(keycode, &g->map);
		game_draw(&g->map, g);
	}
	ft_printf("Steps: %d\n", g->map.moves);
	return (0);
}
