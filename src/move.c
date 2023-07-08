/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:51:17 by mboukadi          #+#    #+#             */
/*   Updated: 2023/07/08 00:59:50 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key(t_map *map, int key)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (key == 53)
		ft_exit(map);
	if (key == 13)
		ft_move_up(map, x, y + 1);
	if (key == 2)
		ft_move_right(map, x + 1, y);
	if (key == 0)
		ft_move_left(map, x - 1, y);
	if (key == 1)
		ft_move_down(map, x, y - 1);
	return (0);
}

void	ft_move(t_map *map, int x, int y)
{
	x = map->player_x;
	y = map->player_y;
	if (map->full[y][x] == '1')
		return ;
	else if (map->full[y][x] == 'E' && map->collect != 0)
		return ;
	else if (map->full[y][x] == 'E' && map->collect == 0)
		exit(EXIT_SUCCESS);
	else if (map->full[y][x] == '0')
	{
		put_images_in_game(map->floor);
		put_images_in_game(map->player_right);
	}
	else if (map->full[y][x] == 'C')
		ft_collect(map);
	map->player_x = x;
	map->player_y = y;
	map->moves += 1;
	ft_print_moves(map);
}

int	move_up(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] == '0')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y - 1][game->player_x] = 'P';
		game->player_y--;
	}
	else if (game->map[game->player_y - 1][game->player_x] == 'C')
	{
		up_coin(game);
	}
	else if (game->map[game->player_y - 1][game->player_x] == 'E'
				&& game->coin_count == 0)
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y - 1][game->player_x] = 'P';
		close_game(game);
	}
	else if (game->map[game->player_y - 1][game->player_x] == 'N')
	{
		ft_printf("You lost!\n");
		close_game(game);
	}
	return (1);
}
