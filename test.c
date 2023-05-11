/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:58:37 by sraza             #+#    #+#             */
/*   Updated: 2023/05/11 20:57:06 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

void	isometric(float *x, float *y, float *z)
{
    float i = *x;
    float j = *y;
    float k = *z;
	*x = ((1 / sqrt(2)) * i) - ((1 / sqrt(2)) * j);
	*y = ((1 / sqrt(6)) * i) + ((1 / sqrt(6)) * j) + ((2 / sqrt(6)) * k);
	*z = ((-1 / sqrt(3)) * i) - ((1 / sqrt(3)) * j) + ((1 / sqrt(3)) * k);
}



int main(void)
{
    float x = 1;
    float y = 1;
    float z = 12;

    
    while (y < 10)
    {
        x = 1;
        while (x < 10)
        {
            printf("x = %f || y = %f || z = %f \n", x, y, z);
            isometric(&x, &y, &z);
            x++;
        }
        y++;
        if (y < 0)
            break ;
    }
    return (0);
}