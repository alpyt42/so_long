/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:49:17 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/29 17:30:09 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	up(t_data *var)
{
	if (var->map[var->row_user + 1][var->col_user] == 'U')
	{
		var->steps++;
		var->row_user++;
		var->map[var->row_user + 1][var->col_user] = 'l';
		var->map[var->row_user + 1][var->col_user] = '0';
	}
	if (var->map[var->row_user + 1][var->col_user] == 'C')
	{
		var->steps++;
		var->arg.obj--;
		var->row_user++;
		var->map[var->row_user + 1][var->col_user] = 'P';
		var->map[var->row_user + 1][var->col_user] = '0';
	}
	if (var->map[var->row_user + 1][var->col_user] == '0')
	{
		var->steps++;
		var->row_user++;
		var->map[var->row_user + 1][var->col_user] = 'P';
		var->map[var->row_user + 1][var->col_user] = '0';
	}
}

void	down(t_data *var)
{
	if (var->map[var->row_user - 1][var->col_user] == 'U')
	{
		var->steps++;
		var->row_user--;
		var->map[var->row_user - 1][var->col_user] = 'l';
		var->map[var->row_user - 1][var->col_user] = '0';
	}
	if (var->map[var->row_user - 1][var->col_user] == 'C')
	{
		var->steps++;
		var->arg.obj--;
		var->row_user--;
		var->map[var->row_user - 1][var->col_user] = 'P';
		var->map[var->row_user - 1][var->col_user] = '0';
	}
	if (var->map[var->row_user - 1][var->col_user] == '0')
	{
		var->steps++;
		var->row_user--;
		var->map[var->row_user - 1][var->col_user] = 'P';
		var->map[var->row_user - 1][var->col_user] = '0';
	}
}

void	right(t_data *var)
{
	if (var->map[var->row_user][var->col_user + 1] == 'U')
	{
		var->steps++;
		var->col_user++;
		var->map[var->row_user][var->col_user + 1] = 'l';
		var->map[var->row_user][var->col_user + 1] = '0';
	}
	if (var->map[var->row_user][var->col_user + 1] == 'C')
	{
		var->steps++;
		var->arg.obj--;
		var->col_user++;
		var->map[var->row_user][var->col_user + 1] = 'P';
		var->map[var->row_user][var->col_user + 1] = '0';
	}
	if (var->map[var->row_user][var->col_user + 1] == '0')
	{
		var->steps++;
		var->col_user++;
		var->map[var->row_user][var->col_user + 1] = 'P';
		var->map[var->row_user][var->col_user + 1] = '0';
	}
}

void	left(t_data *var)
{
	if (var->map[var->row_user][var->col_user - 1] == 'U')
	{
		var->steps++;
		var->col_user--;
		var->map[var->row_user][var->col_user - 1] = 'l';
		var->map[var->row_user][var->col_user - 1] = '0';
	}
	if (var->map[var->row_user][var->col_user - 1] == 'C')
	{
		var->steps++;
		var->arg.obj--;
		var->col_user--;
		var->map[var->row_user][var->col_user - 1] = 'P';
		var->map[var->row_user][var->col_user - 1] = '0';
	}
	if (var->map[var->row_user][var->col_user - 1] == '0')
	{
		var->steps++;
		var->col_user--;
		var->map[var->row_user][var->col_user - 1] = 'P';
		var->map[var->row_user][var->col_user - 1] = '0';
	}
}

// void	check_move(t_data *var)
// {
// 	// if ()
// }