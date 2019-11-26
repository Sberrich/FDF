/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:53:45 by sberrich          #+#    #+#             */
/*   Updated: 2019/11/12 20:48:52 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			iso(int *x, int *y, int z)
{
	int			previous_x;
	int			previous_y;
	double		angel;

	previous_x = *x;
	previous_y = *y;
	angel = 0.523599;
	*x = ((previous_x - previous_y) * cos(angel)) + H / 4;
	*y = -z + ((previous_x + previous_y) * sin(angel)) + V / 8;
}

void			rotate(t_data *data)
{
	int			i;
	int			j;

	i = -1;
	while (++i < data->hight)
	{
		j = -1;
		while (++j < data->width)
		{
			iso(&data->p[i][j].x, &data->p[i][j].y, data->p[i][j].value);
		}
	}
}

void			ft_zoom(t_data *data, char **tab)
{
	int x;

	x = ft_count_tab(tab);
	data->zoom = 700 / x;
}
