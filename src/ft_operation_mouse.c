#include "../includes/fractol.h"

void	zoom_mouse(int key, t_fractol *p)
{
	double	delta_y;
	double	tmp;
	double	k_wind;

	p->alfa_x = (double)p->mouse_x / (double)(WIDHT - 1);
	p->alfa_y = (double)p->mouse_y / (double)(HIGHT - 1);
	tmp = p->delta_x_re;
	k_wind = (double)WIDHT / (double)HIGHT;
	delta_y = tmp / k_wind;
	if (key == 4 || key == 1)
		p->delta_x_re /= K_ZOOM;
	else if ((key == 5 || key == 2) && p->x_re_min > -2)
		p->delta_x_re *= K_ZOOM;
	p->x_re_min += ((tmp - p->delta_x_re) * p->alfa_x);
	p->y_im_max -= ((delta_y - p->delta_x_re / k_wind) * p->alfa_y);
	ft_paint_image(p);
}

int		mouse_press(int button, int x, int y, t_fractol *p)
{
	if (y >= 0 && y <= (HIGHT - 1) && x >= 0 && x <= (WIDHT - 1))
	{
		if (p->type_fractal != 0 && \
		(button == 4 || button == 5 || button == 1 || button == 2))
		{
			if (p->mouse_key == 1)
			{
				p->mouse_x = x;
				p->mouse_y = y;
				zoom_mouse(button, p);
			}
		}
		if ((p->type_fractal == JULIA || p->type_fractal == SYMMETRY) && \
			button == 3)
		{
			if (p->mouse_key == -1)
				p->mouse_key = 1;
			else if (p->mouse_key == 1)
				p->mouse_key = -1;
		}
	}
	return (0);
}

int		mouse_movement(int x, int y, t_fractol *p)
{
	double widht;
	double hight;

	widht = WIDHT - 1;
	hight = HIGHT - 1;
	if (0 <= y && y <= hight && x >= 0 && x <= widht)
	{
		if ((p->type_fractal == JULIA || p->type_fractal == SYMMETRY) \
			&& p->mouse_key == -1)
		{
			p->const_re = (((double)x - widht / 2) / widht) * 2;
			p->const_im = (hight / 2 - (double)y) / hight;
			ft_paint_image(p);
		}
	}
	return (0);
}
