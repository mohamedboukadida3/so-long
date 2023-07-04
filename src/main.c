/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:15:59 by mboukadi          #+#    #+#             */
/*   Updated: 2023/07/04 19:40:33 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	map;
	t_game	game;
	int		i;
	int		j;
	int		x;
	int		y;

	if (check_arg(ac, av) == 0)
		exit(EXIT_FAILURE);
	ft_line_count(&map, av[1]);
	ft_init_map(&map, av[1]);
	ft_copy_map(&map, av[1]);
	ft_valid_caracter(&map);
	ft_valid_number_element(&map, 0, 0, 0);
	ft_is_closed(&map);
	ft_is_rectangle(&map);
	is_valid_path(&map);
	check_after_fill(&map);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 64 * map.count_caracter, 64 * map.line, "Hello world!");
	game.floor.image_path = "./src/image/floor.xpm";
	game.player.image_path = "./src/image/player.xpm";
	game.items.image_path = "./src/image/items.xpm";
	game.wall.image_path = "./src/image/wall.xpm";
	game.exit.image_path = "./src/image/exit.xpm";
	game.floor.image_ptr = mlx_xpm_file_to_image(game.mlx, game.floor.image_path, &game.floor.height_image, &game.floor.lenght_image);
	game.player.image_ptr = mlx_xpm_file_to_image(game.mlx, game.player.image_path, &game.player.height_image, &game.player.lenght_image);
	game.items.image_ptr = mlx_xpm_file_to_image(game.mlx, game.items.image_path, &game.items.height_image, &game.items.lenght_image);
	game.wall.image_ptr = mlx_xpm_file_to_image(game.mlx, game.wall.image_path, &game.wall.height_image, &game.wall.lenght_image);
	game.exit.image_ptr = mlx_xpm_file_to_image(game.mlx, game.exit.image_path, &game.exit.height_image, &game.exit.lenght_image);
	i = -1;
	x = 0;
	y = 0;
	while (map.full[++i])
	{
		j = -1;
		while (map.full[i][++j])
		{
			if (map.full[i][j])
				mlx_put_image_to_window(game.mlx, game.win, game.floor.image_ptr, x, y);
			if (map.full[i][j] == '1')
				mlx_put_image_to_window(game.mlx, game.win, game.wall.image_ptr, x, y);
			else if (map.full[i][j] == 'P')
				mlx_put_image_to_window(game.mlx, game.win, game.player.image_ptr, x, y);
			else if (map.full[i][j] == 'C')
				mlx_put_image_to_window(game.mlx, game.win, game.items.image_ptr, x, y);
			else if (map.full[i][j] == 'E')
				mlx_put_image_to_window(game.mlx, game.win, game.exit.image_ptr, x, y);
			x = x + 64;
		}
		x = 0;
		y = y + 64;
	}
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
//system ("leaks so_long");