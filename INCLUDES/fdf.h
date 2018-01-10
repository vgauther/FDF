/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:33:49 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/09 18:21:24 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BUFF_SIZE 10000
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

typedef struct	s_coord
{
	int x;
	int y;
}				t_coord;

typedef struct	s_tab
{
	int			z;
	int			y;
	int			x;
	t_coord		co;
	int			color;
}				t_tab;

typedef struct	s_size
{
	int y;
	int x;
	int xmin;
	int ymin;
	int xmax;
	int ymax;
	int size_x;
	int size_y;
}				t_size;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	int			len_map;
	int			hei_map;
	int			win_len;
	int			win_hei;
	double		res;
	double		res_z;
	double		x_angle;
	double		y_angle;
	double		z_angle;
	char		*str;
	char		**test;
	t_tab		**tab;
}				t_data;

typedef struct	s_varxyz
{
	int	j;
	int i;
	int x;
	int y;
	int z;
}				t_varxyz;

typedef struct	s_draw
{
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int err2;
}				t_draw;

char			*ft_cap(char *str);
char			*ft_open_n_read(char *target);
int				get_next_line(const int fd, char **line);
void			ft_print_map(t_tab **tab, t_data data);
t_tab			**open_in_tab(char *str, t_data data);
int				ft_count_hei(char *str);
int				ft_count_len(char *str);
t_tab			**ft_xyz(t_tab **tab, t_data data);
void			free_s_tab(t_tab **tab, t_data data);
char			*only_color(char *str);
int				ft_atoi_color(char *str);
t_tab			**ft_creat_tab(char *str, t_data data);
void			ft_bresenham(t_coord a, t_coord b, t_data data, int color);
int				ft_countwords(char const *s, char c);
int				ft_error(char **tab, t_data data);
int				ft_key_pressed(int keycode, void *param);
void			malloc_error(void);
void			free_s_tab(t_tab **tab, t_data data);
void			deltab(char **tab, int len);

#endif
