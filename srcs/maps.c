/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:54:43 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/28 22:24:38 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_size(t_data *var, char **argv)
{
	int		fd;
	char	*res_gnl;

	var->x_map = 0;
	var->y_map = 0;
	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
		display_error(strerror(errno));
	res_gnl = gnl(fd);
	while(res_gnl)
	{
		var->x_map = ft_strlen(res_gnl);
		var->y_map++;
		res_gnl = gnl(fd);
	}
	close(fd);
}
