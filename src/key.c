/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:52:16 by sberrich          #+#    #+#             */
/*   Updated: 2019/11/12 20:46:25 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int key, void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (key == 126)
		down(data);
	else if (key == 125)
		up(data);
	else if (key == 123 || key == 124)
		right_left(key, data);
	else if (key == 53)
		exit(0);
	else if (key == 8)
		change_color(param);
	else if (key == 46)
		menu_(data);
	else if (key == 15 || key == 17 || key == 24)
		rotation(key, data);
	return (0);
}

void	up(t_data *data)
{
	int i;
	int j;

	i = -1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	while (++i < data->hight)
	{
		j = -1;
		while (++j < data->width)
			data->p[i][j].y = data->p[i][j].y + 10;
	}
	ft_draw(data);
}

void	down(t_data *data)
{
	int i;
	int j;

	i = -1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	while (++i < data->hight)
	{
		j = -1;
		while (++j < data->width)
			data->p[i][j].y = data->p[i][j].y - 10;
	}
	ft_draw(data);
}

void	right_left(int key, t_data *data)
{
	int j;
	int i;

	i = -1;
	if (key == 124)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		while (++i <= data->hight - 1)
		{
			j = -1;
			while (++j < data->width)
				data->p[i][j].x = data->p[i][j].x + 10;
		}
	}
	if (key == 123)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		while (++i <= data->hight - 1)
		{
			j = -1;
			while (++j < data->width)
				data->p[i][j].x = data->p[i][j].x - 10;
		}
	}
	ft_draw(data);
}

void	rotation(int key, t_data *data)
{
	if (key == 24)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		ft_check(data->v, data);
		inc_valu(data);
		ft_draw(data);
	}
	if (key == 15)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		ft_check(data->v, data);
		rotate(data);
		ft_draw(data);
	}
	if (key == 17)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		ft_check(data->v, data);
		ft_draw(data);
	}
}
