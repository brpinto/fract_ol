/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:05:09 by brpinto           #+#    #+#             */
/*   Updated: 2019/06/03 15:00:36 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	*mandelbrot(void *thread)
{
	t_thread	*thd;
	int			ymax;
	int			y;
	int			x;

	thd = (t_thread *)thread;
	y = thd->id * (WIN_HEIGHT / THREADS);
	ymax = (thd->id + 1) * (WIN_HEIGHT / THREADS);
	x = 0;
	while (x < WIN_WIDTH)
	{
		y = thd->id * (WIN_HEIGHT / THREADS);
		thd->data.fctl.c_r = (x / thd->data.cam.scalex) + thd->data.coords.x1;
		mandel_calc(x, y, ymax, &thd->data);
		x++;
	}
	return (thread);
}

void	*julia(void *thread)
{
	t_thread	*thd;
	int			ymax;
	int			y;
	int			x;

	thd = (t_thread *)thread;
	y = thd->id * (WIN_HEIGHT / THREADS);
	ymax = (thd->id + 1) * (WIN_HEIGHT / THREADS);
	x = 0;
	while (x < WIN_WIDTH)
	{
		y = thd->id * (WIN_HEIGHT / THREADS);
		thd->data.fctl.c_r = thd->data.cam.pos_x;
		julia_calc(x, y, ymax, &thd->data);
		x++;
	}
	return (thread);
}

void	*burning(void *thread)
{
	t_thread	*thd;
	int			ymax;
	int			x;
	int			y;

	thd = (t_thread*)thread;
	y = thd->id * (WIN_HEIGHT / THREADS);
	ymax = (thd->id + 1) * (WIN_HEIGHT / THREADS);
	x = 0;
	while (x < WIN_WIDTH)
	{
		y = thd->id * (WIN_HEIGHT / THREADS);
		thd->data.fctl.c_r = (x / thd->data.cam.scalex) + thd->data.coords.x1;
		burning_calc(x, y, ymax, &thd->data);
		x++;
	}
	return (thread);
}
