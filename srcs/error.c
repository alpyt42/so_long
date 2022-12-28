/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:13:17 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/28 15:17:24 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_error(char *strerr, char *error)
{
	char	*error_ms;

	error_ms = NULL;
	if (error[0] != '\0')
		error_ms = ft_strjoin(strerr, ": ");
	error_ms = ft_strjoin(error_ms, error);
	ft_putstr_fd(error_ms, 2);
	ft_putstr_fd("\n", 2);
	free(error_ms);
	exit(EXIT_FAILURE);
}