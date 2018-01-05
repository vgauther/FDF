/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:40:29 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/05 16:34:30 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

int	ft_exit(int keycode, void *param)
{
	t_data *data;

	data = (t_data *)param;
	printf("%d\n",keycode);
	if(keycode == 53)
	{
		free_s_tab(data->tab, *data);
		exit(0);
	}
	else if(keycode == 124)
		data->x_angle = data->x_angle - 0.1;
	else if(keycode == 123)
		data->x_angle = data->x_angle + 0.1;
	else if(keycode == 126)
		data->z_angle = data->angle + 0.1;
	else if(keycode == 125)
		data->z_angle = data->z_angle - 0.1;
	else if (keycode == 38)
		data->y_angle = data->y_angle - 0.1;
	else if (keycode == 37)
		data->y_angle = data->y_angle + 0.1;
	else if (keycode == 27)
		data->res = data->res - 1;
	else if (keycode == 24)
		data->res = data->res + 1;
	else
		return (0);
	mlx_clear_window(data->mlx, data->win);
	printf("test :%d\n",data->res);
	free_s_tab(data->tab, *data);
	data->tab = open_in_tab(data->str,*data);
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
	/*data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 500, 500, "FDF's window");*/
	data.len_map = ft_count_len(str);
	data.hei_map = ft_count_hei(str);
	data.angle = 0.82;
	data.res = 10;
	data.x_angle = 0.82;
	data.y_angle = 0.82;
	data.z_angle = -0.82;
	data.str = str;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 500, 500, "FDF's window");
	tab = open_in_tab(str,data);
	//mlx_key_hook(data.win,ft_exit, &data);
	//tab = ft_xyz(tab, data);
	//data.tab = tab;
	ft_print_map(tab, data);
	data.tab = tab;
	free_s_tab(tab, data);
	mlx_key_hook(data.win,ft_exit, &data);
	mlx_loop(data.mlx);
	return 0;
}
