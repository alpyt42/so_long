/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:37:11 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/29 13:06:02 by ale-cont         ###   ########.fr       */
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

# if defined(__APPLE__) && defined(__MACH__)
#  define LEFT_KEY				123	
#  define RIGHT_KEY				124	
#  define UP_KEY				126
#  define DOWN_KEY				125	
#  define A_KEY					0
#  define S_KEY					1
#  define D_KEY					2
#  define W_KEY					13
#  define ESC 					53

# else
#  define LEFT_KEY				65361
#  define RIGHT_KEY				65363
#  define UP_KEY				65362
#  define DOWN_KEY				65364
#  define A_KEY					97
#  define W_KEY					119
#  define S_KEY					115
#  define D_KEY					100
#  define ESC					65307
# endif

# define SPRITE_H				64
# define SPRITE_W				64

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
	int		obj;
// User Position
	int		col_user;
	int		row_user;
}	t_data;

void	display_error(char *error);
void	map_size(t_data *var, char **argv);
void	load_map(t_data *var, char **argv);
void	print_map(t_data *var);

#endif