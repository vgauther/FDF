/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:40:29 by vgauther          #+#    #+#             */
/*   Updated: 2017/12/16 10:41:57 by vgauther         ###   ########.fr       */
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

void	ft_end_list(t_line *start, t_line *next)
{
	t_line *tmp;

	tmp = start;
	while(tmp->next)
		tmp = tmp->next;
	if(start && next)
		tmp->next = next;
}

t_line *add_link(char *str, int nbr)
{
	t_line	*ret;
	char	**tmp;
	int		x;

	x = 0;
	tmp = ft_strsplit(str, ' ');
	if(!(ret =  malloc(sizeof(t_line))))
		return (NULL);
	if(!(ret->data = malloc(sizeof(int) * nbr)))
		return(NULL);
	ret->nbr = nbr;
	while (tmp[x])
	{
		ret->data[x] = ft_atoi(tmp[x]);
		x++;
	}
	ret->next = NULL;
	x = 0;
	while(tmp[x])
	{
		free(tmp[x]);
		x++;
	}
	free(tmp);
	return(ret);
}

t_line	*ft_creat_map(char *target)
{
	char *str;
	char **map;
	int mal;
	int start;
	int i;
	t_line *line;
	t_line *s;

	i = 0;
	mal = 0;
	str = ft_open_n_read(target);
	start = 0;
	while(str[i])
	{
		if(str[i] == '\n')
			mal++;
		i++;
	}
	i = 0;
	map = ft_strsplit(str, '\n');
	while(map[i])
	{
		line = add_link(map[i], ft_coutwords(map[i]));
		if (start == 0)
		{
			s = line;
			start++;
		}
		else
			ft_end_list(s, line);
		i++;
	}
	line = s;
	/*while(line)
	{
		i = 0;
		while(i < line->nbr)
		{
			printf("%d ", line->data[i]);
			i++;
		}
		printf("\n");
		line = line->next;
	}*/
	return(s);
}

int main(int ac, char **av)
{
	void *mlx;
	void *win;
	t_line *list;
	int i;
	int j;
	int i2;

	j = 0;
	i = 0;
	i2 = 10;
	if (ac != 2)
		return 0;

	list = ft_creat_map(av[1]);
	mlx = mlx_init();
	win = mlx_new_window(mlx, list->nbr * 100, list->nbr * 100, "FDF's window");
	mlx_key_hook(win,ft_exit, 0);
	while(list)
	{
		while(i != list->nbr)
		{
			if(list->data[i] == 0)
			{
				while(i2 != (i+1)* 20 + 10)
				{
					mlx_pixel_put(mlx, win, i2, j * 10 + 10, 0xFF0000);
					i2++;
				}
			}
			else
			{
				while(i2 != (i+1)* 20 + 10)
				{
					mlx_pixel_put(mlx, win, i2, j * 10 + 10, 0x00FF00);
					i2++;
				}
			}
			i++;
		}
		i = 0;
		i2 = 10;
		j++;
		list = list->next;
	}
	mlx_loop(mlx);
	return 0;
}

/*
	algorithm de bresenham
	faire une projection de bie via cos sin (chercher rotation axes)

*/
