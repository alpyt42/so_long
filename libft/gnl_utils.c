/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:54:39 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/29 15:38:42 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	gnl_locate_return(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*gnl_strjoin(char *left_str, char *buf)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!left_str)
	{
		left_str = (char *)malloc(sizeof(char) * 1);
		if (!left_str)
			return (NULL);
		left_str[0] = '\0';
	}
	if (!left_str || !buf)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(left_str) + ft_strlen(buf) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buf[j] != '\0')
		str[i++] = buf[j++];
	str[ft_strlen(left_str) + ft_strlen(buf)] = '\0';
	return (free(left_str), str);
}

char	*gnl_fill_line(char *left_str)
{
	char	*line;
	int		len;

	len = 0;
	if (!left_str[len])
		return (NULL);
	while (left_str[len] != '\n' && left_str[len])
		len++;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	len = 0;
	while (left_str[len] && left_str[len] != '\n')
	{
		line[len] = left_str[len];
		len++;
	}
	line[len] = '\0';
	return (line);
}

char	*gnl_new_str(char *left_str)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (left_str[i] != '\n' && left_str[i])
		i++;
	if (left_str[i] == '\0')
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free (left_str);
	return (str);
}
