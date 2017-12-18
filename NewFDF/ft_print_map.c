/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:34:05 by vgauther          #+#    #+#             */
/*   Updated: 2017/12/18 19:39:12 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	ft_print_map(t_line *list, void *win, void *mlx)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (list)
	{
		while(list->nbr > x)
		{
			if(list->nbr > x + 1)
				ft_bresenham(x * 10+10, y * 10+10, (x+1) * 10+10, y * 10+10, mlx, win);
			if(list->next)
				ft_bresenham(x * 10+10, y * 10+10, x * 10+10, (y+1) * 10+10, mlx, win);
			x++;
		}
		mlx_pixel_put(mlx, win, x * 10, y * 10-1, 0x00FF00);
		x = 0;
		list = list->next;
		y++;
	}
}
