/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:24:32 by brpinto           #+#    #+#             */
/*   Updated: 2019/06/03 14:14:36 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static	void	first_tier(t_env *data, int i_val, int pixel)
{
	data->img.data[pixel + 1] = (i_val * 255 / 120 + data->cam.sat) > 255 ?
		255 : (i_val * 255 / 120 + data->cam.sat);
	data->img.data[pixel + 2] = (255 - data->img.data[pixel + 1]
		+ data->cam.sat) > 255 ? 255 : (255 - data->img.data[pixel + 1]
			+ data->cam.sat);
	data->img.data[pixel] = (0 + data->cam.sat) > 255 ? 255
		: (0 + data->cam.sat);
}

static	void	second_tier(t_env *data, int i_val, int pixel)
{
	data->img.data[pixel + 2] = (0 + data->cam.sat)
		> 255 ? 255 : (0 + data->cam.sat);
	data->img.data[pixel] = ((i_val - 120) * 255 / 120 + data->cam.sat) > 255 ?
		255 : ((i_val - 120) * 255 / 120 + data->cam.sat);
	data->img.data[pixel + 1] = (255 - data->img.data[pixel] + data->cam.sat)
		> 255 ? 255 : (255 - data->img.data[pixel] + data->cam.sat);
}

static	void	third_tier(t_env *data, int i_val, int pixel)
{
	data->img.data[pixel + 2] = ((i_val - 240) * 255 / 120 + data->cam.sat)
		> 255 ? 255 : ((i_val - 240) * 255 / 120 + data->cam.sat);
	data->img.data[pixel] = (255 - data->img.data[pixel + 2]
		+ data->cam.sat) > 255 ? 255 : (255 - data->img.data[pixel + 2]
			+ data->cam.sat);
	data->img.data[pixel + 1] = (0 + data->cam.sat)
		> 255 ? 255 : (0 + data->cam.sat);
}

static void		get_color(t_env *data, int pixel)
{
	int i_val;

	i_val = (data->fctl.i * 360 / data->fctl.i_max) + data->cam.val;
	if (i_val < 0)
		i_val *= -1;
	while (i_val > 360)
		i_val -= 360;
	if (i_val < 120)
		first_tier(data, i_val, pixel);
	else if (i_val < 240)
		second_tier(data, i_val, pixel);
	else
		third_tier(data, i_val, pixel);
}

void			ft_put_pixel(t_env *data, int x, int y)
{
	int pixel;

	pixel = (4 * x) + (4 * WIN_WIDTH * y);
	if (x < WIN_WIDTH && x >= 0
			&& y < WIN_HEIGHT && y >= 0
			&& pixel < (4 * WIN_WIDTH * WIN_HEIGHT) && pixel >= 0)
	{
		if (data->fctl.i == data->fctl.i_max)
		{
			data->img.data[pixel] = 0;
			data->img.data[pixel + 1] = 0;
			data->img.data[pixel + 2] = 0;
		}
		else
			get_color(data, pixel);
	}
}
