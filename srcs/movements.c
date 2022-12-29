/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:49:17 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/29 20:19:18 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	up(t_data *var)
{
	if (var->map[var->row_user + 1][var->col_user] == 'U')
	{
		var->map[var->row_user + 1][var->col_user] = 'l';
		var->map[var->row_user][var->col_user] = '0';
		var->steps++;
		var->row_user++;
	}
	else if (var->map[var->row_user + 1][var->col_user] == 'C')
	{
		var->map[var->row_user + 1][var->col_user] = 'P';
		var->map[var->row_user][var->col_user] = '0';
		var->steps++;
		var->arg.obj--;
		var->row_user++;
	}
	else if (var->map[var->row_user + 1][var->col_user] == '0')
	{
		var->map[var->row_user + 1][var->col_user] = 'P';
		var->map[var->row_user][var->col_user] = '0';
		var->steps++;
		var->row_user++;
	}
}

void	down(t_data *var)
{
	if (var->map[var->row_user - 1][var->col_user] == 'U')
	{
		var->map[var->row_user - 1][var->col_user] = 'l';
		var->map[var->row_user][var->col_user] = '0';
		var->steps++;
		var->row_user--;
	}
	else if (var->map[var->row_user - 1][var->col_user] == 'C')
	{
		var->map[var->row_user - 1][var->col_user] = 'P';
		var->map[var->row_user][var->col_user] = '0';
		var->steps++;
		var->arg.obj--;
		var->row_user--;
	}
	else if (var->map[var->row_user - 1][var->col_user] == '0')
	{
		var->map[var->row_user - 1][var->col_user] = 'P';
		var->map[var->row_user][var->col_user] = '0';
		var->steps++;
		var->row_user--;
	}
}

void	right(t_data *var)
{
	if (var->map[var->row_user][var->col_user + 1] == 'U')
	{
		var->map[var->row_user][var->col_user + 1] = 'l';
		var->map[var->row_user][var->col_user] = '0';
		var->steps++;
		var->col_user++;
	}
	else if (var->map[var->row_user][var->col_user + 1] == 'C')
	{
		var->map[var->row_user][var->col_user + 1] = 'P';
		var->map[var->row_user][var->col_user] = '0';
		var->steps++;
		var->arg.obj--;
		var->col_user++;
	}
	else if (var->map[var->row_user][var->col_user + 1] == '0')
	{
		var->map[var->row_user][var->col_user + 1] = 'P';
		var->map[var->row_user][var->col_user] = '0';
		var->steps++;
		var->col_user++;
	}
}

void	left(t_data *var)
{
	if (var->map[var->row_user][var->col_user - 1] == 'U')
	{
		var->map[var->row_user][var->col_user - 1] = 'l';
		var->map[var->row_user][var->col_user] = '0';
		var->steps++;
		var->col_user--;
	}
	else if (var->map[var->row_user][var->col_user - 1] == 'C')
	{
		var->map[var->row_user][var->col_user - 1] = 'P';
		var->map[var->row_user][var->col_user] = '0';
		var->steps++;
		var->arg.obj--;
		var->col_user--;
	}
	else if (var->map[var->row_user][var->col_user - 1] == '0')
	{
		var->map[var->row_user][var->col_user - 1] = 'P';
		var->map[var->row_user][var->col_user] = '0';
		var->steps++;
		var->col_user--;
	}
}

void	check_move(t_data *var, int key)
{
	if (key == 1 || key == 115)
	{
		if (var->map[var->row_user + 1 ][var->col_user] == 'e')
			free_all(var, "Good Job !");
		up(var);
	}
	if (key == 13 || key == 119)
	{
		if (var->map[var->row_user - 1][var->col_user] == 'e')
			free_all(var, "Good Job !");
		down(var);
	}
	if (key == 0 || key == 97)
	{
		if (var->map[var->row_user][var->col_user - 1] == 'e')
			free_all(var, "Good Job !");
		left(var);
	}
	if (key == 2 || key == 100)
	{
		if (var->map[var->row_user][var->col_user + 1] == 'e')
			free_all(var, "Good Job !");
		right(var);
	}
}