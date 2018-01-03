/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_n_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:40:21 by vgauther          #+#    #+#             */
/*   Updated: 2017/12/18 18:36:06 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

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
