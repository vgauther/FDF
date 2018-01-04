/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xyz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 20:03:33 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/04 18:43:03 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

int ft_x(int x, int y, int z, t_data d)
{
	int new_x;
	int new_y;
	int new_z;

	x = x * 10;
	y = y * 10;
	z = z * 4;
	new_x = x * cos(d.x_angle) - y * sin(d.x_angle);
	new_y = x * sin(d.x_angle) + y * cos(d.x_angle);
	new_z = new_y * sin(d.x_angle) + z * cos(d.x_angle);
	new_y = new_y * cos(d.x_angle) - new_z * cos(d.x_angle);
	return (new_x + 100);
}

int ft_y(int x, int y, int z, t_data d)
{
	int new_x;
	int new_y;
	int new_z;

	x = x * 2;
	y = y * 2;
	z = z * 4;
	new_x = x * cos(d.y_angle) - y * sin(d.y_angle);
	new_y = x * sin(d.y_angle) + y * cos(d.y_angle);
	new_z = new_y * sin(d.y_angle) + z * cos(d.y_angle);
	new_y = new_y * cos(d.y_angle) - new_z * cos(d.y_angle);
	return (new_y + 200);
}
/*
int ft_z(int x, int y, int z, int angle)
{
	int new_x;
	int new_y;
	int new_z;

	x = x * 10;
	y = y * 10;
	z = z * 10;
	new_x = x * cos(angle) - y * sin(angle);
	new_y = x * sin(angle) + y * cos(angle);
	new_z = new_y * sin(angle) + z * cos(angle);
	new_y = new_y * cos(angle) - new_z * cos(angle);
	return (0);
}*/
