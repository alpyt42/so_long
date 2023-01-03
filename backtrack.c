/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:50:28 by agaley            #+#    #+#             */
/*   Updated: 2023/01/03 15:15:45 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int chess_board[20], count;

void nqueen_function(int row, int num)
{
    int col;

	col = 0;
    while (++col <= num)
    {
        if (placeholder(row, col)) //function call to check where to place the queen
        {
            chess_board[row] = col;
            if (row == num) //ensures if all queens are placed or not
                display(num); //once all queens placed; display solution.
            else
                nqueen_function(row + 1, num); //function call to place remaining queens.
        }
    }
}

int placeholder(int row, int col)
{
    int count;

	count = 0;
    while (++count <= row - 1)
    {
        if (chess_board[count] == col) //checks if there is any threat from queen placed previously.
            return 0;
        else
            if (abs(chess_board[count] - col) == abs(count - row)) //check for diagonal conflicts.
                return 0;
    }
    return 1; //no threats, queen can be placed.
}

int display(int num)
{
    int m, n;
    printf("\n\n\tPossible Solution %d:\n\n", ++count);
    for (m = 1; m <= num; m++)
        printf("\t[%d]", m);
    for (m = 1; m <= num; m++)
    {
        printf("\n\n[%d]", m);
        for (n = 1; n <= num; n++)
        {
            if (chess_board[m] == n)
                printf("\tQ"); //queen at (i,j) position.
            else
                printf("\t*"); //empty slot.
        }
    }
}

int main()
{
    int num;
    printf("\nEnter Number of Queens:\t");
    scanf("%d", &num);
    if (num <= 3)
        printf("\nNumber should be greater than 3 to form a Matrix\n");
    else
        nqueen_function(1, num); //call to nqueen function
    printf("\n\n");
    return 0;
}