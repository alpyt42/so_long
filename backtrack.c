/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:50:28 by agaley            #+#    #+#             */
/*   Updated: 2023/01/02 22:11:04 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "so_long.h"

void	ft_display_answ(int map[10][10])
{
	int		r;
	int		c;
	char	pos;

	r = 0;
	while (r < 10)
	{
		c = 0;
		while (c < 10)
		{
			if (map[r][c] == 1)
				pos = c + '0';
			if (map[r][c] == 1)
				write(1, &pos, 1);
			c++;
		}
		r++;
	}
	write(1, "\n", 1);
}

int	ft_queen_pos_ok(int tab[10][10], int row, int col)
{
	int	x;
	int	rdiagp;
	int	cdiagp;
	int	rdiagm;
	int	cdiagm;

	x = 0;
	rdiagp = row + 1;
	rdiagm = row - 1;
	cdiagp = col + 1;
	cdiagm = col - 1;
	while (x < 10)
	{
		if ((x != row && tab[x][col] == 1) || (x != col && tab[row][x] == 1)
			|| (rdiagp < 10 && cdiagp < 10 && tab[rdiagp][cdiagp] == 1)
			|| (rdiagm >= 0 && cdiagm >= 0 && tab[rdiagm][cdiagm] == 1)
			|| (rdiagm >= 0 && cdiagp < 10 && tab[rdiagm][cdiagp] == 1))
			return (0);
		rdiagp++;
		cdiagp++;
		rdiagm--;
		cdiagm--;
		x++;
	}
	return (1);
}

int	ft_put_queens(int map[10][10], int row, int count)
{
	int	c;

	if (row == 10)
	{
		ft_display_answ(map);
		count++;
		return (count);
	}
	c = 0;
	while (c < 10)
	{
		if (ft_queen_pos_ok(map, row, c))
		{
			map[row][c] = 1;
			count = ft_put_queens(map, row + 1, count);
			map[row][c] = 0;
		}
		c++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int		map[10][10];
	int		i;
	int		j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (ft_put_queens(map, 0, 0));
}

int	main(void)
{
	printf("\nres:%d\n", ft_ten_queens_puzzle());
}