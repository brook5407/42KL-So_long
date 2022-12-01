/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_put_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:00:18 by chchin            #+#    #+#             */
/*   Updated: 2022/08/08 10:00:20 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_player_animation(t_map *m, t_game *g)
{
	void	*(*f)(void *, char *, int *, int *);

	f = mlx_xpm_file_to_image;
	m->p.a[0][0].img = f(g->mlx, "./srs/b1.xpm", &m->px, &m->px);
	m->p.a[0][1].img = f(g->mlx, "./srs/b2.xpm", &m->px, &m->px);
	m->p.a[0][2].img = f(g->mlx, "./srs/b1.xpm", &m->px, &m->px);
	m->p.a[0][3].img = f(g->mlx, "./srs/b3.xpm", &m->px, &m->px);
	m->p.a[1][0].img = f(g->mlx, "./srs/t1.xpm", &m->px, &m->px);
	m->p.a[1][1].img = f(g->mlx, "./srs/t2.xpm", &m->px, &m->px);
	m->p.a[1][2].img = f(g->mlx, "./srs/t1.xpm", &m->px, &m->px);
	m->p.a[1][3].img = f(g->mlx, "./srs/t3.xpm", &m->px, &m->px);
	m->p.a[2][0].img = f(g->mlx, "./srs/l1.xpm", &m->px, &m->px);
	m->p.a[2][1].img = f(g->mlx, "./srs/l2.xpm", &m->px, &m->px);
	m->p.a[2][2].img = f(g->mlx, "./srs/l1.xpm", &m->px, &m->px);
	m->p.a[2][3].img = f(g->mlx, "./srs/l3.xpm", &m->px, &m->px);
	m->p.a[3][0].img = f(g->mlx, "./srs/r1.xpm", &m->px, &m->px);
	m->p.a[3][1].img = f(g->mlx, "./srs/r2.xpm", &m->px, &m->px);
	m->p.a[3][2].img = f(g->mlx, "./srs/r1.xpm", &m->px, &m->px);
	m->p.a[3][3].img = f(g->mlx, "./srs/r3.xpm", &m->px, &m->px);
}

static void	game_load(t_map *m, t_game *g)
{
	void	*(*f)(void *, char *, int *, int *);

	f = mlx_xpm_file_to_image;
	load_player_animation(m, g);
	m->v.img = f(g->mlx, "./srs/v1.xpm", &m->px, &m->px);
	m->v.img2 = f(g->mlx, "./srs/v2.xpm", &m->px, &m->px);
	m->h.img = f(g->mlx, "./srs/h1.xpm", &m->px, &m->px);
	m->h.img2 = f(g->mlx, "./srs/h2.xpm", &m->px, &m->px);
	m->c.img = f(g->mlx, "./srs/c.xpm", &m->px, &m->px);
	m->e.img = f(g->mlx, "./srs/e1.xpm", &m->px, &m->px);
	m->e.img2 = f(g->mlx, "./srs/e2.xpm", &m->px, &m->px);
	m->f0.img = f(g->mlx, "./srs/f.xpm", &m->px, &m->px);
	m->w1.img = f(g->mlx, "./srs/w.xpm", &m->px, &m->px);
}

static void	put_floor(t_map *m, t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < m->height)
	{
		x = 0;
		while (x <= m->width)
		{
			mlx_put_image_to_window(g->mlx, g->win, m->f0.img, x, y);
			x += m->px;
		}
		y += m->px;
	}
}

static void	put_element(t_map *m, t_game *g, int x, int y)
{
	if (m->map[y][x] == '1')
		mlx_put_image_to_window(g->mlx, g->win, m->w1.img, x * 45, y * 45);
	else if (m->map[y][x] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, m->c.img, x * 45, y * 45);
	else if (m->map[y][x] == 'P')
	{
		m->p.pos.x = x;
		m->p.pos.y = y;
		mlx_put_image_to_window(g->mlx, g->win, \
		m->p.a[m->p.dir][m->p.cont++ % 4].img, x * 45, y * 45);
	}
	else if (m->map[y][x] == 'E' && m->collected != m->c.data)
		mlx_put_image_to_window(g->mlx, g->win, m->e.img, x * 45, y * 45);
	else if (m->map[y][x] == 'E' && m->collected == m->c.data)
		mlx_put_image_to_window(g->mlx, g->win, m->e.img2, x * 45, y * 45);
	else if (m->map[y][x] == 'V' && m->v.data % 2 == 0)
		mlx_put_image_to_window(g->mlx, g->win, m->v.img, x * 45, y * 45);
	else if (m->map[y][x] == 'V' && m->v.data % 2 == 1)
		mlx_put_image_to_window(g->mlx, g->win, m->v.img2, x * 45, y * 45);
	else if (m->map[y][x] == 'H' && m->v.data % 2 == 0)
		mlx_put_image_to_window(g->mlx, g->win, m->h.img, x * 45, y * 45);
	else if (m->map[y][x] == 'H' && m->v.data % 2 == 1)
		mlx_put_image_to_window(g->mlx, g->win, m->h.img2, x * 45, y * 45);
}

void	game_draw(t_map *m, t_game *g)
{
	int		x;
	int		y;
	char	*itoa;
	char	*display;

	y = 0;
	game_load(m, g);
	put_floor(m, g);
	itoa = ft_itoa(m->moves);
	display = ft_strjoin("Steps: ", itoa);
	free(itoa);
	mlx_string_put(g->mlx, g->win, 30, m->height, 0xFFFFFF, display);
	free(display);
	while (y < m->y)
	{
		x = 0;
		while (m->map[y][x])
		{
			put_element(m, g, x, y);
			x++;
		}
		y++;
	}
}
