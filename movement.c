/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborgian <dborgian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:27:53 by dborgian          #+#    #+#             */
/*   Updated: 2023/03/31 15:36:40 by dborgian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

int	move(int keycode, t_vars *vars)
{
	if (vars->randomize == YES)
	{
		randomize_wasd(vars);
		randomize_arrows(vars);
		vars->randomize = NO;
	}
	if (vars->flagdeath == 0)
	{
		if (keycode == vars->w_code || keycode == vars->up_code)
			move_w(vars);
		else if (keycode == vars->s_code || keycode == vars->down_code)
			move_s(vars);
		else if (keycode == vars->a_code || keycode == vars->left_code)
			move_a(vars);
		else if (keycode == vars->d_code || keycode == vars->right_code)
			move_d(vars);
		terminal_display(vars);
	}
	return (0);
}

int	move_w(t_vars *vars)
{
	if (vars->map[vars->player_y - 1][vars->player_x] == '1')
		return (0);
	if (vars->map[vars->player_y - 1][vars->player_x] == 'C')
	{
		vars->randomize = YES;
		vars->jibba_count += 1;
	}
	if (vars->map[vars->player_y - 1][vars->player_x] == 'X')
		put_image(vars);
	else if (vars->map[vars->player_y - 1][vars->player_x] == 'E')
	{
		if (vars->jibba_count == vars->total_collectable)
			end_game(vars);
	}
	else
	{
		vars->map[vars->player_y - 1][vars->player_x] = 'P';
		vars->map[vars->player_y][vars->player_x] = '0';
		vars->player_y -= 1;
		vars->move_count++;
		mlx_clear_window(vars->mlx, vars->win);
		draw_map(vars);
	}
	return (0);
}

int	move_s(t_vars *vars)
{
	if (vars->map[vars->player_y + 1][vars->player_x] == '1')
		return (0);
	if (vars->map[vars->player_y + 1][vars->player_x] == 'C')
	{
		vars->randomize = YES;
		vars->jibba_count += 1;
	}
	if (vars->map[vars->player_y + 1][vars->player_x] == 'X')
		put_image(vars);
	else if (vars->map[vars->player_y + 1][vars->player_x] == 'E')
	{
		if (vars->jibba_count == vars->total_collectable)
			end_game(vars);
	}
	else
	{
		vars->map[vars->player_y + 1][vars->player_x] = 'P';
		vars->map[vars->player_y][vars->player_x] = '0';
		vars->player_y += 1;
		vars->move_count++;
		mlx_clear_window(vars->mlx, vars->win);
		draw_map(vars);
	}
	return (0);
}

int	move_a(t_vars *vars)
{
	if (vars->map[vars->player_y][vars->player_x - 1] == '1')
		return (0);
	if (vars->map[vars->player_y][vars->player_x - 1] == 'C')
	{
		vars->randomize = YES;
		vars->jibba_count += 1;
	}
	if (vars->map[vars->player_y][vars->player_x - 1] == 'X')
		put_image(vars);
	else if (vars->map[vars->player_y][vars->player_x - 1] == 'E')
	{
		if (vars->jibba_count == vars->total_collectable)
			end_game(vars);
	}
	else
	{
		vars->map[vars->player_y][vars->player_x - 1] = 'P';
		vars->map[vars->player_y][vars->player_x] = '0';
		vars->player_x--;
		vars->move_count++;
		mlx_clear_window(vars->mlx, vars->win);
		draw_map(vars);
	}
	return (0);
}

int	move_d(t_vars *vars)
{
	if (vars->map[vars->player_y][vars->player_x + 1] == '1')
		return (0);
	if (vars->map[vars->player_y][vars->player_x + 1] == 'C')
	{
		vars->randomize = YES;
		vars->jibba_count += 1;
	}
	if (vars->map[vars->player_y][vars->player_x + 1] == 'X')
		put_image(vars);
	else if (vars->map[vars->player_y][vars->player_x + 1] == 'E')
	{
		if (vars->jibba_count == vars->total_collectable)
			end_game(vars);
	}
	else
	{
		vars->map[vars->player_y][vars->player_x + 1] = 'P';
		vars->map[vars->player_y][vars->player_x] = '0';
		vars->player_x += 1;
		vars->move_count++;
		mlx_clear_window(vars->mlx, vars->win);
		draw_map(vars);
	}
	return (0);
}
