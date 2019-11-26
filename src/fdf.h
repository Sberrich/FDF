/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:51:47 by oelazzou          #+#    #+#             */
/*   Updated: 2019/11/12 20:38:23 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# define H		2000
# define V		1800

typedef	struct	s_bres
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int err2;
}				t_bres;

typedef struct	s_point
{
	int			x;
	int			y;
	int			value;
	int			color;
}				t_point;

typedef struct	s_data
{
	void		*win_ptr;
	void		*mlx_ptr;
	int			width;
	int			hight;
	int			zoom;
	char		*v;
	t_point		**p;
}				t_data;

void			rotation(int key, t_data *data);
void			iso(int *x, int *y, int z);
void			ft_check(char *nom, t_data *data);
void			ft_draw(t_data	*data);
void			ft_line(int color, t_point p0, t_point p1, t_data *data);
void			ft_zoom(t_data *data, char **tab);
void			rotate(t_data *data);
int				key_press(int key, void *param);
void			right_left(int key, t_data *data);
void			up(t_data *data);
void			down(t_data *data);
void			free_twod(char	**arr);
void			ft_error(char *name);
void			change_color(t_data *data);
void			show_menu(t_data *data);
void			menu_(t_data *data);
void			print_pipes(t_data *data, int i, int j, int pos);

void			inc_valu(t_data *data);
#endif
