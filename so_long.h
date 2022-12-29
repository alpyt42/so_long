/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:37:11 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/29 19:46:56 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

# ifdef __APPLE__
#  include "mlx/mlx.h"
# else
#  include "mlx_linux/mlx.h"
# endif
# include "libft/libft.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17

# define SPRITE_H				64
# define SPRITE_W				64

typedef struct s_map {
	int	obj; // collectibles
	int	start;
	int	ex; // exit
	int	en; // enemies
}	t_map;

typedef struct s_data {
// Data for MLX
	void	*mlx;
	void	*mlx_win;
	void	*img; // put image here
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
// Size of img;
	int		col_img; //count of column
	int		row_img; //count of row
// Size of map
	int		col_map; //count of column
	int		row_map; //count of row
// Map info
	char	**map; // include map, row by row (split with \n)
// Count of steps/collectibles
	int		steps;
// User Position
	int		col_user;
	int		row_user;
// Exit Position
	int		col_ex;
	int		row_ex;
	t_map	arg;
}	t_data;

void	display_error(char *error);
void	map_size(t_data *var, char **argv);
void	load_map(t_data *var, char **argv);
void	print_map(t_data *var);
void	check_map(t_data *var);
void	get_position(t_data *var);
int		key(int key, t_data *var);
void	check_move(t_data *var, int key);
int		free_all(t_data *var, char *msg);

#endif