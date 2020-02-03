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
	else if (p->flag == 2)
		ft_paint_julia(p);
}

int		mouse_press(int button, int x, int y, t_fractol *p)
{
	if (y >= 0 && y <= (HIGHT - 1) && x >= 0 && x <= (WIDHT - 1))
	{
		if (p->flag != 0 && (button == 4 || button == 5 || button == 1 || button == 2)) // колесико scrol UP +, scroll DOWN -
		{
			if (p->mouse_key == 1)
			{
			p->mouse_x = x;
			p->mouse_y = y;
			zoom_mouse(button, p);
			}
		}
		if (p->flag == 2 && button == 3)
			p->mouse_key = 1;
	}
	// else if (button == 1 && (y >= 0 && y <= (HIGHT - 1)) && \
	// 		(x >= 0 && x <= (WIDHT - 1)))
	// 	p->mouse_key = 1;
	return (0);
}

// int		mouse_release(int button, int x, int y, t_fractol *p)
// {
// 	(void)x;
// 	(void)y;
// 	(void)button;
// 	p->mouse_key = -1;
// 	return (0); 
// }

int		mouse_movement(int x, int y, t_fractol *p)
{
	// int		x1;
	// int		y1;

	// x1 = p->mouse_x;
	// y1 = p->mouse_y;
	// p->mouse_x = x;
	// p->mouse_y = y;
	if (y >= 0 && y <= (HIGHT - 1) && x >= 0 && x <= (WIDHT - 1))
	{
		if (p->flag == 2 && p->mouse_key == -1)
		{
			p->c_re = -0.8 + (double)x / (double)(WIDHT - 1) / 4;
			p->c_im = 0.6 - (double)y / (double)(HIGHT - 1) / 2;
			ft_paint_julia(p);
		}
	// if (p->mouse_key == 1)
	// {
	// 	p->x0 += (x - x1);
	// 	p->y0 += (y - y1);
	// 	if (p->mouse_key == 1)
	// 		ft_paint_mandelbrota(p);
	// }
	}
	return (0);
}