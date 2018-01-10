/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:51:04 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/09 18:22:20 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

int		ft_error(char **tab, t_data data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (data.len_map == 0 || data.hei_map == 0)
		return (0);
	while (tab[y])
	{
		if (ft_countwords(tab[y], ' ') != data.len_map)
			return (0);
		y++;
	}
	return (1);
}

void	malloc_error(void)
{
	ft_putstr("a malloc failed\n");
	exit(0);
}
