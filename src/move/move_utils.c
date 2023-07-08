/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:56:27 by mboukadi          #+#    #+#             */
/*   Updated: 2023/07/08 17:14:56 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_print_moves(t_map *map)
{
	ft_printf("You made ");
	ft_putnbr_fd(map->moves, 1);
	if (map->moves == 1)
		ft_printf(" move\r", 1);
	else
		ft_printf(" moves\r", 1);
	return (map->moves);
}

void	ft_position_player(t_map *map)
{
	int	x;
	int	y;

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

int	ft_collect(t_map *map)
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
	return (map->collect);
}
