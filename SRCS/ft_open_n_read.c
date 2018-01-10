/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_n_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:40:21 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/09 18:22:59 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

char	*ft_read(int fd)
{
	char	*str;
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*tmp;

	str = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		tmp = str;
		str = ft_strjoin(str, buf);
		free(tmp);
	}
	if (ret == -1)
	{
		ft_putstr("error : wrong file\n");
		exit(0);
	}
	return (str);
}

char	*ft_open_n_read(char *target)
{
	int		fd;
	char	*str_ret;

	if ((fd = open(target, O_RDONLY)) < 0)
	{
		ft_putstr("error : the file descriptor is negative\n");
		exit(0);
	}
	str_ret = ft_read(fd);
	return (str_ret);
}
