#include "../includes/fractol.h"

void	ft_parametr_julia(t_fractol *p)
{
		p->width = WIDHT;
		p->hight = HIGHT;
		p->c_re = -0.8;
		p->c_im = 0.156;
		p->x_re_min = -1.5;
		p->y_im_max = 1;
		p->delta_x_re = 3;
		p->x0 = WIDHT / 2;
		p->y0 = HIGHT / 2;
		p->color = COLOR;
		p->flag = 2;
}

int		ft_pixel_number_check(t_fractol *p, double new_re, double new_im)
{
	double	tmp;
	double	z_re;
	double	z_im;
	double	orbit;
	int		n;

	z_re = new_re;
	z_im = new_im;
	orbit = pow(new_re, 2) + pow(new_im, 2);
	n = 0;
	while (n < NUM && orbit <= 4)
	{
		tmp = z_re;
		z_re = z_re * z_re - z_im * z_im + p->c_re;
		z_im = 2 * tmp * z_im + p->c_im;
		orbit = z_re * z_re + z_im * z_im;
		n += 1;
	}
	return (n);
}

void	ft_fractal_julia(t_fractol *p)
{
	double	new_re;
	double	new_im;
	int		speed;
	int		color;
	int x;
	int y;

	p->zoom = p->delta_x_re / p->width;
	y = 0;
	while (y < p->hight)
	{
		x = 0;
		while (x < p->width)
		{
			new_re = p->x_re_min + (double)x * p->zoom;
			new_im = p->y_im_max - (double)y * p->zoom;

			speed = ft_pixel_number_check(p, new_re, new_im);
			color = ft_pixel_color_alfa(speed);
				// color = mlx_get_color_value(p->mlx_ptr, speed * p->color);
			p->draw[x + y * WIDHT] = color;
			x += 1;
		}
		y += 1;
	}
}