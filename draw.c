/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborgian <dborgian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:08:58 by dborgian          #+#    #+#             */
/*   Updated: 2023/03/29 19:36:12 by dborgian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_vars *vars, int x, int y)
{
	vars->player_y = y;
	vars->player_x = x;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->background,
		x * 64, y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player,
		x * 64, y * 64);
	if (vars->flagdeath == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->cella,
			x * 64, y * 64);
}

void	draw_wall(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->background,
		x * 64, y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->wall,
		x * 64, y * 64);
}

void	draw_police_car(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->background,
		x * 64, y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->police_car,
		x * 64, y * 64);
}

void	draw_map(t_vars *vars)
{
	int	x;
	int	y;

	y = -1;
	while (vars->map[++y] != '\0')
	{
		x = -1;
		while (vars->map[y][++x])
		{
			draw_object(vars, x, y);
		}
		info_display(vars);
	}
	if (vars->winningflag == 1)
		end_game(vars);
}

void	draw_object(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == 'P')
		draw_player(vars, x, y);
	else if (vars->map[y][x] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->background,
			x * 64, y * 64);
	else if (vars->map[y][x] == '1')
		draw_wall(vars, x, y);
	else if (vars->map[y][x] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->jibba,
			x * 64, y * 64);
	else if (vars->map[y][x] == 'X')
		draw_police_car(vars, x, y);
	else if (vars->map[y][x] == 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->background,
			x * 64, y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->logo,
			x * 64, y * 64);
	}
}
