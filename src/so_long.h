/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:36:05 by mboukadi          #+#    #+#             */
/*   Updated: 2023/07/05 20:16:22 by mboukadi         ###   ########.fr       */
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

	void		*mlx_ptr;
	void		*win_ptr;

	void		*player;
	void		*floor;
	void		*wall;
	void		*items;
	void		*exit;
}		t_map;

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

void	put_player(t_map *map, int x, int y);
void	put_items(t_map *map, int x, int y);
void	put_images_in_game(t_map *map);
void	adding_in_graphics(t_map *map);
void	ft_init_game(t_map *map);

/*.................................MAIN.......................................*/

int		main(int ac, char **av);

#endif