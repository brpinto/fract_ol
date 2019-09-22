/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:44:55 by brpinto           #+#    #+#             */
/*   Updated: 2019/06/03 15:03:51 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	mandel_calc(int x, int y, int ymax, t_env *data)
{
	double tmp;

	while (y < ymax)
	{
		data->fctl.c_i = (y / data->cam.scaley) + data->coords.y1;
		data->fctl.z_r = 0;
		data->fctl.z_i = 0;
		data->fctl.i = 0;
		while (((data->fctl.z_r * data->fctl.z_r + data->fctl.z_i
				* data->fctl.z_i) < 4) && data->fctl.i < data->fctl.i_max)
		{
			tmp = data->fctl.z_r;
			data->fctl.z_r = data->fctl.z_r * data->fctl.z_r - data->fctl.z_i
				* data->fctl.z_i + data->fctl.c_r;
			data->fctl.z_i = 2 * data->fctl.z_i * tmp + data->fctl.c_i;
			data->fctl.i++;
		}
		ft_put_pixel(data, x, y);
		y++;
	}
}

void	julia_calc(int x, int y, int ymax, t_env *data)
{
	double tmp;

	while (y < ymax)
	{
		data->fctl.c_i = data->cam.pos_y;
		data->fctl.z_r = (x / data->cam.scalex) + data->coords.x1;
		data->fctl.z_i = (y / data->cam.scaley) + data->coords.y1;
		data->fctl.i = 0;
		while (((data->fctl.z_r * data->fctl.z_r + data->fctl.z_i
				* data->fctl.z_i) < 4) && data->fctl.i < data->fctl.i_max)
		{
			tmp = data->fctl.z_r;
			data->fctl.z_r = data->fctl.z_r * data->fctl.z_r - data->fctl.z_i
				* data->fctl.z_i + data->fctl.c_r;
			data->fctl.z_i = 2 * data->fctl.z_i * tmp + data->fctl.c_i;
			data->fctl.i++;
		}
		ft_put_pixel(data, x, y);
		y++;
	}
}

void	burning_calc(int x, int y, int ymax, t_env *data)
{
	double tmp;

	while (y < ymax)
	{
		data->fctl.c_i = (y / data->cam.scaley) + data->coords.y1;
		data->fctl.z_r = 0;
		data->fctl.z_i = 0;
		data->fctl.i = 0;
		while (((data->fctl.z_r * data->fctl.z_r + data->fctl.z_i
				* data->fctl.z_i) < 4) && data->fctl.i < data->fctl.i_max)
		{
			tmp = data->fctl.z_r * data->fctl.z_r - data->fctl.z_i
				* data->fctl.z_i + data->fctl.c_r;
			data->fctl.z_i = fabs(2 * data->fctl.z_i * data->fctl.z_r)
				+ data->fctl.c_i;
			data->fctl.z_r = fabs(tmp);
			data->fctl.i++;
		}
		ft_put_pixel(data, x, y);
		y++;
	}
}
