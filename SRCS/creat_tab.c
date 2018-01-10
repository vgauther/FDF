/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:45:38 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/09 18:27:39 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

void	put_data_in_tab(t_tab **tab, int x, int y, char *str)
{
	tab[y][x].z = ft_atoi(str);
	tab[y][x].co.y = y;
	tab[y][x].co.x = x;
	tab[y][x].color = ft_atoi_color(only_color(str));
}

t_tab	**ft_creat_tab(char *str, t_data data)
{
	t_tab	**tab;
	char	**tmp8;
	char	**tmp2;
	int		x;
	int		y;

	y = -1;
	tmp8 = ft_strsplit(str, '\n');
	if (!(tab = malloc(sizeof(t_tab *) * (data.hei_map))))
		malloc_error();
	while (++y < data.hei_map)
	{
		x = -1;
		if (!(tab[y] = malloc(sizeof(t_tab) * (data.len_map + 1))))
			malloc_error();
		tmp2 = ft_strsplit(tmp8[y], ' ');
		while (++x < data.len_map)
		{
			put_data_in_tab(tab, x, y, tmp2[x]);
		}
		deltab(tmp2, x);
	}
	deltab(tmp8, y);
	return (tab);
}
