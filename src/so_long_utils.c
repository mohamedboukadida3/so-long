/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:20:32 by mboukadi          #+#    #+#             */
/*   Updated: 2023/07/06 14:46:26 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_line_count(t_map	*map, char *av)
{
	int		i;
	char	*map1;

	i = open(av, O_DIRECTORY);
	if (i > 0)
	{
		ft_printf("error, %s is directory !\n", av);
		exit(EXIT_FAILURE);
	}
	i = open(av, O_RDONLY);
	map1 = get_next_line(i);
	if (!map1)
	{
		ft_printf("error , the map is empty !\n");
		exit(EXIT_FAILURE);
	}
	map->line = 0;
	map->count_caracter = ft_strlen(map1) - 1;
	while (map1)
	{
		free(map1);
		map->line++;
		map1 = get_next_line(i);
	}
	close(i);
}

void	ft_init_map(t_map *map, char *av)
{
	int	i;
	int	j;

	i = open(av, O_RDONLY);
	map->full = malloc ((sizeof(char *) + 1) * map->line);
	j = 0;
	map->full[j] = get_next_line(i);
	while (j < map->line)
	{
		j++;
		map->full[j] = get_next_line(i);
	}
	map->full[j] = 0;
	close (i);
}

void	ft_valid_caracter(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->line)
	{
		j = -1;
		while (++j < map->count_caracter)
		{
			if (map->full[i][j] != '1' && map->full[i][j] != '0'
			&& map->full[i][j] != 'C' && map->full[i][j] != 'E'
			&& map->full[i][j] != 'P')
			{
				ft_printf("please check map characters !\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}

void	ft_valid_number_element(t_map *map, int c, int e, int p)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->line)
	{
		j = -1;
		while (++j < map->count_caracter)
		{
			if (map->full[i][j] == 'C')
				c++;
			if (map->full[i][j] == 'E')
				e++;
			if (map->full[i][j] == 'P')
				p++;
		}
	}
	if ((e != 1) || (c == 0) || (p != 1))
	{
		ft_printf("please check number of elements !\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_is_closed(t_map *map)
{
	int	i;
	int	j;
	int	size;

	size = ft_strlen(map->full[0]) - 1;
	i = -1;
	while (++i < size)
	{
		if (map->full[0][i] != '1' || map->full[map->line - 1][i] != '1')
		{
			ft_printf("map is not closed!\n");
			exit(EXIT_FAILURE);
		}
	}
	j = -1;
	while (map->full[++j])
	{
		if (map->full[j][0] != '1' || map->full[j][size - 1] != '1')
		{
			ft_printf("map is not closed!\n");
			exit(EXIT_FAILURE);
		}
	}
}
