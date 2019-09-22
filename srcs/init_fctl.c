/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fctl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:38:30 by brpinto           #+#    #+#             */
/*   Updated: 2019/06/03 15:07:51 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	init_mandelbrot(t_env *env)
{
	env->fractal = mandelbrot;
	env->coords.x1 = -2;
	env->coords.x2 = 2;
	env->coords.y1 = -1.2;
	env->coords.y2 = 1.2;
	env->fctl.i_max = 20;
}

void	init_julia(t_env *env)
{
	env->fractal = julia;
	if (env->fctl.move == 0 && env->fractal == julia)
	{
		env->cam.pos_x = 0.285;
		env->cam.pos_y = 0.01;
	}
	env->coords.x1 = -1.8;
	env->coords.x2 = 1.8;
	env->coords.y1 = -1.2;
	env->coords.y2 = 1.2;
	env->fctl.i_max = 50;
}

void	init_burning(t_env *env)
{
	env->fractal = burning;
	env->coords.x1 = -2.5;
	env->coords.x2 = 1.5;
	env->coords.y1 = -1.8;
	env->coords.y2 = 1;
	env->fctl.i_max = 40;
}
