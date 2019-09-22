/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:03:20 by brpinto           #+#    #+#             */
/*   Updated: 2019/06/03 14:15:13 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	display_fract(t_env *env)
{
	mlx_clear_window(env->dis, env->win);
	init_img(env);
	init_threads(*env);
	mlx_put_image_to_window(env->dis, env->win, env->img.img_ptr, 0, 0);
}
