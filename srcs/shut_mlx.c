/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shut_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:29:23 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/29 19:48:12 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	free_all(t_data *var, char *msg)
{
	int	row;

	if (!msg)
		ft_putstr_fd("Game closed\n", 1);
	else
		ft_putstr_fd(msg, 1);
	mlx_destroy_window(var->mlx, var->mlx_win);
	row = -1;
	while (++row < var->row_map)
		free(var->map[row]);
	free(var->map);
	free(var->mlx);
	exit(EXIT_FAILURE);
	return (0);
}