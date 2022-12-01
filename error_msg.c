/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 09:39:32 by chchin            #+#    #+#             */
/*   Updated: 2022/08/02 09:39:35 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_filename(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd("Invalid file", STDERR_FILENO);
	exit(STDERR_FILENO);
}

void	error_wall(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd("Map is not surrounded by wall", STDERR_FILENO);
	exit(STDERR_FILENO);
}

void	error_rectangular(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd("Map is not rectangular", STDERR_FILENO);
	exit(STDERR_FILENO);
}

void	error_element(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd("Invalid character detected", STDERR_FILENO);
	exit(STDERR_FILENO);
}

void	error_sprites(t_map *map)
{
	if (map->p.data != 1)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		if (map->p.data == 0)
			ft_putendl_fd("No player in map", STDERR_FILENO);
		else
			ft_putendl_fd("Too many players in map", STDERR_FILENO);
		exit(STDERR_FILENO);
	}
	if (map->e.data == 0)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		ft_putendl_fd("No exit in map", STDERR_FILENO);
		exit(STDERR_FILENO);
	}
	if (map->c.data == 0)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		ft_putendl_fd("No collectible in map", STDERR_FILENO);
		exit(STDERR_FILENO);
	}
}
