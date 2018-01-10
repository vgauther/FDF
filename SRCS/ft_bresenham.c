/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:28:25 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/09 18:22:33 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

void	ft_bresenham(t_coord a, t_coord b, t_data data, int color)
{
	t_draw draw;

	draw.dx = abs(b.x - a.x);
	draw.sx = a.x < b.x ? 1 : -1;
	draw.dy = abs(b.y - a.y);
	draw.sy = a.y < b.y ? 1 : -1;
	draw.err = (draw.dx > draw.dy ? draw.dx : -draw.dy) / 2;
	while (1)
	{
		mlx_pixel_put(data.mlx, data.win, a.x, a.y, color);
		if (a.x == b.x && a.y == b.y)
			break ;
		draw.err2 = draw.err;
		if (draw.err2 > -draw.dx)
		{
			draw.err -= draw.dy;
			a.x += draw.sx;
		}
		if (draw.err2 < draw.dy)
		{
			draw.err += draw.dx;
			a.y += draw.sy;
		}
	}
}
