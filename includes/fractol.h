/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:25:56 by brpinto           #+#    #+#             */
/*   Updated: 2019/06/03 17:00:38 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <libft.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# define THREADS 4

typedef	struct		s_cam
{
	int				sat;
	int				val;
	double			scalex;
	double			scaley;
	float			trans_x;
	float			trans_y;
	int				scroll_up;
	int				scroll_down;
	double			pos_x;
	double			pos_y;
}					t_cam;

typedef	struct		s_coords
{
	double			x;
	double			y;
	double			y1;
	double			x1;
	double			y2;
	double			x2;
	double			mouse_x;
	double			mouse_y;
}					t_coords;

typedef	struct		s_fctl
{
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	int				i_max;
	int				i;
	int				move;
}					t_fctl;

typedef	struct		s_img
{
	void			*img_ptr;
	unsigned char	*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef	struct		s_env
{
	void			*(*fractal)();
	void			*dis;
	void			*win;
	int				win_width;
	int				win_height;
	t_img			img;
	t_fctl			fctl;
	t_coords		coords;
	t_cam			cam;
}					t_env;

typedef	struct		s_thread
{
	int				id;
	t_env			data;
	pthread_t		thread;
}					t_thread;

int					ft_close(void *param);
void				error_msg(void);
void				init_env(t_env *env, char *av);
void				init_mlx(t_env *env);
int					init_img(t_env *env);
void				init_threads(t_env env);
void				init_mandelbrot(t_env *env);
void				init_julia(t_env *env);
void				init_burning(t_env *env);
void				*mandelbrot(void *env);
void				*julia(void *env);
void				*burning(void *env);
void				display_fract(t_env *env);
void				ft_put_pixel(t_env *data, int x, int y);
int					ft_key_press(int key, t_env *env);
int					mouse_press(int button, int x, int y, t_env *env);
int					mouse_move(int x, int y, t_env *env);
void				mandel_calc(int x, int y, int ymax, t_env *data);
void				julia_calc(int x, int y, int ymax, t_env *data);
void				burning_calc(int x, int y, int ymax, t_env *data);

#endif
