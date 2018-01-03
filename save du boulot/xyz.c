/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xyz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 20:03:33 by vgauther          #+#    #+#             */
/*   Updated: 2017/12/30 23:36:04 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

int ft_x(int x, int y, int z, int angle)
{
	int new_x;
	int new_y;
	int new_z;

	x = x * 10;
	y = y * 10;
	z = z * 4;
	new_x = x*cos(angle) - y*sin(angle);
	new_y = x*sin(angle) + y*cos(angle);
	angle = angle / 2;
	new_z = new_y*sin(angle) + z*cos(angle);
	new_y = new_y*cos(angle) - new_z*cos(angle);
	return (new_x + 150);
}

int ft_y(int x, int y, int z, int angle)
{
	int new_x;
	int new_y;
	int new_z;

	x = x * 10;
	y = y * 10;
	z = z * 4;
	new_x = x*cos(angle) - y*sin(angle);
	new_y = x*sin(angle) + y*cos(angle);
	angle = angle / 2;
	new_z = new_y*sin(angle) + z*cos(angle);
	new_y = new_y*cos(angle) - new_z*cos(angle);
	return (new_y + 150);
}

int ft_z(int x, int y, int z, int angle)
{
	int new_x;
	int new_y;
	int new_z;

	x = x * 10;
	y = y * 10;
	z = z * 10;
	new_x = x*cos(angle) - y*sin(angle);
	new_y = x*sin(angle) + y*cos(angle);
	new_z = new_y*sin(angle) + z*cos(angle);
	new_y = new_y*cos(angle) - new_z*cos(angle);
	return (0);
}
