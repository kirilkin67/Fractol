#include "../includes/fractol.h"

void	ft_parametr_julia(t_fractol *p)
{
	p->width = WIDHT;
	p->hight = HIGHT;
	p->c_re = -0.70176;
	p->c_im = -0.3842;
	p->x_re_min = -1.5;
	p->y_im_max = 1;
	p->delta_x_re = 3;
	p->num = NUM;
	p->color = COLOR;
	p->flag = 2;
	p->flag_color = 1;
	p->mouse_key = -1;
}

int		ft_pixel_number_check(void *p, double new_re, double new_im)
{
	t_data	*data;
	double	tmp;
	double	z_re;
	double	z_im;
	double	orbit;

	data = (t_data *)p;
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

// void	ft_fractal_julia(t_fractol *p)
// {
// 	int		speed;
// 	int		color;
// 	double	zoom;
// 	int x;
// 	int y;

// 	zoom = p->delta_x_re / p->width;
// 	y = 0;
// 	while (y < p->hight)
// 	{
// 		x = 0;
// 		while (x < p->width)
// 		{
// 			p->new_re = p->x_re_min + (double)x * zoom;
// 			p->new_im = p->y_im_max - (double)y * zoom;
// 			speed = ft_pixel_number_check(p, p->new_re, p->new_im);
// 			color = ft_pixel_color_alfa(speed);
// 			// color = mlx_get_color_value(p->mlx_ptr, speed * p->color);
// 			p->draw[x + y * WIDHT] = color;
// 			x += 1;
// 		}
// 		y += 1;
// 	}
// }

void	*thread_julia(void *function)
{
	int		speed;
	int		color;
	double	zoom;
	t_data	*data;

	data = (t_data *)function;
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
				color = mlx_get_color_value(data->mlx_ptr, speed * data->color);
			data->draw_t[0][data->x + data->y_start * WIDHT] = color;
			data->x += 1;
		}
		data->y_start += 1;
	}
	return (NULL);
}

void	ft_multi_thread_julia(t_fractol *p)
{
	pthread_t	id[NUM_THREAD];
	t_data		data[NUM_THREAD];
	int			n;

	n = 0;
	while (n < NUM_THREAD)
	{
		data[n].y_start = n * HIGHT / NUM_THREAD;
		data[n].y_end = (n + 1) * HIGHT / NUM_THREAD;
		data[n].c_re = p->c_re;
		data[n].c_im = p->c_im;
		data[n].delta_x_re = p->delta_x_re;
		data[n].x_re_min = p->x_re_min;
		data[n].y_im_max = p->y_im_max;
		data[n].num = p->num;
		data[n].color = p->color;
		data[n].flag_color = p->flag_color;
		data[n].mlx_ptr = p->mlx_ptr;
		data[n].draw_t = &p->draw;
		pthread_create(&id[n], NULL, thread_julia, &data[n]);
		n += 1;
	}
	while (n-- > 0)
		pthread_join(id[n], NULL);
}
