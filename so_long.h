/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:30:05 by chchin            #+#    #+#             */
/*   Updated: 2022/07/29 14:30:08 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include "libft/libft.h"

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_img
{
	void	*img;
}	t_img;

typedef struct s_player
{
	int			data;
	int			dir;
	int			cont;
	t_vector	pos;
	t_img		a[4][4];
}	t_player;

typedef struct s_sprite
{
	int		data;
	void	*img;
	void	*img2;
}	t_sprite;

typedef struct s_map
{
	int			width;
	int			height;
	int			x;
	int			y;
	int			px;
	int			moves;
	int			collected;
	char		**map;
	t_sprite	f0;
	t_sprite	w1;
	t_sprite	c;
	t_sprite	e;
	t_sprite	v;
	t_sprite	h;
	t_player	p;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
}	t_game;

void	error_filename(void);
void	error_wall(void);
void	error_rectangular(void);
void	error_element(void);
void	error_sprites(t_map *map);
void	check_map(char *path, t_map *map);

void	init_map(t_map *map);
void	get_map_size(t_map *map, char *path);
void	game_init(t_map *map, t_game *g, char *argv);

void	game_draw(t_map *m, t_game *g);
void	end_game(t_game *g, t_map *m, int x, int y);

int		key_press(int keycode, t_game *g);

void	free_game(t_map *map, t_game *game);
int		quit_game(t_game *g);

#endif
