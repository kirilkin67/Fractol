#include "../includes/fractol.h"

int		ft_complex_number_check(t_fractol *data, double c_re, double c_im)
{
	int speed;

	if (data->type_fractal == MANDELBROT)
		speed = ft_mandelbrot_check(data->num, c_re, c_im);
	if (data->type_fractal == JULIA)
		speed = ft_julia_check(data, c_re, c_im);
	if (data->type_fractal == SYMMETRY)
		speed = ft_symmetry_check(data, c_re, c_im);
	return (speed);
}

void	*thread_function(void *function)
{
	int			speed;
	int			color;
	double		zoom;
	t_fractol	*data;

	data = (t_fractol *)function;
	zoom = data->delta_x_re / WIDHT;
	while (data->y_start < data->y_end)
	{
		data->x = 0;
		while (data->x < WIDHT)
		{
			data->c_re = data->x_re_min + data->x * zoom;
			data->c_im = data->y_im_max - data->y_start * zoom;
			speed = ft_complex_number_check(data, data->c_re, data->c_im);
			color = function_color(data, speed);
			data->draw[data->x + data->y_start * WIDHT] = color;
			data->x += 1;
		}
		data->y_start += 1;
	}
	return (NULL);
}

void	ft_multi_thread(t_fractol *paint)
{
	pthread_t	id[NUM_THREAD];
	t_fractol	data[NUM_THREAD];
	size_t		n;

	n = 0;
	while (n < NUM_THREAD)
	{
		data[n] = *paint;
		data[n].y_start = n * HIGHT / NUM_THREAD;
		data[n].y_end = (n + 1) * HIGHT / NUM_THREAD;
		pthread_create(&id[n], NULL, thread_function, &data[n]);
		n += 1;
	}
	n = 0;
	while (n < NUM_THREAD)
	{
		pthread_join(id[n], NULL);
		n += 1;
	}
}