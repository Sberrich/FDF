/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:07:02 by oelazzou          #+#    #+#             */
/*   Updated: 2019/11/12 20:48:05 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		change_color(t_data *data)
{
	int i;
	int j;

	i = -1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	while (++i < data->hight)
	{
		j = -1;
		while (++j < data->width)
			data->p[i][j].color += 0x000050;
	}
	ft_draw(data);
}

void		inc_valu(t_data *data)
{
	int		i;
	int		j;
	int		z;

	i = -1;
	z = 0;
	while (++i < data->hight)
	{
		j = -1;
		while (++j < data->width)
		{
			z = data->p[i][j].value * 2;
			iso(&data->p[i][j].x, &data->p[i][j].y, z);
		}
	}
}
