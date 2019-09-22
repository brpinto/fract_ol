/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 19:33:21 by brounch           #+#    #+#             */
/*   Updated: 2019/06/03 15:06:57 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		mouse_move(int x, int y, t_env *env)
{
	if (env->fctl.move == 1 && env->fractal == julia)
	{
		env->cam.pos_x = (x * (env->coords.x2 - env->coords.x1)
			/ WIN_WIDTH + env->coords.x1);
		env->cam.pos_y = (y * (env->coords.y2 - env->coords.y1)
			/ WIN_HEIGHT + env->coords.y1);
		display_fract(env);
	}
	return (0);
}
