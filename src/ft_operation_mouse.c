#include "../includes/fractol.h"

static void	zoom_mouse(int key, t_fractol *p)
{
	double delta_y;
	double tmp;
	double k_wind;
	
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
	if (p->flag == 1)
		ft_paint_mandelbrota(p);
	if (p->flag == 2)
		ft_paint_julia(p);
	if (p->flag == 3)
		ft_paint_symmetry(p);
}

int		mouse_press(int button, int x, int y, t_fractol *p)
{
	if (y >= 0 && y <= (HIGHT - 1) && x >= 0 && x <= (WIDHT - 1))
	{
		if (p->flag != 0 && (button == 4 || button == 5 || button == 1 || button == 2))
		{
			if (p->mouse_key == 1)
			{
			p->mouse_x = x;
			p->mouse_y = y;
			zoom_mouse(button, p);
			}
		}
		if ((p->flag == 2 || p->flag == 3) && button == 3)
			p->mouse_key = 1;
	}
	return (0);
}

int		mouse_movement(int x, int y, t_fractol *p)
{
	if (y >= 0 && y <= (HIGHT - 1) && x >= 0 && x <= (WIDHT - 1))
	{
		if ((p->flag == 2 || p->flag == 3) && p->mouse_key == -1)
		{
			p->c_re = (double)(x - (WIDHT - 1)/2) / (double)(WIDHT - 1) * 2;
			p->c_im = (double)((HIGHT - 1)/2 - y) / (double)(HIGHT - 1);
			if (p->flag == 2)
				ft_paint_julia(p);
			else
				ft_paint_symmetry(p);
		}
	}
	return (0);
}