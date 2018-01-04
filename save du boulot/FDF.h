/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:33:49 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/04 18:39:10 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BUFF_SIZE 1000
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

typedef struct	s_tab
{
	int			z;
	int			color;
}				t_tab;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	int			len_map;
	int			hei_map;
	double		angle;
	int			res;
	double		x_angle;
	double		y_angle;
	double		z_angle;
	t_tab		**tab;
}				t_data;

typedef struct	s_line
{
	int			*data;
	int			nbr;
	struct		s_line *next;
}				t_line;

char	*ft_open_n_read(char *target);
int		get_next_line(const int fd, char **line);
//int		ft_coutwords(char *str);
void	ft_print_map(t_tab **tab, t_data data);
t_line	*ft_creat_map(char *target);
void	ft_bresenham(int x1,int y1, int x2, int y2, t_data data, int color);
int		ft_x(int x, int y, int z, t_data d);
int		ft_y(int x, int y, int z, t_data d);
//int		ft_z(int x, int y, int z, int angle);
t_tab	**open_in_tab(char *str, t_data data);
int		ft_count_hei(char *str);
int		ft_count_len(char *str);

#endif
