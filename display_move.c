/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborgian <dborgian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:03:18 by dborgian          #+#    #+#             */
/*   Updated: 2023/03/31 15:40:01 by dborgian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	info_display(t_vars *vars)
{
	char	*s1;

	s1 = ft_itoa(vars->move_count);
	mlx_string_put(vars->mlx, vars->win, 150, vars->height + 22,
		0xff0000, "moves: ");
	mlx_string_put(vars->mlx, vars->win, 250, vars->height + 22,
		0xff0000, s1);
	free(s1);
}

void	terminal_display(t_vars *vars)
{
	char	*str;

	str = ft_itoa(vars->move_count);
	ft_putstr("Moves: ");
	ft_putstr(str);
	ft_putstr("\n");
	free(str);
}
