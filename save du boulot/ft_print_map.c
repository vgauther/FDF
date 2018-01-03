/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:34:05 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/03 14:45:18 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	ft_print_map(t_tab **tab, void *win, void *mlx, int len)
{
	int x;
	int y;
	int x1;
	int y1;
	int x2;
	int y2;
	int angle;

	y = 0;
	angle = 3.14/2;
	len = 10;
	while(y != 9)
	{
		x = 0;
		while(x != len - 1)
		{
			x1 = ft_x(x, y, tab[y][x].z, angle);
			y1 = ft_y(x, y, tab[y][x].z, angle);
			x2 = ft_x(x + 1, y, tab[y][x + 1].z, angle);
			y2 = ft_y(x + 1, y, tab[y][x + 1].z, angle);
			ft_bresenham(x1, y1, x2, y2, mlx, win);
			x2 = ft_x(x, y + 1, tab[y + 1][x].z, angle);
			y2 = ft_y(x, y + 1, tab[y + 1][x].z, angle);
			ft_bresenham(x1, y1, x2, y2, mlx, win);
			x++;
		}
			x1 = ft_x(x, y, tab[y][x].z, angle);
			y1 = ft_y(x, y, tab[y][x].z, angle);
			x2 = ft_x(x, y + 1, tab[y + 1][x].z, angle);
			y2 = ft_y(x, y + 1, tab[y + 1][x].z, angle);
			ft_bresenham(x1, y1, x2, y2, mlx, win);
		y++;
	}
}
