/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:40:29 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/03 22:46:00 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

int	ft_exit(int keycode)
{
	if(keycode != 53)
		return 0;
	exit(0);
}

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
}

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
	printf("%d\n", data.len_map);
	printf("%d", data.hei_map);
	mlx_key_hook(data.win,ft_exit, 0);
	tab = open_in_tab(str);
	ft_print_map(tab, data);
	mlx_loop(data.mlx);
	return 0;
}
