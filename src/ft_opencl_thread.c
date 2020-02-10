#include "../includes/fractol.h"


// void	*thread_mandelbrota(void *function)
// {
// 	double	c_re;
// 	double	c_im;
// 	double	zoom;
// 	int		speed;
// 	int		color;
// 	t_data	*data;

// 	data = (t_data *)function;
// 	zoom = data->delta_x_re / WIDHT;
// 	while (data->y_start < data->y_end)
// 	{
// 		data->x = 0;
// 		while (data->x < WIDHT)
// 		{
// 			c_re = data->x_re_min + data->x * zoom;
// 			c_im = data->y_im_max - data->y_start * zoom;
// 			speed = ft_complex_number_check(c_re, c_im);
// 			if (speed == NUM)
// 				color = 0x0;
// 			else
// 				// color = ft_pixel_color_alfa(speed);
// 				color = mlx_get_color_value(data->mlx_ptr, speed * data->color);
// 			data->draw_t[0][data->x + data->y_start * WIDHT] = color;
// 			data->x += 1;
// 		}
// 		data->y_start += 1;
// 	}
// 	return (NULL);
// }

// void	ft_multi_thread_mandelbrota(t_fractol *p)
// {
// 		pthread_t	id[NUM_THREAD];
// 		t_data		data[NUM_THREAD];
// 		int			n;

// 		n = 0;
// 		while (n < NUM_THREAD)
// 		{
// 			data[n].y_start = n * HIGHT / NUM_THREAD;
// 			data[n].y_end = (n + 1) * HIGHT / NUM_THREAD;
// 			data[n].delta_x_re = p->delta_x_re;
// 			data[n].x_re_min = p->x_re_min;
// 			data[n].y_im_max = p->y_im_max;
// 			data[n].color = p->color;
// 			data[n].mlx_ptr = p->mlx_ptr;
// 			data[n].draw_t = &p->draw;
// 			pthread_create(&id[n], NULL, thread_mandelbrota, &data[n]);
// 			n += 1;
// 		}
// 		n = 0;
// 		while (n < NUM_THREAD)
// 		{
// 			pthread_join(id[n], NULL);
// 			n += 1;
// 		}
// }
