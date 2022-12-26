/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:50:57 by ale-cont          #+#    #+#             */
/*   Updated: 2022/11/11 13:29:25 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*find;
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)haystack;
	find = (char *)needle;
	i = 0;
	if (find[i] == '\0')
		return (str);
	if (len == 0)
		return (NULL);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == find[j] && str[i + j] && find[j])
			j++;
		if (find[j] == '\0' && (i + j) <= len)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
