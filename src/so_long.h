/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:36:05 by mboukadi          #+#    #+#             */
/*   Updated: 2023/07/04 19:40:51 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_map
{
	char		**full;
	char		**copy_full;
	int			line;
	int			count_caracter;
}		t_map;

typedef struct s_image
{
	char	*image_path;
	void	*image_ptr;
	int		height_image;
	int		lenght_image;
}		t_image;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_image	wall;
	t_image	player;
	t_image	items;
	t_image	floor;
	t_image	exit;
}		t_game;

/*.................................PARSING....................................*/

int		check_arg(int argc, char **argv);
void	ft_line_count(t_map *map, char *av);
void	ft_init_map(t_map *map, char *av);
void	ft_valid_caracter(t_map *map);
void	ft_valid_number_element(t_map *map, int c, int e, int p);
void	ft_is_closed(t_map *map);
void	ft_is_rectangle(t_map *map);
void	ft_copy_map(t_map *map, char *av);
void	ft_flood_fill(t_map *map, int x, int y);
void	is_valid_path(t_map *map);
void	check_after_fill(t_map *map);
/*.................................MLX........................................*/

//void	set_image(t_game *game);
/*.................................MAIN.......................................*/

int		main(int ac, char **av);

#endif