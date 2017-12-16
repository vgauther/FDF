/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_n_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:40:21 by vgauther          #+#    #+#             */
/*   Updated: 2017/12/14 17:00:39 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"
/*
char	*ft_read(int fd, int i, int x)
{
	char	*str_ret;
	char	buf[BUFF_SIZE + 1];
	int		ret;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		if (str_ret)
		{
			x = ft_strlen(str_ret) + ft_strlen(buf) + 1;
			free(str_ret);
			if (!(str_ret = malloc(sizeof(char) * x)))
				return (NULL);
		}
		else
		{
			if (!(str_ret = malloc(sizeof(char) * ft_strlen(buf) + 1)))
				return (NULL);
		}
		x = -1;
		while (buf[++x])
			str_ret[i++] = buf[x];
		str_ret[i] = 0;
	}
	return (str_ret);
}
*/

char	*ft_read(int fd)
{
	char *str;
	char buf[BUFF_SIZE + 1];
	int ret;
	char *tmp;


	str = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		tmp = str;
		str= ft_strjoin(str, buf);
		free(tmp);
	}
	return (str);
}
char	*ft_open_n_read(char *target)
{
	int		fd;
	char	*str_ret;

	fd = open(target, O_RDONLY);
	str_ret = ft_read(fd);
	return (str_ret);
}
