/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborgian <dborgian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:34:36 by dborgian          #+#    #+#             */
/*   Updated: 2023/03/31 15:12:57 by dborgian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibft/libft.h"
#include "so_long.h"

int	xclose(t_vars *vars)
{
	free_map(vars);
	exit(0);
	return (0);
}

int	key_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else
		move(keycode, vars);
	return (0);
}

int	ft_count(char *s1)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s1[i])
	{
		if (s1[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

int	control_format(char *argv)
{
	int	i;

	i = 0;
	if (!argv)
		return (0);
	while (argv[i] != '.')
		i++;
	if (argv[i + 1] != 'b' && argv[i + 2] != 'e'
		&& argv[i + 3] != 'r' && argv[i + 4] != '\0')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 2)
	{
		start(&vars, argv[1]);
		if (ft_control(&vars) == 1)
		{
			write(1, "controlli non okay\n", 20);
			return (1);
		}
		get_sprite(&vars);
		draw_map(&vars);
		mlx_loop_hook(vars.mlx, animation, &vars);
		mlx_hook(vars.win, 2, 1L << 0, key_close, &vars);
		mlx_hook(vars.win, 17, 0, xclose, &vars);
		mlx_loop(vars.mlx);
	}
	else
	{
		write(1, "error", 5);
		exit(1);
	}
	free_map(&vars);
}
