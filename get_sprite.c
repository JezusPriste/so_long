/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborgian <dborgian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:42:05 by dborgian          #+#    #+#             */
/*   Updated: 2023/06/13 18:27:01 by dborgian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_background_and_wall(t_vars *vars)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	vars->background = mlx_xpm_file_to_image(vars->mlx,
			"./spites/cementotiziano.xpm", &x, &y);
	if (!vars->background)
		return (0);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "./spites/siepe.xpm", &x, &y);
	if (!vars->wall)
		return (0);
	return (1);
}

int	get_player(t_vars *vars)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	vars->player = mlx_xpm_file_to_image(vars->mlx,
			"./spites/DamIaronman.xpm", &x, &y);
	if (!vars->player)
		return (0);
	vars->jibba = mlx_xpm_file_to_image(vars->mlx,
			"./spites/jibbabella.xpm", &x, &y);
	if (!vars->jibba)
		return (0);
	return (1);
}

int	get_enemies(t_vars *vars)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	vars->police_car = mlx_xpm_file_to_image(vars->mlx,
			"./spites/policecarX64.xpm", &x, &y);
	if (!vars->police_car)
		return (0);
	return (1);
}

int	get_cella_and_logo(t_vars *vars)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	vars->cella = mlx_xpm_file_to_image(vars->mlx,
			"./spites/gabbia.xpm", &x, &y);
	if (!vars->cella)
		return (0);
	vars->logo = mlx_xpm_file_to_image(vars->mlx,
			"./spites/AnyConv.com__exit_dami_00.xpm", &x, &y);
	if (!vars->logo)
		return (0);
	return (1);
}

void	get_sprite(t_vars *vars)
{
	int	i;

	i = 0;
	i += get_background_and_wall(vars);
	i += get_player(vars);
	i += get_cella_and_logo(vars);
	i += get_enemies(vars);
	if (i != 4)
	{
		write(1, "errore controlla i sprite\n", 27);
		exit(1);
	}
}
