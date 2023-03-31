/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborgian <dborgian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:50:15 by dborgian          #+#    #+#             */
/*   Updated: 2023/03/31 14:59:04 by dborgian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_edges(t_vars *vars)
{
	int	y;

	y = 0;
	while (vars->map[0][y] && vars->map[vars->i - 1][y])
	{
		if (vars->map[0][y] != '1' || vars->map[vars->i][y] != '1')
		{
			write(1, "Error raw\n", 10);
			return (1);
		}
		y++;
	}
	return (0);
}

int	check_middle(t_vars	*vars)
{
	int	i;
	int	c;

	i = 0;
	c = ft_strlen(vars->map[0]) - 1;
	while (i < vars->i)
	{
		if ((vars->map[i][0] != '1') ||
			(vars->map[i][c]) != '1')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	checking_reta(t_vars *vars)
{
	int	x;
	int	ret;
	int	max;

	x = 1;
	max = ft_strlen (vars->map[0]);
	while (vars->map[x])
	{
		ret = ft_strlen(vars->map[x]);
		if (ret != max)
			return (1);
		x++;
	}
	if (max == x)
		return (1);
	return (0);
}

int	checking_elements(t_vars *vars)
{
	int	i;
	int	player;
	int	jibba;
	int	exit;

	i = 0;
	player = 0;
	jibba = 0;
	exit = 0;
	while (vars->s1[i])
	{
		if (vars->s1[i] == 'P')
			player += 1;
		else if (vars->s1[i] == 'C')
			jibba += 1;
		else if (vars->s1[i] == 'E')
			exit += 1;
		i++;
	}
	vars->total_collectable = jibba;
	if (player != 1 || exit != 1 || jibba < 1)
		return (1);
	return (0);
}

int	ft_control(t_vars *vars)
{
	if (!vars->map)
		return (1);
	if (check_edges(vars) == 1)
		return (1);
	if (checking_reta(vars) == 1)
		return (1);
	if (check_middle(vars) == 1)
		return (1);
	if (checking_elements(vars) == 1)
		return (1);
	return (0);
}
