/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:10:20 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/04 14:14:18 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_arr(char ***arr)
{
	int	i;

	i = 0;
	// printf("arr[]%s\n", arr[0]);
	// printf("arr[]%s\n", arr[1]);
	// printf("arr[]%s\n", arr[2]);
	// printf("arr[]%s\n", arr[3]);
	// printf("arr[]%s\n", arr[4]);
	// printf("arr[]%s\n\n\n", arr[5]);
	printf("befsizeof%lu\n", sizeof(arr[i]));
	free(*arr[i]);
	printf("aftsizeof%lu\n", sizeof(arr[i]));
	free(arr);
	// printf("arr[]after%d\n", i);
	// printf("arr[]after%s\n", arr[0]);
	// printf("arr[]after%s\n", arr[1]);
	// printf("arr[]after%s\n", arr[2]);
	// printf("arr[]after%s\n", arr[3]);
	// printf("arr[]after%s\n", arr[4]);
	// printf("arr[]after%s\n\n\n", arr[5]);
}

int	main(void)
{
	char *test = malloc(sizeof(char) * 5);
	test[] = "test";
	ft_free_arr()
}