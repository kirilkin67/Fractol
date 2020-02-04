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
	p->flag = 1;
	p->mouse_key = 1;
}

int		ft_complex_number_check(int num, double c_re, double c_im)
{
	double	tmp;
	double	z_re;
	double	z_im;
	double	orbit;
	int		n;

	z_re = c_re;
	z_im = c_im;
	orbit = c_re * c_re + c_im * c_im;
	n = 0;
	while (n < num && orbit <= 4)
	{
		tmp = z_re;
		z_re = z_re * z_re - z_im * z_im + c_re;
		z_im = 2 * tmp * z_im + c_im;
		orbit = z_re * z_re + z_im * z_im;
		n += 1;
	}
	return (n);
}

void	ft_fractal_mandelbrota(t_fractol *p)
{
	double	zoom;
	int		speed;
	int		color;
	int		x;
	int		y;

	zoom = p->delta_x_re / p->width;
	y = 0;
	while (y < p->hight)
	{
		x = 0;
		while (x < p->width)
		{
			p->c_re = p->x_re_min + x * zoom;
			p->c_im = p->y_im_max - y * zoom;
			speed = ft_complex_number_check(p->num ,p->c_re, p->c_im);
			if (speed == NUM)
				p->color = 0x0;
			else
				// color = ft_pixel_color_alfa(speed);
				color = mlx_get_color_value(p->mlx_ptr, speed * COLOR);
			p->draw[x + y * WIDHT] = color;
			x += 1;
		}
		y += 1;
	}
}

void	*thread_mandelbrota(void *function)
{
	int		speed;
	int		color;
	t_data	*data;

	data = (t_data *)function;
	data->zoom = data->delta_x_re / WIDHT;
	while (data->y_start < data->y_end)
	{
		data->x = 0;
		while (data->x < WIDHT)
		{
			data->c_re = data->x_re_min + data->x * data->zoom;
			data->c_im = data->y_im_max - data->y_start * data->zoom;
			speed = ft_complex_number_check(data->num,data->c_re, data->c_im);
			if (data->flag_color == 1)
				color = ft_pixel_color_alfa(data->num, speed);
			else if (data->flag_color == 2)
				color = mlx_get_color_value(data->mlx_ptr, speed * data->color);
			data->draw_t[0][data->x + data->y_start * WIDHT] = color;
			data->x += 1;
		}
		data->y_start += 1;
	}
	return (NULL);
}

void	ft_multi_thread_mandelbrota(t_fractol *p)
{
	pthread_t	id[NUM_THREAD];
	t_data		data[NUM_THREAD];
	int			n;

	n = 0;
	while (n < NUM_THREAD)
	{
		data[n].y_start = n * HIGHT / NUM_THREAD;
		data[n].y_end = (n + 1) * HIGHT / NUM_THREAD;
		data[n].delta_x_re = p->delta_x_re;
		data[n].x_re_min = p->x_re_min;
		data[n].y_im_max = p->y_im_max;
		data[n].num = p->num;
		data[n].color = p->color;
		data[n].flag_color = p->flag_color;
		data[n].mlx_ptr = p->mlx_ptr;
		data[n].draw_t = &p->draw;
		pthread_create(&id[n], NULL, thread_mandelbrota, &data[n]);
		n += 1;
	}
	n = 0;
	while (n < NUM_THREAD)
	{
		pthread_join(id[n], NULL);
		n += 1;
	}
}
