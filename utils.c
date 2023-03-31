/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborgian <dborgian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:39:59 by dborgian          #+#    #+#             */
/*   Updated: 2023/03/31 16:13:11 by dborgian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>

void	free_map(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		free(vars->map[i]);
		i++;
	}
	free (vars->map);
}

int	randomize(int rand_nbrs[4])
{
	int	i;
	int	r;
	int	check;

	check = NOT_OK;
	while (check == NOT_OK)
	{
		r = rand() % 4;
		i = 0;
		while (i < 4)
		{
			if (rand_nbrs[i] == r)
				break ;
			i++;
		}
		if (i == 4)
		{
			i = 0;
			while (rand_nbrs[i] != -1)
				i++;
			rand_nbrs[i] = r;
			check = OK;
		}
	}
	return (r);
}

void	randomize_wasd(t_vars *vars)
{
	const int	keys[] = {0, 1, 2, 13};
	int			rand_nbrs[4];
	int			i;

	i = 0;
	while (i < 4)
		rand_nbrs[i++] = -1;
	vars->w_code = keys[randomize(rand_nbrs)];
	vars->a_code = keys[randomize(rand_nbrs)];
	vars->s_code = keys[randomize(rand_nbrs)];
	vars->d_code = keys[randomize(rand_nbrs)];
}

void	randomize_arrows(t_vars *vars)
{
	const int	keys[] = {123, 124, 125, 126};
	int			rand_nbrs[4];
	int			i;

	i = 0;
	while (i < 4)
		rand_nbrs[i++] = -1;
	vars->up_code = keys[randomize(rand_nbrs)];
	vars->down_code = keys[randomize(rand_nbrs)];
	vars->left_code = keys[randomize(rand_nbrs)];
	vars->right_code = keys[randomize(rand_nbrs)];
}
