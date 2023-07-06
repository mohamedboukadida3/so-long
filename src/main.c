/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:15:59 by mboukadi          #+#    #+#             */
/*   Updated: 2023/07/06 19:22:07 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	map;

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
	ft_init_game(&map);
	adding_in_graphics(&map);
	mlx_loop_hook(map.mlx_ptr, &adding_in_graphics, &map);
	mlx_hook(map.mlx_ptr, 2, 0, &ft_key, &map);
	mlx_hook(map.mlx_ptr, 17, 0, &ft_exit, NULL);
	mlx_loop(map.mlx_ptr);
	return (EXIT_SUCCESS);
}
	//system ("leaks so_long");
