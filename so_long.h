/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborgian <dborgian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:51:17 by dborgian          #+#    #+#             */
/*   Updated: 2023/04/03 13:24:03 by dborgian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE	10
# define YES			1
# define NO				0
# define OK				1
# define NOT_OK			0

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <mlx.h>
# include "libft/libft.h"
# include <time.h>

typedef struct	s_vars{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		fd;
	int		enemy_stage;
	int		enemy_loop;
	void	*player;
	int		player_x;
	int		player_y;
	int		player_loop;
	int		x;
	int		y;
	char	**map;
	void	*background;
	char	*pd;
	char	*s1;
	int		i;
	void	*wall;
	void	*jibba;
	void	*death;
	int		flag;
	int		prev_player_x;
	int		prev_player_y;
	void	*police_car;
	int		jibba_count;
	int		total_collectable;
	int		keycode;
	int		last_direction;
	int		randomize;
	int		w_code;
	int		a_code;
	int		s_code;
	int		d_code;
	int		up_code;
	int		down_code;
	int		left_code;
	int		right_code;
	void	*cella;
	int		flagdeath;
	int		police_loop;
	int		policestance_loop;
	void	*police1;
	void	*police2;
	void	*police3;
	void	*logo;
	int		winningflag;
	int		move_count;
}				t_vars;

//utils
int		xclose(t_vars *vars);
int		ft_count(char *s1);
int		key_close(int keycode, t_vars *vars);
int		key_pressed(int keycode, t_vars *vars);
void	print_image(t_vars vars, void *i, int x, int y);
void	change_image(t_vars *vars);
void	put_image(t_vars *vars);
void	info_display(t_vars *vars);
void	terminal_display(t_vars *vars);
void	print_matrix(t_vars *vars);
void	free_map(t_vars *vars);

//game
int		main(int argc, char **argv);
void	death(t_vars *vars);
void	win(t_vars *vars);
void	end_game(t_vars *vars);
int		animation(t_vars *vars);

//gamestart
t_vars	init_vars(t_vars *vars);
t_vars	read_file(t_vars *vars, char *path);
t_vars	start(t_vars *vars, char *argv);
t_vars	create_window(t_vars *vars);

//get_sprite
int		get_background_and_wall(t_vars *vars);
int		get_player(t_vars *vars);
int		get_enemies(t_vars *vars);
int		get_cella_and_logo(t_vars *vars);
void	get_sprite(t_vars *vars);

//draw
void	draw_player(t_vars *vars, int x, int y);
void	draw_background(t_vars *vars, int x, int y);
void	draw_wall(t_vars *vars, int x, int y);
void	draw_collectible(t_vars *vars, int x, int y);
void	draw_police_car(t_vars *vars, int x, int y);
void	draw_logo(t_vars *vars, int x, int y);
void	draw_end_game(t_vars *vars);
void	draw_map(t_vars *vars);
void	draw_object(t_vars *vars, int x, int y);

//control
int		control_format(char *argv);
int		ft_control(t_vars *vars);
int 	checking_stucture(t_vars *vars);
int 	checking_middles(t_vars *vars);
int 	checking_edges(t_vars *vars);
int 	checking_elements(t_vars *vars);

//randomize
int 	random_movement();
void 	randomize_wasd(t_vars *vars);
void 	randomize_arrows(t_vars *vars);

//movement
int 	move(int keycode, t_vars *vars);
int    	move_w(t_vars *vars);
int		move_s(t_vars *vars);
int		move_d(t_vars *vars);
int		move_a(t_vars *vars);
# endif