/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:40:29 by vgauther          #+#    #+#             */
/*   Updated: 2017/12/18 18:46:56 by vgauther         ###   ########.fr       */
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
	void *mlx;
	void *win;
	t_line *list;
	
	if (ac != 2)
		return 0;
	list = ft_creat_map(av[1]);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "FDF's window");
	mlx_key_hook(win,ft_exit, 0);
	ft_print_map(list, win, mlx);
	mlx_loop(mlx);
	return 0;
}

/*
	algorithm de bresenham
	faire une projection de bie via cos sin (chercher rotation axes)
*/
