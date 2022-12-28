/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:32:45 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/28 22:26:29 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_map(t_data *var)
{
	var->map = (char **)malloc(sizeof(char *) * (var->y_map + 1));
	if (!var->map)
		display_error(strerror(errno));
	var->map = ft_split(var->map_buf, '\n');
}

void	check_args(int argc, char **argv)
{
	if (argc < 2)
		display_error("\033[1;31mPlease provide a map\033[0m\n\
Ex: ./so_long maps/map.ber\n");
	if (argc > 2)
		display_error("\033[1;31mToo many arguments.\n\033[0m\
Ex: ./so_long maps/map.ber\n");
	if (ft_strstr(argv[1], ".ber") == NULL)
		display_error("\033[1;33mInvalid map extension. Use .ber for maps\033[0m\n");
}

int	main(int argc, char **argv)
{
	// int		size = 64;
	// void	*imgtow;
	t_data	var;

	check_args(argc, argv);
	var.mlx = mlx_init();
	map_size(&var, argv);
	init_map(&var);
	// var.mlx_win = mlx_new_window(var.mlx, 640, 120, "So long");
	// imgtow = mlx_xpm_file_to_image(var.mlx, "./sprite/ball.xpm", &size, &size);
	// mlx_put_image_to_window(var.mlx, var.mlx_win, imgtow, 64*2, 0);
	// printf("%s", var.map[0]);
	// printf("%s", var.map_buf);
	// mlx_loop(var.mlx);
}