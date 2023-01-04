/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:13:17 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/04 15:13:58 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_error(t_data *var, char *error)
{
	ft_free_arr(var->bt_map);
	ft_free_arr(var->map);
	ft_putstr_fd(error, 2);
	exit(EXIT_FAILURE);
}
