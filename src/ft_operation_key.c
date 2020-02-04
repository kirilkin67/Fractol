#include "../includes/fractol.h"

void	zoom_key(int key, t_fractol *p)
{
	int sign;

	sign = (key == 27) ? -1 : 1;
	if (p->side_w >= 10 || p->side_h >= 10)
	{
	p->side_w += (KZ_MAX * sign);
	p->side_h += (KZ_MAX * sign);
	p->x0 -= (KZ_MAX / 2 * sign);
	p->y0 -= (KZ_MAX / 2 * sign);
	p->k_look += (K_LOOK  * sign);
	p->depth = DEPTH;
	}
	else if (key == 24)
	{
		p->side_w = 10;
		p->side_h = 10;
		p->x0 -= (KZ_MAX / 2 * sign);
		p->y0 -= (KZ_MAX / 2 * sign);
	}
	ft_paint_rectangle(p);
}

void	color_key(int key, t_fractol *p)
{
	if (key == 12)
		p->flag_color = 1;
	else if (key == 13)
		p->flag_color = 2;
	if (key == 15)
		p->color += 3000;
	else if (key == 14 && p->color > 10000)
		p->color -= 2000;
	if (p->flag == 1)
		ft_paint_mandelbrota(p);
	if (p->flag == 2)
		ft_paint_julia(p);
}

void	iteration_key(int key, t_fractol *p)
{
	if (key == 69 && p->num < 1000)
		p->num += 20;
	if (key == 78 && p->num > 40)
		p->num -= 20;
	if (p->flag == 1)
		ft_paint_mandelbrota(p);
	if (p->flag == 2)
		ft_paint_julia(p);
}

void	shift_key(int key, t_fractol *p)
{
	if (key == 123)
		p->x_re_min += 30 * p->delta_x_re / WIDHT;
	else if (key == 124)
		p->x_re_min -= 30 * p->delta_x_re / WIDHT;
	else if (key == 125)
		p->y_im_max += 30 * p->delta_x_re / WIDHT;
	else if (key == 126)
		p->y_im_max -= 30 * p->delta_x_re / WIDHT;
	if (p->flag == 1)
		ft_paint_mandelbrota(p);
	if (p->flag == 2)
		ft_paint_julia(p);
}

int		key_press(int key, t_fractol *p)
{
	if (key == 53)
		exit(0);
	if ((key == 24 || key == 27) && p->flag == 0)
		zoom_key(key, p);
	if (key == 12 || key == 13 || key == 14 || key == 15)
		color_key(key, p);
	if (key == 69 || key == 78)
		iteration_key(key, p);
	if (key == 125 || key == 126 || key == 123 || key == 124)
		shift_key(key, p); 
	if (key == 49)
	{
		if (p->flag == 1)
		{
			ft_parametr_mandelbrota(p);
			ft_paint_mandelbrota(p);
		}
		if (p->flag == 2)
		{
			ft_parametr_julia(p);
			ft_paint_julia(p);
		}
	}
	return (0);
}
