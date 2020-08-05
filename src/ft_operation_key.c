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
		p->color_function = 1;
	else if (key == KEY_W)
		p->color_function = 2;
	if (key == KEY_R)
		p->color += 3000;
	else if (key == KEY_E && p->color > 10000)
		p->color -= 2000;
	fractal_type_image_selection(p);
}

void	iteration_key(int key, t_fractol *p)
{
	if (key == NUM_KEY_PLUS && p->num_iter < 1000)
		p->num_iter += 20;
	if (key == NUM_KEY_MINUS && p->num_iter > 40)
		p->num_iter -= 20;
	fractal_type_image_selection(p);
}

void	shift_key(int key, t_fractol *p)
{
	if (key == KEY_LEFT)
		p->x_re_min += 30 * p->delta_x_re / WIDHT;
	else if (key == KEY_RIGHT)
		p->x_re_min -= 30 * p->delta_x_re / WIDHT;
	else if (key == KEY_DOWN)
		p->y_im_max += 30 * p->delta_x_re / WIDHT;
	else if (key == KEY_UP)
		p->y_im_max -= 30 * p->delta_x_re / WIDHT;
	fractal_type_image_selection(p);
}

int		key_press(int key, t_fractol *p)
{
	if (key == KEY_ESC)
		exit(0);
	if ((key == KEY_PLUS || key == KEY_MINUS) && p->type_fractal == 0)
		zoom_key(key, p);
	if (key == KEY_Q || key == KEY_W || key == KEY_E || key == KEY_R)
		color_key(key, p);
	if (key == NUM_KEY_PLUS || key == NUM_KEY_MINUS)
		iteration_key(key, p);
	if (key == KEY_DOWN || key == KEY_UP || key == KEY_LEFT || key == KEY_RIGHT)
		shift_key(key, p);
	if ((key == KEY_SPACE || key == KEY_J || key == KEY_M || key == KEY_S) \
		&& p->type_fractal != 0)
	{
		if ((p->type_fractal == MANDELBROT && key == KEY_SPACE) || key == KEY_M)
			ft_parametr_mandelbrota(p);
		if ((p->type_fractal == JULIA && key == KEY_SPACE) || key == KEY_J)
			ft_parametr_julia(p);
		if ((p->type_fractal == SYMMETRY && key == KEY_SPACE) || key == KEY_S)
		{
			ft_parametr_julia(p);
			p->type_fractal = SYMMETRY;
		}
		fractal_type_image_selection(p);
	}
	return (0);
}
