#include "../includes/fractol.h"

void	ft_parametr_mandelbrota(t_fractol *p)
{
	p->width = WIDHT;
	p->hight = HIGHT;
	p->x_re_min = -2;
	p->y_im_max = 1;
	p->delta_x_re = 3;
	p->num = NUM;
	p->color = COLOR;
	p->flag_color = 1;
	p->type_fractal = MANDELBROT;
	p->mouse_key = 1;
}

int		ft_mandelbrot_check(int num, double c_re, double c_im)
{
	double	tmp;
	double	z_re;
	double	z_im;
	double	orbit;
	int		iter;

	z_re = c_re;
	z_im = c_im;
	orbit = c_re * c_re + c_im * c_im;
	iter = 0;
	while (iter < num && orbit <= 4)
	{
		tmp = z_re;
		z_re = z_re * z_re - z_im * z_im + c_re;
		z_im = 2 * tmp * z_im + c_im;
		orbit = z_re * z_re + z_im * z_im;
		iter += 1;
	}
	return (iter);
}

// void	*thread_mandelbrota(void *function)
// {
// 	int			speed;
// 	int			color;
// 	double		zoom;
// 	t_fractol	*data;

// 	data = (t_fractol *)function;
// 	zoom = data->delta_x_re / WIDHT;
// 	while (data->y_start < data->y_end)
// 	{
// 		data->x = 0;
// 		while (data->x < WIDHT)
// 		{
// 			data->c_re = data->x_re_min + data->x * zoom;
// 			data->c_im = data->y_im_max - data->y_start * zoom;
// 			speed = ft_mandelbrot_check(data->num,data->c_re, data->c_im);
//			color = function_color(data, speed);
// 			data->draw[data->x + data->y_start * WIDHT] = color;
// 			data->x += 1;
// 		}
// 		data->y_start += 1;
// 	}
// 	return (NULL);
// }

// void	ft_multi_thread_mandelbrota(t_fractol *paint)
// {
// 	pthread_t	id[NUM_THREAD];
// 	t_fractol	data[NUM_THREAD];
// 	size_t		n;

// 	n = 0;
// 	while (n < NUM_THREAD)
// 	{
// 		data[n] = *paint;
// 		data[n].y_start = n * HIGHT / NUM_THREAD;
// 		data[n].y_end = (n + 1) * HIGHT / NUM_THREAD;
// 		pthread_create(&id[n], NULL, thread_mandelbrota, &data[n]);
// 		n += 1;
// 	}
// 	n = 0;
// 	while (n < NUM_THREAD)
// 	{
// 		pthread_join(id[n], NULL);
// 		n += 1;
// 	}
// }
