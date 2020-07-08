#include "../includes/fractol.h"

void	ft_parametr_julia(t_fractol *p)
{
	p->width = WIDHT;
	p->hight = HIGHT;
	p->c_re = 0.285;
	p->c_im = 0.01;
	p->x_re_min = -1.5;
	p->y_im_max = 1;
	p->delta_x_re = 3;
	p->num = NUM;
	p->color = COLOR;
	p->flag = 2;
	p->flag_color = 1;
	p->mouse_key = -1;
}

int		ft_pixel_number_check(t_fractol *data, double new_re, double new_im)
{
	double	tmp;
	double	z_re;
	double	z_im;
	double	orbit;

	z_re = new_re;
	z_im = new_im;
	orbit = pow(new_re, 2) + pow(new_im, 2);
	data->n = 0;
	while (data->n < data->num && orbit <= 4)
	{
		tmp = z_re;
		z_re = z_re * z_re - z_im * z_im + data->c_re;
		z_im = 2 * tmp * z_im + data->c_im;
		orbit = z_re * z_re + z_im * z_im;
		data->n += 1;
	}
	return (data->n);
}

void	*thread_julia(void *function)
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
			speed = ft_pixel_number_check(data, data->new_re, data->new_im);
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

void	ft_multi_thread_julia(t_fractol *paint)
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
		pthread_create(&id[n], NULL, thread_julia, &data[n]);
		n += 1;
	}
	while (n--)
		pthread_join(id[n], NULL);
}
