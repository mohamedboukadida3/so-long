/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:56:27 by mboukadi          #+#    #+#             */
/*   Updated: 2023/07/06 19:45:37 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_position_player(t_map *map, int x, int y)
{
	y = -1;
	while (map->full[++y])
	{
		x = -1;
		while (map->full[y][++x])
		{
			if (map->full[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
			}
		}
	}
}

void	ft_collect(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (map->full[++y])
	{
		x = -1;
		while (map->full[y][++x])
		{
			if (map->full[y][x] == 'C')
				map->collect++;
		}
	}
}

void	ft_move(t_map *map, int x, int y)
{
	x = map->player_x;
	y = map->player_y;
	if (map->full[y][x] == '1')
		return ;
	else if (map->full[y][x] == 'E' && map->collect != 0)
	{
		ft_printf("there are still items left\n");
		return ;
	}
	else if (map->full[y][x] == 'E' && map->collect == 0)
	{
		ft_printf("congratulations go win\n");
		exit(EXIT_SUCCESS);
	}
}

int	ft_key(t_map *map, int key)
{
	int	x;
	int	y;

	y = map->player_y;
	x = map->player_x;
	map->full[y][x] = '0';
	if (key == 53)
		ft_exit(map);
	if (key == 13)
		ft_move(map, y, x + 1);
	if (key == 2)
		ft_move(map, y + 1, x);
	if (key == 0)
		ft_move(map, y - 1, x);
	if (key == 1)
		ft_move(map, y, x - 1);
	return (0);
}

int	ft_exit(t_map *map)
{
	free(map->full);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	exit(EXIT_SUCCESS);
}
