/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:42:35 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/28 21:47:14 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_joinbuff(int fd, char *left_str)
{
	char	*buf;
	int		rd_bytes;

	rd_bytes = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (gnl_locate_return(left_str) == 0 && rd_bytes != 0)
	{
		rd_bytes = read(fd, buf, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buf);
			free(left_str);
			return (NULL);
		}
		buf[rd_bytes] = '\0';
		left_str = gnl_strjoin(left_str, buf);
	}
	free(buf);
	return (left_str);
}

char	*gnl(int fd)
{
	char			*line;
	static char		*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	left_str = gnl_joinbuff(fd, left_str);
	if (!left_str)
		return (NULL);
	line = gnl_fill_line(left_str);
	left_str = gnl_new_str(left_str);
	return (line);
}
