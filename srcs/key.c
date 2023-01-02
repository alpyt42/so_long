/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:44:57 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/02 21:48:46 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	winner(t_data *var, char c)
{
	if (c == 'D')
		var->map[var->row_user - 1][var->col_user] = 'x';
	else if (c == 'U')
		var->map[var->row_user + 1][var->col_user] = 'x';
	else if (c == 'L')
		var->map[var->row_user][var->col_user - 1] = 'x';
	else if (c == 'R')
		var->map[var->row_user][var->col_user + 1] = 'x';
	var->map[var->row_user][var->col_user] = '0';
	var->steps++;
	var->arg.win = 1;
}

int	key(int key, t_data *var)
{
	int	init_steps;

	init_steps = var->steps;
	if (key == 53)
		free_all(var, "Game closed\n");
	else
	{
		if (ft_find_char(var, 'l'))
			free_all(var, "LOOOOOOOOSER !");
		else if (var->arg.win == 1)
			free_all(var, "YOU WIN !");
		check_move(var, key);
	}
	if (var->arg.obj == 0 && var->arg.win != 1)
		var->map[var->row_ex][var->col_ex] = 'e';
	if (init_steps != var->steps)
		printf("Steps: %d\n", var->steps);
	print_map(var);
	return (0);
}