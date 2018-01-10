/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:20:49 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/09 18:22:26 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

void	free_s_tab(t_tab **tab, t_data data)
{
	int i;

	i = 0;
	while (i != data.hei_map)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	deltab(char **tab, int len)
{
	int i;

	i = 0;
	while (len != i)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
