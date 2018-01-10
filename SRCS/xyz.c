/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xyz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 20:03:33 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/09 18:23:38 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

void		rotation(t_tab **tab, t_data d, t_varxyz v)
{
	tab[v.j][v.i].co.x *= d.res;
	tab[v.j][v.i].co.y *= d.res;
	tab[v.j][v.i].z *= d.res_z;
	v.x = tab[v.j][v.i].co.x;
	v.z = tab[v.j][v.i].z;
	tab[v.j][v.i].co.x = cos(d.y_angle) * v.x + sin(d.y_angle) * v.z;
	tab[v.j][v.i].z = cos(d.y_angle) * v.z - sin(d.y_angle) * v.x;
	v.y = tab[v.j][v.i].co.y;
	v.z = tab[v.j][v.i].z;
	tab[v.j][v.i].co.y = cos(d.x_angle) * v.y - sin(d.x_angle) * v.z;
	tab[v.j][v.i].z = sin(d.x_angle) * v.y + cos(d.x_angle) * v.z;
	v.x = tab[v.j][v.i].co.x;
	v.y = tab[v.j][v.i].co.y;
	tab[v.j][v.i].co.x = cos(d.z_angle) * v.x - sin(d.z_angle) * v.y;
	tab[v.j][v.i].co.y = sin(d.z_angle) * v.x + cos(d.z_angle) * v.y;
}

t_tab		**ft_xyz(t_tab **tab, t_data d)
{
	t_varxyz v;

	v.j = -1;
	while (++v.j != d.hei_map)
	{
		v.i = -1;
		while (++v.i != d.len_map)
			rotation(tab, d, v);
	}
	return (tab);
}
