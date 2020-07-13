#include "../includes/fractol.h"

void	zoom_key(int key, t_fractol *p)
{
	p->sign = (key == KEY_MINUS) ? -1 : 1;
	if ((p->side_w >= 20 && p->side_w <= MAX_ZOOM) || \
		(p->side_h >= 20 && p->side_h <= MAX_ZOOM))
	{
		p->side_w += (KZ_MAX * p->sign);
		p->side_h += (KZ_MAX * p->sign);
		p->x0 -= (KZ_MAX / 2 * p->sign);
		p->y0 -= (KZ_MAX / 2 * p->sign);
		p->k_look += (K_LOOK * p->sign);
		p->depth = DEPTH;
		ft_paint_rectangle(p);
	}
	else if ((p->side_w < 20 || p->side_h < 20) && key == KEY_PLUS)
	{
		p->side_w = 20;
		p->side_h = 20;
		p->x0 -= (KZ_MAX / 2 * p->sign);
		p->y0 -= (KZ_MAX / 2 * p->sign);
	}
	else if ((p->side_w > MAX_ZOOM || p->side_h > MAX_ZOOM) && key == KEY_MINUS)
	{
		p->side_w = MAX_ZOOM;
		p->side_h = MAX_ZOOM;
	}
}

void	color_key(int key, t_fractol *p)
{
	if (key == KEY_Q)
		p->flag_color = 1;
	else if (key == KEY_W)
		p->flag_color = 2;
	if (key == KEY_R)
		p->color += 3000;
	else if (key == KEY_E && p->color > 10000)
		p->color -= 2000;
	fractal_type_image_selection(p);
}

void	iteration_key(int key, t_fractol *p)
{
	if (key == NUM_KEY_PLUS && p->num < 1000)
		p->num += 20;
	if (key == NUM_KEY_MINUS && p->num > 40)
		p->num -= 20;
	fractal_type_image_selection(p);
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
	fractal_type_image_selection(p);
}

int		key_press(int key, t_fractol *p)
{
	if (key == KEY_ESC)
		exit(0);
	if ((key == 24 || key == 27) && p->type_fractal == 0)
		zoom_key(key, p);
	if (key == 12 || key == 13 || key == 14 || key == 15)
		color_key(key, p);
	if (key == 69 || key == 78)
		iteration_key(key, p);
	if (key == 125 || key == 126 || key == 123 || key == 124)
		shift_key(key, p);
	if ((key == 49 || key == KEY_J || key == KEY_M || key == KEY_S) && \
		p->type_fractal != 0)
	{
		if ((p->type_fractal == MANDELBROT && key == 49) || key == KEY_M)
			ft_parametr_mandelbrota(p);
		if ((p->type_fractal == JULIA && key == 49) || key == KEY_J)
			ft_parametr_julia(p);
		if ((p->type_fractal == SYMMETRY && key == 49) || key == KEY_S)
		{
			ft_parametr_julia(p);
			p->type_fractal = SYMMETRY;
		}
		fractal_type_image_selection(p);
	}
	return (0);
}
