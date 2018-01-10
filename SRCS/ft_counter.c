/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:37:37 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/09 18:22:42 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

int		ft_count_hei(char *str)
{
	int i;
	int nbr;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			nbr++;
		i++;
	}
	return (nbr);
}
