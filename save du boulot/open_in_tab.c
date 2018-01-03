/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_in_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 14:49:05 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/03 22:34:03 by vgauther         ###   ########.fr       */
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
		while (str[i] == ' ' ||  str[i] == '\t')
			i++;
		while (str[i] != 0 && str[i] != ' ' && str[i] != '\t')
			i++;
		nbr++;
		while (str[i] == ' ' ||  str[i] == '\t')
			i++;
		if(str[i + 1] == '\n')
			i++;
	}
	return (nbr + 1);
}

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

}

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

t_tab **open_in_tab(char *str)
{
	t_tab **tab;
	char **tmp;
	char **tmp2;
	int len;
	int hei;
	int x;
	int y;

	x = 0;
	y = 0;
	len = ft_count_len(str);
	hei = ft_count_hei(str);
	tmp = ft_strsplit(str, '\n');
	if(!(tab = malloc(sizeof(t_tab *) * hei)))
		return (NULL);
	while(tmp[y])
	{
		if(!(tab[y] = malloc(sizeof(t_tab) * len)))
			return (NULL);
		tmp2 = ft_strsplit(tmp[y], ' ');
		while(tmp2[x])
		{
			tab[y][x].z = ft_atoi(tmp2[x]);
			tab[y][x].color = 0xff0000;
			x++;
		}
		free(tmp2);
		x = 0;
		y++;
	}
	return (tab);
}
