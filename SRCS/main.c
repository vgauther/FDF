/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:40:29 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/09 18:23:20 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

int				ft_test(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

t_data			set_res(t_data data)
{
	int i;
	int j;

	j = 1;
	i = 1;
	data.res = -1;
	if (data.hei_map < 1000 || data.len_map < 1000)
	{
		while (((i++ * data.hei_map) < 1000) && ((i * data.len_map) < 1000))
			if (!(i % 10))
				j++;
		data.res = -i;
		data.res_z = -j;
	}
	else
	{
		while ((((data.res * data.hei_map) < 1000)
					|| ((data.res * data.len_map) < 1000)) && (data.res >= 0.1))
			data.res += 0.1;
		data.res_z = -0.1;
	}
	return (data);
}

t_data			dataset(char *str)
{
	t_data	data;

	data.test = ft_strsplit(str, '\n');
	data.hei_map = ft_test(data.test);
	data.len_map = ft_countwords(data.test[0], ' ');
	data.x_angle = 0.82;
	data.y_angle = 0.82;
	data.z_angle = -0.82;
	data.str = ft_cap(str);
	data.win_len = 1600;
	data.win_hei = 1200;
	data = set_res(data);
	return (data);
}

int				main(int ac, char **av)
{
	char		*str;
	t_tab		**tab;
	t_data		data;

	if (ac != 2)
	{
		ft_putstr("Usage : ./fdf <filename>\n");
		return (0);
	}
	str = ft_open_n_read(av[1]);
	data = dataset(str);
	if (ft_error(data.test, data) == 0)
	{
		ft_putstr("error : file cant be used\n");
		return (0);
	}
	deltab(data.test, data.hei_map);
	tab = ft_creat_tab(data.str, data);
	data.tab = tab;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.win_len, data.win_hei, "FDF");
	ft_print_map(ft_xyz(data.tab, data), data);
	mlx_hook(data.win, 2, 0, ft_key_pressed, &data);
	mlx_loop(data.mlx);
	return (0);
}
