/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:56:01 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/09 18:27:32 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

t_data	*reset_data(int keycode, t_data *data)
{
	if (keycode == 12)
	{
		data->x_angle = 0;
		data->y_angle = 0;
		data->z_angle = 0;
	}
	else
	{
		data->x_angle = 0.82;
		data->y_angle = 0.82;
		data->z_angle = -0.82;
	}
	return (data);
}

t_data	*key(int keycode, t_data *data)
{
	if (keycode == 124)
		data->x_angle = data->x_angle - 0.1;
	else if (keycode == 123)
		data->x_angle = data->x_angle + 0.1;
	else if (keycode == 126)
		data->z_angle = data->z_angle + 0.1;
	else if (keycode == 125)
		data->z_angle = data->z_angle - 0.1;
	else if (keycode == 37)
		data->y_angle = data->y_angle + 0.1;
	else if (keycode == 38)
		data->y_angle = data->y_angle - 0.1;
	else if (keycode == 27)
		data->res = data->res + 1;
	else if (keycode == 24)
		data->res = data->res - 1;
	else if (keycode == 6)
		data->res_z += 1;
	else if (keycode == 7)
		data->res_z -= 1;
	else if (keycode == 12 || keycode == 13)
		data = reset_data(keycode, data);
	return (data);
}

int		ft_key_pressed(int keycode, void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (keycode == 53)
	{
		free_s_tab(data->tab, *data);
		exit(0);
	}
	if (keycode == 7 || keycode == 6 || keycode == 24 || keycode == 27 || \
		keycode == 38 || keycode == 37 || keycode == 12 || keycode == 13 \
		|| (keycode >= 123 && keycode <= 126))
	{
		data = key(keycode, data);
		mlx_clear_window(data->mlx, data->win);
		free_s_tab(data->tab, *data);
		data->tab = ft_creat_tab(data->str, *data);
		ft_print_map(ft_xyz(data->tab, *data), *data);
	}
	return (0);
}
