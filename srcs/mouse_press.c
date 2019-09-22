/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:45:12 by brpinto           #+#    #+#             */
/*   Updated: 2019/06/03 16:20:44 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void		zoom(t_env *env, int x, int y)
{
	env->coords.mouse_x = (x * (env->coords.x2 - env->coords.x1)
		/ WIN_WIDTH + env->coords.x1);
	env->coords.mouse_y = (y * (env->coords.y2 - env->coords.y1)
		/ WIN_HEIGHT + env->coords.y1);
	if (env->cam.scroll_down)
	{
		env->coords.x1 += (env->coords.mouse_x - env->coords.x1) / 10;
		env->coords.x2 -= (env->coords.x2 - env->coords.mouse_x) / 10;
		env->coords.y1 += (env->coords.mouse_y - env->coords.y1) / 10;
		env->coords.y2 -= (env->coords.y2 - env->coords.mouse_y) / 10;
		env->fctl.i_max += 1;
		env->cam.scroll_down = 0;
	}
	else if (env->cam.scroll_up)
	{
		env->coords.x1 -= (env->coords.mouse_x - env->coords.x1) / 10;
		env->coords.x2 += (env->coords.x2 - env->coords.mouse_x) / 10;
		env->coords.y1 -= (env->coords.mouse_y - env->coords.y1) / 10;
		env->coords.y2 += (env->coords.y2 - env->coords.mouse_y) / 10;
		env->fctl.i_max -= 1;
		env->cam.scroll_down = 0;
	}
}

int				mouse_press(int button, int x, int y, t_env *env)
{
	if (button == 4 || button == 5)
	{
		if (button == 4)
			env->cam.scroll_down = 1;
		else if (button == 5)
			env->cam.scroll_up = 1;
		zoom(env, x, y);
	}
	else if (button == 3 && env->fractal == julia)
		env->fctl.move = (env->fctl.move == 0) ? 1 : 0;
	display_fract(env);
	return (0);
}
