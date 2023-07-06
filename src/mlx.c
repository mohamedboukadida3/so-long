/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:25:52 by mboukadi          #+#    #+#             */
/*   Updated: 2023/07/06 19:27:18 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_game(t_map *map)
{
	map->mlx_ptr = mlx_init();
	if (map->mlx_ptr == 0)
		ft_printf("error\n");
	map->win_ptr = mlx_new_window(map->mlx_ptr, (map->count_caracter * 64),
			(map->line * 64), "so_long");
	if (map->win_ptr == 0)
		ft_printf("error\n");
}

void	put_player(t_map *map, int y, int x)
{
	mlx_put_image_to_window(map->mlx_ptr,
		map->win_ptr, map->player_right, y * 64, x * 64);
}

void	put_items(t_map *map, int y, int x)
{
	mlx_put_image_to_window(map->mlx_ptr,
		map->win_ptr, map->items, y * 64, x * 64);
}

void	put_images_in_game(t_map *map)
{
	int	i;
	int	j;

	map->floor = mlx_xpm_file_to_image(map->mlx_ptr,
			"./src/image/floor.xpm", &i, &j);
	map->wall = mlx_xpm_file_to_image(map->mlx_ptr,
			"./src/image/wall.xpm", &i, &j);
	map->player_right = mlx_xpm_file_to_image(map->mlx_ptr,
			"./src/image/player_right.xpm", &i, &j);
	map->player_left = mlx_xpm_file_to_image(map->mlx_ptr,
			"./src/image/player_left.xpm", &i, &j);
	map->exit = mlx_xpm_file_to_image(map->mlx_ptr,
			"./src/image/exit.xpm", &i, &j);
	map->items = mlx_xpm_file_to_image(map->mlx_ptr,
			"./src/image/items.xpm", &i, &j);
}

void	adding_in_graphics(t_map *map)
{
	int	i;
	int	j;

	put_images_in_game(map);
	i = -1;
	while (map->full[++i])
	{
		j = -1;
		while (map->full[i][++j])
		{
			mlx_put_image_to_window(map->mlx_ptr,
				map->win_ptr, map->floor, j * 64, i * 64);
			if (map->full[i][j] == '1')
				mlx_put_image_to_window(map->mlx_ptr,
					map->win_ptr, map->wall, j * 64, i * 64);
			else if (map->full[i][j] == 'C')
				put_items(map, j, i);
			else if (map->full[i][j] == 'P')
				put_player(map, j, i);
			else if (map->full[i][j] == 'E')
				mlx_put_image_to_window(map->mlx_ptr,
					map->win_ptr, map->exit, j * 64, i * 64);
		}
	}
}
