/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:33:49 by vgauther          #+#    #+#             */
/*   Updated: 2017/12/19 10:45:26 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BUFF_SIZE 100
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

typedef struct	s_line
{
	int			*data;
	int			nbr;
	struct		s_line *next;
}				t_line;

char	*ft_open_n_read(char *target);
int		get_next_line(const int fd, char **line);
int		ft_coutwords(char *str);
void	ft_print_map(t_line *list, void *win, void *mlx);
t_line	*ft_creat_map(char *target);
void	ft_bresenham(int x1,int y1, int x2, int y2, void *mlx, void *win);

#endif
