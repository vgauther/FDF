/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:34:05 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/05 15:09:59 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	ft_print_map(t_tab **tab, t_data data)
{
	int x;
	int y;
	/*int x1;
	int y1;
	int x2;
	int y2;*/

	ft_xyz(tab,data);
	y = 0;
	while(y != data.hei_map - 1)
	{
		x = 0;
		while(x != data.len_map - 1)
		{
			/*x1 = ft_x(x, y, tab[y][x].z, data);
			y1 = ft_y(x, y, tab[y][x].z, data);
			x2 = ft_x(x + 1, y, tab[y][x + 1].z, data);
			y2 = ft_y(x + 1, y, tab[y][x + 1].z, data);*/
			ft_bresenham(tab[y][x].x, tab[y][x].y, tab[y][x+1].x, tab[y][x+1].y, data,tab[y][x+1].color);
			/*x2 = ft_x(x, y + 1, tab[y + 1][x].z, data);
			y2 = ft_y(x, y + 1, tab[y + 1][x].z, data);*/
			ft_bresenham(tab[y][x].x, tab[y][x].y, tab[y + 1][x].x, tab[y+1][x].y, data, tab[y+1][x].color);
			x++;
		}
		/*x1 = ft_x(x, y, tab[y][x].z, data);
		y1 = ft_y(x, y, tab[y][x].z, data);
		x2 = ft_x(x, y + 1, tab[y + 1][x].z, data);
		y2 = ft_y(x, y + 1, tab[y + 1][x].z, data);*/
		ft_bresenham(tab[y][x].x, tab[y][x].y, tab[y+1][x].x, tab[y+1][x].y, data,tab[y+1][x].color);
		y++;
	}
	/*x1 = ft_x(x, y, tab[y][x].z, data);
	y1 = ft_y(x, y, tab[y][x].z, data);
	x2 = ft_x(x + 1, y, tab[y][x + 1].z, data);
	y2 = ft_y(x + 1, y, tab[y][x + 1].z, data);*/
	ft_bresenham(tab[y][x].x, tab[y][x].y, tab[y][x+1].x, tab[y][x+1].y, data,tab[y][x+1].color);
}
