/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:40:29 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/04 18:48:03 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

int	ft_exit(int keycode, void *param)
{
	t_data *data;

	data = (t_data *)param;
	if(keycode == 53)
		exit(0);
	else if(keycode == 126)
		data->x_angle = data->x_angle - 0.1;
	else if(keycode == 125)
		data->x_angle = data->x_angle + 0.1;
	else if(keycode == 124)
		data->z_angle = data->angle + 0.1;
	else if(keycode == 123)
		data->z_angle = data->z_angle - 0.1;
	else if (keycode == 38)
		data->y_angle = data->y_angle - 0.1;
	else if (keycode == 37)
		data->y_angle = data->y_angle + 0.1;
	else
		return (0);
	mlx_clear_window(data->mlx, data->win);
	ft_print_map(data->tab, *data);
	return(0);
}

/*
int		ft_coutwords(char *str)
{
	int nbr;
	int i;

	nbr = 0;
	i = 0;
	while (str[i])
	{
		while(str[i] == ' ' || str[i] == '\t')
			i++;
		if(str[i] != 0)
		{
			while(str[i] != ' ' && str[i] != '\t' && str[i] != 0)
				i++;
			nbr++;
		}
		while(str[i] == ' ' || str[i] == '\t')
			i++;
	}
	return (nbr);
}*/

int main(int ac, char **av)
{
	char *str;
	t_tab **tab;
	t_data	data;

	if (ac != 2)
		return 0;
	str = ft_open_n_read(av[1]);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 500, 500, "FDF's window");
	data.len_map = ft_count_len(str);
	data.hei_map = ft_count_hei(str);
	data.angle = 0.82;
	data.res = 10;
	data.x_angle = 0.82;
	data.y_angle = 0.82;
	data.z_angle = 0.82;
	tab = open_in_tab(str,data);
	free(str);
	data.tab = tab;
	ft_print_map(tab, data);
	ft_putstr("3");
	mlx_key_hook(data.win,ft_exit, &data);
	mlx_loop(data.mlx);
	return 0;
}
