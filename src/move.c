/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:56:27 by mboukadi          #+#    #+#             */
/*   Updated: 2023/07/07 17:24:58 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_moves(t_map *map)
{
	ft_putstr_fd("You made ", 1);
	ft_putnbr_fd(map->moves, 1);
	if (map->moves == 1)
		ft_putstr_fd(" move\r", 1);
	else
		ft_putstr_fd(" moves\r", 1);
}
