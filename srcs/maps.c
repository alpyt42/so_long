/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:54:43 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/29 17:01:49 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_size(t_data *var, char **argv)
{
	int		fd;
	char	*res_gnl;

	var->col_map = 0;
	var->row_map = 0;
	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
		display_error(strerror(errno));
	res_gnl = gnl(fd);
	while(res_gnl)
	{
		var->col_map = ft_strlen(res_gnl);
		var->row_map++;
		res_gnl = gnl(fd);
	}
	free(res_gnl);
	close(fd);
}

static void	put_img(t_data *var, int row, int col)
{
	if (var->map[row][col] == '0')
		var->img = mlx_xpm_file_to_image(var->mlx, "./sprite/grass.xpm", 
			&var->col_img, &var->row_img);
	else if (var->map[row][col] == '1')
		var->img = mlx_xpm_file_to_image(var->mlx, "./sprite/ground.xpm", 
			&var->col_img, &var->row_img);
	else if (var->map[row][col] == 'C')
		var->img = mlx_xpm_file_to_image(var->mlx, "./sprite/ball.xpm", 
			&var->col_img, &var->row_img);
	else if (var->map[row][col] == 'E')
		var->img = mlx_xpm_file_to_image(var->mlx, "./sprite/coupe_b.xpm", 
			&var->col_img, &var->row_img);
	else if (var->map[row][col] == 'e')
		var->img = mlx_xpm_file_to_image(var->mlx, "./sprite/coupe.xpm", 
			&var->col_img, &var->row_img);
	else if (var->map[row][col] == 'P')
		var->img = mlx_xpm_file_to_image(var->mlx, "./sprite/zizou.xpm", 
			&var->col_img, &var->row_img);
	else if (var->map[row][col] == 'l')
		var->img = mlx_xpm_file_to_image(var->mlx, "./sprite/zvm.xpm", 
			&var->col_img, &var->row_img);
	else if (var->map[row][col] == 'U')
		var->img = mlx_xpm_file_to_image(var->mlx, "./sprite/mate.xpm", 
			&var->col_img, &var->row_img);
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img, SPRITE_W * col, SPRITE_H * row);
	mlx_destroy_image(var->mlx, var->img);
}

void	load_map(t_data *var, char **argv)
{
	int		row;
	int		fd;

	row = -1;
	var->map = (char **)malloc(sizeof(char *) * (var->row_map + 1));
	if (!var->map)
		display_error(strerror(errno));
	var->map[var->row_map] = NULL;
	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
		display_error(strerror(errno));
	while (++row < var->row_map)
		var->map[row] = gnl(fd);
	close(fd);
}

void	print_map(t_data *var)
{
	int	row;
	int	col;

	row = -1;
	while (++row < var->row_map)
	{
		col = -1;
		while (++col < var->col_map)
			put_img(var, row, col);
	}
}