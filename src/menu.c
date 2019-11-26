/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 21:57:02 by oelazzou          #+#    #+#             */
/*   Updated: 2019/11/12 18:38:28 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	show_menu(t_data *data)
{
	print_pipes(data, 0, 410, 400);
	print_pipes(data, 0, 410, 0);
	mlx_string_put(data->mlx_ptr,
				data->win_ptr, 20, 10, 0xffffff, "Press [C] -> Change Colors");
	mlx_string_put(data->mlx_ptr,
			data->win_ptr, 20, 50,
			0xffffff, "Press [T] -> For Parallel Projection");
	mlx_string_put(data->mlx_ptr,
			data->win_ptr, 20, 100,
			0xffffff, "Press [R] -> For Isometric Projection");
	mlx_string_put(data->mlx_ptr,
			data->win_ptr, 20, 150, 0xffffff, "Press [UP] -> Move up");
	mlx_string_put(data->mlx_ptr,
			data->win_ptr, 20, 200, 0xffffff, "Press [Down] -> Move Down");
	mlx_string_put(data->mlx_ptr,
			data->win_ptr, 20, 250, 0xffffff, "Press [left] -> Move Left");
	mlx_string_put(data->mlx_ptr,
			data->win_ptr, 20, 300, 0xffffff, "Press [Right] -> Move Right");
	mlx_string_put(data->mlx_ptr,
			data->win_ptr, 20, 350, 0xffffff, "Press [M] -> Return To MENU");
	mlx_string_put(data->mlx_ptr,
			data->win_ptr, 20, 400, 0xff0000, "Press [ESC] -> Exit");
}

void	menu_(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	show_menu(data);
}

void	print_pipes(t_data *data, int i, int j, int pos)
{
	while (i < j)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, pos, i, 0x0052D4, "|");
		i = i + 5;
	}
}
