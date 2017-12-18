/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:28:25 by vgauther          #+#    #+#             */
/*   Updated: 2017/12/18 19:14:00 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	ft_bresenham(int x1,int y1, int x2, int y2, void *mlx, void *win)
{
	int dx;
	int dy;
	int e;

	if (x1 < x2)
	{
		e = x2 - x1;
		dx = e * 2;
		dy = (y2 - y1) * 2;
		while(x1 <= x2)
		{
			mlx_pixel_put(mlx, win, x1, y1, 0xFF0000);
			x1++;
			e = e - dy;
			if(e <= 0)
			{
				y1++;
				e = e + dx;
			}
		}
	}
	else
	{
		e = y2 - y1;
		dy = e * 2;
		dx = (x2 - x1) * 2;

		while(y1 <= y2)
		{
			mlx_pixel_put(mlx, win, x1, y1, 0xFF0000);
			y1++;
			e = e - dx;
			if(e <= 0)
			{
				x1++;
				e = e + dy;
			}
		}

	}
}
