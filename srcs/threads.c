/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:20:02 by brpinto           #+#    #+#             */
/*   Updated: 2019/05/28 18:12:26 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	init_threads(t_env env)
{
	t_thread	threads[THREADS];
	int			i;

	i = 0;
	while (i < THREADS)
	{
		threads[i].id = i;
		threads[i].data = env;
		pthread_create(&threads[i].thread, NULL, env.fractal, &threads[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(threads[i++].thread, NULL);
	}
}
