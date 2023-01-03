/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:59:30 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/03 19:20:22 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int		check_move_bt(char **matrix, int x, int y)
{
	int	x_len;
	int	y_len;

	x_len = ft_strlen(matrix[0]);
	y_len = ft_arrlen(matrix);
	if ((x >= 0 && x < x_len && y >= 0 && y < y_len && matrix[y][x] != '1'))
		return (1);
	return (0);
}

static int	find_path(char **matrix, int x, int y, int coins)
{
	static int	exits;
	static int	c;

	if (matrix[y][x] == 'E')
		exits++;
	if (matrix[y][x] == 'C')
		c++;
	matrix[y][x] = '1';
	if (check_move_bt(matrix, x - 1, y))
		find_path(matrix, x - 1, y, coins);
	if (check_move_bt(matrix, x, y + 1))
		find_path(matrix, x, y + 1, coins);
	if (check_move_bt(matrix, x + 1, y))
		find_path(matrix, x + 1, y, coins);
	if (check_move_bt(matrix, x, y - 1))
		find_path(matrix, x, y - 1, coins);
	if (exits > 0 && c == coins)
		return (1);
	return (0);
}

int	backtracking(t_data *var)
{
	char	**str;
	int		x;
	int		y;

	x = var->col_user;
	y = var->row_user;
	str = 0;
	str = ft_arrdup(var->map);
	if (find_path(str, x, y, var->arg.obj) == 0)
		printf("STOP");
	ft_free_arr(str);
	return (1);
}