/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:56:27 by mboukadi          #+#    #+#             */
/*   Updated: 2023/07/10 00:21:05 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init_mlx(t_map *map)
{
	map->mlx_ptr = mlx_init();
	if (map->mlx_ptr == 0)
		ft_printf("error\n");
	map->win_ptr = mlx_new_window(map->mlx_ptr, (map->count_caracter * 64),
			(map->line * 64), "so_long");
	if (map->win_ptr == 0)
		ft_printf("error\n");
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
	map->collect = 0;
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

int	end(t_map *map)
{
	free(map->full);
	mlx_destroy_image(map->mlx_ptr, map->wall);
	mlx_destroy_image(map->mlx_ptr, map->floor);
	mlx_destroy_image(map->mlx_ptr, map->items);
	mlx_destroy_image(map->mlx_ptr, map->player);
	mlx_destroy_image(map->mlx_ptr, map->exit);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	free(map->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	ft_print_movements(t_map *map)
{
	char	*movements;
	char	*phrase;

	movements = ft_itoa(map->moves);
	phrase = ft_strjoin("Movements : ", movements);
	mlx_string_put(map->mlx_ptr, map->win_ptr, 30, 30, 0xFF0000, phrase);
	free(movements);
	free(phrase);
}
