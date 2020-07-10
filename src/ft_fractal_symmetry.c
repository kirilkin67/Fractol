#include "fractol.h"

int		ft_symmetry_number_check(t_fractol *data, double new_re, double new_im)
{
	double	tmp;
	double	z_re;
	double	z_im;
	double	orbit;

	z_re = new_re;
	z_im = new_im;
	orbit = new_re * new_re + new_im * new_im;
	data->n = 0;
	while (data->n < data->num && orbit <= 4)
	{
		tmp = z_re;
		z_re = z_re * z_re - z_im * z_im + data->c_re;
		z_im = 2 * tmp * ABS(z_im) + data->c_im;
		orbit = z_re * z_re + z_im * z_im;
		data->n += 1;
	}
	return (data->n);
}

void	*thread_symmetry(void *function)
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
			data->new_re = data->x_re_min + data->x * zoom;
			data->new_im = data->y_im_max - data->y_start * zoom;
			speed = ft_symmetry_number_check(data, data->new_re, data->new_im);
			if (data->flag_color == 1)
				color = ft_pixel_color_alfa(data->num, speed);
			else
				color = ft_pixel_color_betta(data, data->num, speed);
			data->draw[data->x + data->y_start * WIDHT] = color;
			data->x += 1;
		}
		data->y_start += 1;
	}
	return (NULL);
}

void	ft_multi_thread_symmetry(t_fractol *paint)
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
		pthread_create(&id[n], NULL, thread_symmetry, &data[n]);
		n += 1;
	}
	while (n--)
		pthread_join(id[n], NULL);
}

void	ft_paint_symmetry(t_fractol *p)
{
	
	// ft_parametr_julia(p);
	// p->flag = 3;
	ft_multi_thread_symmetry(p);
	expose_hook(p);
	// ft_operation(p);
}
