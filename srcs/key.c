/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:44:57 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/29 20:24:53 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_loser(t_data *var)
{
	int	row;
	int	col;

	row = -1;
	while (++row < var->row_map)
	{
		col = -1;
		while (++col < var->col_map)
			if (var->map[row][col] == 'l')
				free_all(var, "LOOOOOOOOSER !");
	}
}

int	key(int key, t_data *var)
{
	int	init_steps;

	init_steps = var->steps;
	if (key == 53)
		free_all(var, "Game closed\n");
	else
	{
		check_loser(var);
		check_move(var, key);
	}
	if (init_steps != var->steps)
		printf("Steps: %d\n", var->steps);
	if (var->arg.obj == 0)
		var->map[var->row_ex][var->col_ex] = 'e';
	// mlx_string_put(var->mlx, var->mlx_win, 10, 10, 0x000000FF, "steps");
	print_map(var);
	return (0);
}