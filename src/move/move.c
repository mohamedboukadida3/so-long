/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:51:17 by mboukadi          #+#    #+#             */
/*   Updated: 2023/07/10 00:27:23 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	right_move(t_map *map, int i, int j)
{
	if (map->full[j][i] == 'E')
	{
		if (map->collect == 0)
			return (0);
		ft_printf("\nYou Have Won, Congrats!\n");
		end(map);
	}
	if (map->full[j][i] == '0')
	{
		map->full[j][i] = 'P';
		map->player_x = i;
		map->player_y = j;
		map->moves++;
	}
	if (map->full[j][i] == 'C')
	{
		map->full[j][i] = 'P';
		map->player_x = i;
		map->player_y = j;
		map->collect--;
		map->moves++;
	}
	return (0);
}

static int	keyboard_w_s(t_map *map, int movement)
{
	int	i;
	int	j;

	i = map->player_x;
	j = map->player_y;
	if (movement == 13 || movement == 126)
	{
		j--;
		if (map->full[j][i] == '1')
			return (0);
		right_move(map, i, j);
		map->full[j + 1][i] = '0';
	}
	else if (movement == 1 || movement == 125)
	{
		j++;
		if (map->full[j][i] == '1')
			return (0);
		right_move(map, i, j);
		map->full[j - 1][i] = '0';
	}
	ft_printf("Steps Taken: %i\n", map->moves);
	return (1);
}

static int	keyboard_a_d(t_map *map, int movement)
{
	int	i;
	int	j;

	i = map->player_x;
	j = map->player_y;
	if (movement == 0 || movement == 123)
	{
		i--;
		if (map->full[j][i] == '1')
			return (0);
		right_move(map, i, j);
		map->full[j][i + 1] = '0';
	}
	else if (movement == 2 || movement == 124)
	{
		i++;
		if (map->full[j][i] == '1')
			return (0);
		right_move(map, i, j);
		map->full[j][i - 1] = '0';
	}
	ft_printf("Steps Taken: %i\n", map->moves);
	return (1);
}

int	ft_key(int key, t_map *map)
{
	int	s;

	if (key == 53)
		exit(0);
	if (key == 13 || key == 126)
		s = keyboard_w_s(map, key);
	if (key == 2 || key == 124)
		s = keyboard_a_d(map, key);
	if (key == 0 || key == 123)
		s = keyboard_a_d(map, key);
	if (key == 1 || key == 125)
		s = keyboard_w_s(map, key);
	if (s)
		adding_in_graphics(map);
	return (EXIT_SUCCESS);
}
