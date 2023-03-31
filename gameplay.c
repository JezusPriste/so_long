/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborgian <dborgian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:41:11 by dborgian          #+#    #+#             */
/*   Updated: 2023/03/31 15:41:22 by dborgian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win(t_vars *vars)
{
	vars->flag = 0;
	mlx_clear_window(vars->mlx, vars->win);
	mlx_string_put(vars->mlx, vars->win, vars->width
		/ 2, vars->height / 2, 0x00FF0000, "congratulation!");
}

int	animation(t_vars *vars)
{
	if (vars->winningflag == 0)
	{
		while (vars->police_loop < 10000)
			vars->police_loop++;
		if (vars->police_loop == 10000)
		{
			vars->policestance_loop++;
			change_image(vars);
			vars->police_loop = 0;
		}
	}
	return (0);
}

void	change_image(t_vars *vars)
{
	int	x;
	int	y;

	if (vars->policestance_loop == 5)
		vars->police_car = mlx_xpm_file_to_image
			(vars->mlx, "./spites/police.xpm", &x, &y);
	if (vars->policestance_loop == 15)
		vars->police_car = mlx_xpm_file_to_image(vars->mlx,
				"./spites/police1.xpm", &x, &y);
	if (vars->policestance_loop == 30)
	{
		vars->police_car = mlx_xpm_file_to_image(vars->mlx,
				"./spites/police2.xpm", &x, &y);
		vars->policestance_loop = 0;
	}
	draw_map(vars);
}

void	put_image(t_vars *vars)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->cella, x * 64, y * 64);
	vars->flagdeath = 1;
}

void	end_game(t_vars *vars)
{
	vars->winningflag = 1;
	mlx_clear_window(vars->mlx, vars->win);
	mlx_string_put(vars->mlx, vars->win, 100, 100, 0x00FFFFFF,
		"Bravo, sei riuscito a portare le jibbe in salvo");
}
