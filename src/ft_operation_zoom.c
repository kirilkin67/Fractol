#include "../includes/fractol.h"

// static void	alfa_x_y(t_fractol *p)
// {
// 	p->alfa_x = (double)p->mouse_x / (double)(WIDHT - 1);
// 	p->alfa_y = (double)p->mouse_y / (double)(HIGHT - 1);
// }


// static void	zoom_mouse(int key, t_fractol *p)
// {
// 	double delta_y;
// 	double tmp;
// 	double k_wind;
	
// 	p->alfa_x = (double)p->mouse_x / (double)(WIDHT - 1);
// 	p->alfa_y = (double)p->mouse_y / (double)(HIGHT - 1);
// 	tmp = p->delta_x_re;
// 	k_wind = (double)WIDHT / (double)HIGHT;
// 	delta_y = tmp / k_wind;
// 	if (key == 4)
// 		p->delta_x_re /= K_ZOOM;
// 	else if (key == 5 && p->x_re_min > -2)
// 		p->delta_x_re *= K_ZOOM;
// 	p->x_re_min += ((tmp - p->delta_x_re) * p->alfa_x);
// 	p->y_im_max -= ((delta_y - p->delta_x_re / k_wind) * p->alfa_y);
// 	ft_paint_mandelbrota(p);
// }
