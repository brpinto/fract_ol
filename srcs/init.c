/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:27:53 by brpinto           #+#    #+#             */
/*   Updated: 2019/06/03 15:05:11 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static	void	init_cam(t_env *env)
{
	env->cam.scalex = WIN_WIDTH / (env->coords.x2 - env->coords.x1);
	env->cam.scaley = WIN_HEIGHT / (env->coords.y2 - env->coords.y1);
}

int				init_img(t_env *env)
{
	env->img.img_ptr = mlx_new_image(env->dis, WIN_WIDTH, WIN_HEIGHT);
	env->img.data = (unsigned char*)mlx_get_data_addr(env->img.img_ptr,
			&env->img.bpp, &env->img.size_l, &env->img.endian);
	env->cam.scalex = WIN_WIDTH / (env->coords.x2 - env->coords.x1);
	env->cam.scaley = WIN_HEIGHT / (env->coords.y2 - env->coords.y1);
	init_cam(env);
	return (0);
}

void			init_mlx(t_env *env)
{
	env->dis = mlx_init();
	env->win = mlx_new_window(env->dis, WIN_WIDTH, WIN_HEIGHT, "Fractol");
}

void			init_env(t_env *env, char *av)
{
	ft_bzero(env, sizeof(t_env *));
	env->fctl.move = 0;
	env->cam.sat = 0;
	if (ft_strcmp(av, "mandelbrot") == 0)
		init_mandelbrot(env);
	else if (ft_strcmp(av, "julia") == 0)
		init_julia(env);
	else if (ft_strcmp(av, "burning") == 0)
		init_burning(env);
	if (!env->fractal)
		error_msg();
}
