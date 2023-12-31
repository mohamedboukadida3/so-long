/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:09:35 by mboukadi          #+#    #+#             */
/*   Updated: 2023/08/31 23:10:28 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_copy_map(t_map *map, char *av)
{
	int	i;
	int	j;

	i = open(av, O_RDONLY);
	map->copy_full = malloc ((sizeof(char *) + 1) * map->line);
	j = 0;
	map->copy_full[j] = get_next_line(i);
	while (j < map->line)
	{
		j++;
		map->copy_full[j] = get_next_line(i);
	}
	map->copy_full[j] = 0;
	close (i);
}

void	ft_flood_fill(t_map *map, int x, int y)
{
	if (map->copy_full[x][y] != '1' && map->copy_full[x][y] != 'F')
	{
		map->copy_full[x][y] = 'F';
		ft_flood_fill(map, x - 1, y);
		ft_flood_fill(map, x + 1, y);
		ft_flood_fill(map, x, y - 1);
		ft_flood_fill(map, x, y + 1);
	}
}

void	is_valid_path(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->copy_full[++i])
	{
		j = -1;
		while (map->copy_full[i][++j])
		{
			if (map->copy_full[i][j] == 'P')
			{
				ft_flood_fill(map, i, j);
				j = 0;
			}
		}
	}
}

void	check_after_fill(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->copy_full[++i])
	{
		j = 0;
		while (map->copy_full[i][++j])
		{
			if (map->copy_full[i][j] == 'C' || map->copy_full[i][j] == 'E' )
			{
				ft_printf("invalid path !\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
