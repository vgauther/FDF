/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:28:25 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/04 16:13:19 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	ft_bresenham(int x1,int y1, int x2, int y2, t_data data, int color)
{
	int dx;
	int dy;
	int i;
	int xinc;
	int yinc;
	int cumul;
	int x;
	int y;

	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	xinc = (dx > 0) ? 1 : -1 ;
	yinc = (dy > 0) ? 1 : -1 ;
	dx = abs(dx);
	dy = abs(dy);
	i = 1;
	mlx_pixel_put(data.mlx, data.win, x, y, color);
	if(dx > dy)
	{
		cumul = dx / 2;
		while(i <= dx)
		{
			x = x+ xinc;
			cumul = cumul + dy;
			if(cumul >= dx)
			{
				cumul = cumul - dx;
				y = y + yinc;
			}
			i++;
			mlx_pixel_put(data.mlx, data.win, x, y, color);
		}
	}
	else
	{
		cumul = dy / 2;
		while(i <= dy)
		{
			y = y + yinc;
			cumul = cumul + dx;
			if(cumul >= dy)
			{
				cumul = cumul - dy;
				x = x + xinc;
			}
			mlx_pixel_put(data.mlx, data.win, x, y, color);
			i++;
		}
	}
}
