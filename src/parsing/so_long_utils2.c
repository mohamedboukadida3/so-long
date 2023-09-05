/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:59:44 by mboukadi          #+#    #+#             */
/*   Updated: 2023/07/09 02:21:21 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_arg(int argc, char **argv)
{
	int	fd;
	int	size;

	if (argc != 2)
	{
		ft_printf("invalid number of arguments !\n");
		return (0);
	}
	size = ft_strlen(argv[1]);
	if (argv[1][size - 4] != '.' || argv[1][size - 3] != 'b'
		|| argv[1][size - 2] != 'e' || argv[1][size - 1] != 'r')
	{
		ft_printf("Invalid file type, use .ber\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("file not found !\n");
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

size_t	ft_strlen_modif(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
	{
		i++;
	}
	return (i);
}

void	ft_is_rectangle(t_map *map)
{
	int		i;
	size_t	s;

	s = ft_strlen_modif(map->full[0]);
	i = 0;
	while (map->full[i])
	{
		if (ft_strlen_modif(map->full[i]) != s)
		{
			ft_printf("map is not rectangular !\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	ft_init_game(t_map *map)
{
	map->line = 0;
	map->count_caracter = 0;
	map->collect = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->moves = 0;
	map->mlx_ptr = 0;
	map->win_ptr = 0;
	map->player = 0;
	map->floor = 0;
	map->wall = 0;
	map->items = 0;
	map->exit = 0;
}
