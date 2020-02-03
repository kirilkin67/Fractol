#include "../includes/fractol.h"

int		close_endian(void *param)
{
	(void) param;
	exit(0);
}

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
	ft_paint_rectangle(p);
	}
	else if (key == 24)
	{
		p->side_w = 10;
		p->side_h = 10;
		p->x0 -= (KZ_MAX / 2 * sign);
		p->y0 -= (KZ_MAX / 2 * sign);
		ft_paint_rectangle(p);
	}
}

void	color_key(int key, t_fractol *p)
{
	if (key == 12)
		p->flag_color = 1;
	else if (key == 13)
		p->flag_color = 2;
	else if (key == 69)
		p->color += 3000;
	else if (key == 69 && p->color > 10000)
		p->color -= 2000;
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
	if (key == 12 || key == 13 || key == 69 || key == 78)
		color_key(key, p);
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
