/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:51:17 by mboukadi          #+#    #+#             */
/*   Updated: 2023/07/08 17:17:49 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	right_move(t_map *map, int i, int j)
{
	if (map->full[j][i] == 'E')
	{
		if (map->collect == 0)
		{
			printf("\nYou Have Won, Congrats!\n");
			ft_exit(map);
		}
		//////
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
}

static int	keyboard_w_s(t_map *map, int movement)
{
	int	i;
	int	j;

	i = map->player_x;
	j = map->player_y;
	if (movement == 13)
	{
		j--;
		if (map->full[j][i] == '1')
			return (0);
		right_move(map, i, j);
		map->full[j + 1][i] = '0';
	}
	else if (movement == 1)
	{
		j++;
		if (map->full[j][i] == '1')
			return (0);
		right_move(map, i, j);
		map->full[j - 1][i] = '0';
	}
	printf("Steps Taken: %i\n", map->moves);
	//ft_print_moves(map->moves);
	//printf("Collectables Left: %i\n", map->collect);
	return (1);
}

static int	keyboard_a_d(t_map *map, int movement)
{
	int	i;
	int	j;

	i = map->player_x;
	j = map->player_y;
	if (movement == 0)
	{
		i--;
		if (map->full[j][i] == '1')
			return (0);
		right_move(map, i, j);
		map->full[j][i - 1] = '0';
	}
	else if (movement == 2)
	{
		i++;
		if (map->full[j][i] == '1')
			return (0);
		right_move(map, i, j);
		map->full[j][i - 1] = '0';
	}
	//ft_print_moves(map->moves);
	printf("Steps Taken: %i\n", map->moves);
	//printf("Collectables Remaining: %i\n", map->collect);
	return (1);
}

int	ft_key(int key, t_map *map)
{
	int	s;

	if (key == 53)
		exit(0);
	if (key == 13)
		s = keyboard_w_s(map, key);
	if (key == 2)
		s = keyboard_a_d(map, key);
	if (key == 0)
		s = keyboard_a_d(map, key);
	if (key == 1)
		s = keyboard_w_s(map, key);
	if (s)
		adding_in_graphics(map);
	return (0);
}
