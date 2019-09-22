/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:30:06 by brpinto           #+#    #+#             */
/*   Updated: 2019/06/03 16:32:36 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static	void	reset(t_env *env)
{
	if (env->fractal == mandelbrot)
		init_mandelbrot(env);
	else if (env->fractal == julia)
		init_julia(env);
	else if (env->fractal == burning)
		init_burning(env);
	env->cam.sat = 0;
	env->cam.val = 0;
}

static	void	change_fractal(int key, t_env *env)
{
	if (key == 18)
		env->fractal = mandelbrot;
	else if (key == 19)
		env->fractal = julia;
	else if (key == 20)
		env->fractal = burning;
	reset(env);
}

static	void	manage_color(int key, t_env *env)
{
	if (key == 69)
		env->cam.val += 3;
	else if (key == 126)
		env->cam.sat++;
	else if (key == 125)
		env->cam.sat--;
}

static	void	manage_translate(int key, t_env *env)
{
	env->cam.trans_x = (env->coords.x2 - env->coords.x1) * 0.1;
	env->cam.trans_y = (env->coords.y2 - env->coords.y1) * 0.1;
	if (key == 13)
	{
		env->coords.y2 += env->cam.trans_y;
		env->coords.y1 += env->cam.trans_y;
	}
	else if (key == 1)
	{
		env->coords.y2 -= env->cam.trans_y;
		env->coords.y1 -= env->cam.trans_y;
	}
	else if (key == 2)
	{
		env->coords.x2 -= env->cam.trans_x;
		env->coords.x1 -= env->cam.trans_x;
	}
	else if (key == 0)
	{
		env->coords.x2 += env->cam.trans_x;
		env->coords.x1 += env->cam.trans_x;
	}
}

int				ft_key_press(int key, t_env *env)
{
	if (key == 53)
		exit(0);
	else if (key == 13 || key == 1 || key == 0 || key == 2)
		manage_translate(key, env);
	else if (key == 69 || key == 126 || key == 125)
		manage_color(key, env);
	else if (key == 15)
		reset(env);
	else if (key == 18 || key == 19 || key == 20)
		change_fractal(key, env);
	display_fract(env);
	return (0);
}
