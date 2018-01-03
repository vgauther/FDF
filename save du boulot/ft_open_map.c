/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:29:44 by vgauther          #+#    #+#             */
/*   Updated: 2017/12/18 18:41:02 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"


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
	return(s);
}
