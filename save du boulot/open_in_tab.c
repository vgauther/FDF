/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_in_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 14:49:05 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/04 16:44:21 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

int		ft_count_len(char *str)
{
	int i;
	int nbr;

	i = 0;
	nbr = 0;
	while(str[i] != '\n')
	{
		while (str[i] == ' ')
			i++;
		while (str[i] != 0 && str[i] != ' ')
			i++;
		nbr++;
		while (str[i] == ' ')
			i++;
		if(str[i + 1] == '\n')
			i++;
	}
	return (nbr + 1);
}
/*
void	ft_print_tab(t_tab **tab, int len)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(tab[y])
	{
		while(x != len - 1)
		{
			printf("%d ", tab[y][x].z);
			x++;
		}
		printf("\n");
		x = 0;
		y++;
	}
}*/

int		ft_count_hei(char *str)
{
	int i;
	int nbr;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		if(str[i] == '\n')
			nbr++;
		i++;
	}
	return (nbr);
}

char *ft_cap(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return(ft_strdup(str));
}

int		ft_atoi_color(char *str)
{
	int i;
	int color;
	int mult;

	mult = 1;
	i = 7;
	color = 0;
	str = ft_cap(ft_strdup(str));
	while(i != 1)
	{
		if (str[i] >= 'A' && str[i] <= 'Z' )
			color = color + (str[i] - 55) * mult;
		else
			color = color + (str[i] - 48) * mult;
		i--;
		mult = mult * 16;
	}
	return (color);

}

char *only_color(char *str)
{
	char *ret;
	int i;
	int x;

	i = 0;
	x = 0;
	while(str[i] != ',' && str[i])
		i++;
	if(str[i] == 0)
		return ("0xFFFFFF");
	if(!(ret = malloc(sizeof(char) * 9)))
		return (NULL);
	i++;
	while(str[i])
	{
		ret[x] = str[i];
		x++;
		i++;
	}
	return (ret);
}

t_tab **open_in_tab(char *str, t_data data)
{
	t_tab **tab;
	char **tmp;
	char **tmp2;
	int x;
	int y;

	x = 0;
	y = 0;
	tmp = ft_strsplit(str, '\n');
	if(!(tab = malloc(sizeof(t_tab *) * data.hei_map)))
		return (NULL);
	while(tmp[y])
	{
		if(!(tab[y] = malloc(sizeof(t_tab) * data.len_map)))
			return (NULL);
		tmp2 = ft_strsplit(tmp[y], ' ');
		while(tmp2[x])
		{
			tab[y][x].z = ft_atoi(tmp2[x]);
			tab[y][x].color = ft_atoi_color(only_color(tmp2[x]));
			x++;
		}
		free(tmp2);
		x = 0;
		y++;
	}
	return (tab);
}

//FFFFFF = 15728640+983040+61440+3840+240+15
