/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:34:05 by vgauther          #+#    #+#             */
/*   Updated: 2017/12/19 16:21:56 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	ft_print_map(t_line *list, void *win, void *mlx)
{
	int x;
	int y;
	int x1;
	int y1;
	int x2;
	int y2;
	int a;
	int x_save;
	int y_save;

	x_save = 0;
	y_save = 0;
	x2 = 0;
	y2 = 0;
	x1 = 0;
	y1 = 0;
	a = 3.14/3;
	x = 0;
	y = 0;
	while (list)
	{
		while(list->nbr > x)
		{
			x_save = (10 * x) + 110;
			y_save = (10 * y) + 110;
			x1 = cos(a) * x_save - y_save * sin(a);
			y1 = cos(a) * y_save + x_save * sin(a);
			x2 = (10 * (x + 1)) + 110;
			x2 = x2 * cos(a) - y_save * sin(a);
			y2 = y_save * cos(a) + (x_save + 10) * sin(a);
			if(list->nbr > x + 1)
			{
				//mlx_pixel_put(mlx,win, x1, y1, 0x00FF00);
				ft_bresenham(x1+150, y1, x2+150, y2, mlx, win);
				//mlx_pixel_put(mlx,win, x1, y1, 0x00FF00);
			}
			y2 = (10 * (y + 1)) + 110;
			x2 = cos(a) * x_save - y2 * sin(a);
			y2 = cos(a) * y2 + x_save * sin(a);
			if(list->next)
			{
				//mlx_pixel_put(mlx,win, x1, y1, 0x00FF00);
				ft_bresenham(x1+150, y1, x2+150, y2, mlx, win);
				//mlx_pixel_put(mlx,win, x1+150, y1, 0x00FF00);
			}
				x++;
		}
		x = 0;
		list = list->next;
		y++;
	}
				mlx_pixel_put(mlx,win, x2, y1, 0x00FF00);
}
