/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:42:28 by brpinto           #+#    #+#             */
/*   Updated: 2019/06/03 15:07:36 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	main(int ac, char **av)
{
	t_env env;

	if (ac != 2)
		error_msg();
	init_env(&env, av[1]);
	init_mlx(&env);
	display_fract(&env);
	mlx_hook(env.win, 2, 0, ft_key_press, (void*)&env);
	mlx_hook(env.win, 17, 0, ft_close, (void *)&env);
	mlx_hook(env.win, 4, 0, mouse_press, (void *)&env);
	mlx_hook(env.win, 6, 0, mouse_move, (void *)&env);
	mlx_loop(env.dis);
	return (0);
}
