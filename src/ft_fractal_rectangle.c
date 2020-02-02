#include "../includes/fractol.h"

void	ft_parametr_rectangle(t_fractol *p, char *s1, char *s2)
{
	p->side_w = ft_atoi(s1);
	p->side_h = ft_atoi(s2);
	// p->side_z = paint.side_w;
	p->width = p->side_w + 200;
	p->hight = p->side_h + 200;
	p->x0 = 100;
	p->y0 = 100;
	p->depth = DEPTH;
	p->alfa = ALFA;
	p->flag = 0;
}

void	ft_point_coordinates(t_fractol *p)
{
	int n;
	int x;
	int y;
	int x0 = p->width / 2;
	int y0 = p->hight / 2;

	n = 0;
	while (n < 4)
	{
		p->rectangle[n][0] = p->x0 + n % 2 * p->side_w;
		p->rectangle[n][1] = p->y0 + n / 2 * p->side_h;
		x = p->rectangle[n][0];
		y = p->rectangle[n][1];
	p->rectangle[n][0] = x0 + (x-x0) * cos(p->k_look) - (y-y0) * sin(p->k_look);
	p->rectangle[n][1] = y0 + (y-y0) * cos(p->k_look) + (x-x0) * sin(p->k_look);
		n += 1;
	}
}

static void	next_point_coordinates(int *dot, int *p1, int *p2, double alfa)
{
	dot[0] = p1[0] * (1 - alfa) + p2[0] * alfa;
	dot[1] = p1[1] * (1 - alfa) + p2[1] * alfa;
}

static void	draw_rectangle(t_fractol *p, int rectangle[4][2])
{
	ft_drawing_line(p, rectangle[0], rectangle[1]);
	ft_drawing_line(p, rectangle[1], rectangle[3]);
	ft_drawing_line(p, rectangle[3], rectangle[2]);
	ft_drawing_line(p, rectangle[2], rectangle[0]);
}

void		ft_fractal_rectangle(t_fractol *p, int rectangle[4][2])
{
	int tmp[4][2];

	if (p->depth < 1)
		return ;
	draw_rectangle(p, rectangle);
	next_point_coordinates(tmp[0], rectangle[0], rectangle[1], p->alfa);
	next_point_coordinates(tmp[1], rectangle[1], rectangle[3], p->alfa);
	next_point_coordinates(tmp[2], rectangle[2], rectangle[0], p->alfa);
	next_point_coordinates(tmp[3], rectangle[3], rectangle[2], p->alfa);
	p->depth -= 1;
	ft_fractal_rectangle(p, tmp);
}
