/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:09:31 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/09 18:21:41 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

char	*ft_cap(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

int		ft_pow(int src, int pui)
{
	int mult;
	int save;

	save = src;
	if (pui == 0)
		return (1);
	mult = pui - 1;
	while (mult > 0)
	{
		src *= save;
		mult--;
	}
	return (src);
}

int		ft_atoi_color(char *str)
{
	int			i[2];
	int			color;
	long int	*num;

	i[0] = 0;
	color = 0;
	i[1] = 0;
	if (!(num = malloc(sizeof(long int *) * ft_strlen(str))))
		malloc_error();
	while (str[i[1]])
	{
		if (str[i[1]] >= 'A' && str[i[1]] <= 'Z')
			num[i[1]] = (str[i[1]] - 'A' + 10);
		else
			num[i[1]] = (str[i[1]] - '0');
		i[1]++;
	}
	while (--i[1] >= 0)
	{
		color += num[i[1]] * ft_pow(16, i[0]);
		i[0]++;
	}
	free(num);
	free(str);
	return (color);
}

char	*only_color(char *str)
{
	char	*ret;
	int		i;
	int		x;
	int		mall;

	mall = ft_strlen(str);
	i = 0;
	x = 0;
	while (str[i] != ',' && str[i])
		i++;
	if (str[i] == 0)
		return (ft_strdup("FFFFFF"));
	if (!(ret = malloc(sizeof(char) * (mall - i + 3))))
		malloc_error();
	i = i + 3;
	while (str[i])
	{
		ret[x] = str[i];
		x++;
		i++;
	}
	ret[x] = 0;
	return (ret);
}
