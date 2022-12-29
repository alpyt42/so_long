/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:20:50 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/29 17:38:46 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_arg(t_data *var)
{
	int	row;
	int	col;

	row = -1;
	while (++row < var->row_map)
	{
		col = -1;
		while (++col < var->col_map)
		{
			if (var->map[row][col] == 'E')
				var->arg.ex++;
			if (var->map[row][col] == 'C')
				var->arg.obj++;
			if (var->map[row][col] == 'P')
				var->arg.start++;
			if (var->map[row][col] == 'U')
				var->arg.en++;
			if (!ft_strchr("10CEUP", (int)var->map[row][col]))
				return (1);
		}
	}
	if (var->arg.ex != 1 || var->arg.obj == 0 
		|| var->arg.start != 1)
		return (1);
	return (0);
}

// static int	check_path(t_data *var)
// {
	
// }

static int	check_wall(t_data *var)
{
	int	row;
	int	col;

	row = -1;
	while (++row < var->row_map)
	{
		if ((int)ft_strlen(var->map[row]) != (var->col_map))
			return (1);
		col = -1;
		while (++col < var->col_map)
		{
			if (col == 0 || row == 0 || row == (var->row_map - 1) 
				|| col == (var->col_map - 1))
				if (var->map[row][col] != '1')
					return (1);
		}
	}
	return (0);
}

void	check_map(t_data *var)
{
	if (check_wall(var) != 0)
		display_error("\033[1;33mInvalid map (Check size/walls) !\033[0m\n");
	if (check_arg(var) != 0)
		display_error("\033[1;33mInvalid map (Check characters used) !\033[0m\n");
}