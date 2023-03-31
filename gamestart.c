/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborgian <dborgian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:16:53 by dborgian          #+#    #+#             */
/*   Updated: 2023/03/31 16:31:59 by dborgian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vars	init_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->player_x = 0;
	vars->player_y = 0;
	vars->player_loop = 0;
	vars->policestance_loop = 0;
	vars->enemy_stage = 0;
	vars->randomize = NO;
	vars->w_code = 13;
	vars->a_code = 0;
	vars->s_code = 1;
	vars->d_code = 2;
	vars->up_code = 126;
	vars->down_code = 125;
	vars->left_code = 123;
	vars->right_code = 124;
	vars->flagdeath = 0;
	vars->police_loop = 0;
	vars->winningflag = 0;
	vars->jibba_count = 0;
	vars->total_collectable = 0;
	return (*vars);
}

t_vars	read_file(t_vars *vars, char *path)
{
	vars->s1 = malloc(sizeof(char) * 10000000);
	vars->fd = open(path, O_RDONLY);
	if (vars->fd == -1)
		exit(1);
	read(vars->fd, vars->s1, 10000000);
	vars->map = ft_split(vars->s1, '\n');
	vars->i = ft_count(vars->s1);
	vars->height = vars->i * 64;
	vars->width = ft_strlen(vars->map[0]) * 64;
	vars->win = mlx_new_window(vars->mlx, vars->width,
			vars->height + 64, "so_long");
	return (*vars);
}

t_vars	start(t_vars *vars, char *path)
{
	init_vars(vars);
	read_file(vars, path);
	return (*vars);
}
