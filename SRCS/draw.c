/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:29:02 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/09 18:22:00 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

t_size		calc_size(t_tab **tab, t_data data)
{
	t_size size;

	size.y = -1;
	size.xmin = 0;
	size.ymin = 0;
	size.xmax = 0;
	size.ymax = 0;
	while (++size.y < data.hei_map)
	{
		size.x = -1;
		while (++size.x < data.len_map)
		{
			if (tab[size.y][size.x].co.x < size.xmin)
				size.xmin = tab[size.y][size.x].co.x;
			if (tab[size.y][size.x].co.y < size.ymin)
				size.ymin = tab[size.y][size.x].co.y;
			if (tab[size.y][size.x].co.x > size.xmax)
				size.xmax = tab[size.y][size.x].co.x;
			if (tab[size.y][size.x].co.y > size.ymax)
				size.ymax = tab[size.y][size.x].co.y;
		}
	}
	size.size_x = (size.xmax - size.xmin) + 100;
	size.size_y = (size.ymax - size.ymin) + 500;
	return (size);
}

void		ft_centre(t_tab **tab, t_data data)
{
	t_size		size;
	int			x;
	int			y;

	size = calc_size(tab, data);
	y = 0;
	while (y < data.hei_map)
	{
		x = 0;
		while (x < data.len_map)
		{
			tab[y][x].co.y = ((size.ymax - tab[y][x].co.y) + 50);
			tab[y][x].co.x = ((size.xmax - tab[y][x].co.x) + 50);
			x++;
		}
		y++;
	}
}

void		ft_print_map(t_tab **tab, t_data data)
{
	int x	;
	int y;

	y = 0;
	ft_centre(tab, data);
	while (y != data.hei_map)
	{
		x = 0;
		while (x != data.len_map - 1)
		{
			ft_bresenham(tab[y][x].co, tab[y][x + 1].co, \
					data, tab[y][x + 1].color);
			if (y != data.hei_map - 1)
			{
				ft_bresenham(tab[y][x].co, \
					tab[y + 1][x].co, data, tab[y + 1][x].color);
			}
			x++;
		}
		if (y != data.hei_map - 1)
			ft_bresenham(tab[y][x].co, tab[y + 1][x].co, \
					data, tab[y + 1][x].color);
		y++;
	}
}
