#include "../includes/fractol.h"

void	ft_parametr_julia(t_fractol *p)
{
	p->width = WIDHT;
	p->hight = HIGHT;
	p->const_re = 0.285;
	p->const_im = 0.01;
	p->x_re_min = -1.5;
	p->y_im_max = 1;
	p->delta_x_re = 3;
	p->num = NUM;
	p->color = COLOR;
	p->type_fractal = JULIA;
	p->color_function = 1;
	p->mouse_key = -1;
}

int		ft_julia_check(t_fractol *data, double c_re, double c_im)
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
	while (iter < data->num && orbit <= 4)
	{
		tmp = z_re;
		z_re = z_re * z_re - z_im * z_im + data->const_re;
		z_im = 2 * tmp * z_im + data->const_im;
		orbit = z_re * z_re + z_im * z_im;
		iter += 1;
	}
	return (iter);
}
