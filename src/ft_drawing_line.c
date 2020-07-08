#include "../includes/fractol.h"

void		ft_drawing_fon(t_fractol *p)
{
	int	x;
	int	y;

	y = 0;
	while (y < (p->hight - 1))
	{
		x = 0;
		while (x < (p->width - 1))
		{
			p->draw[x + y * p->width] = COLOR_FON;
			x += 1;
		}
		y += 1;
	}
}

static void	drawing_data(t_draw *data, int *dot1, int *dot2)
{
	data->deltax = ABS((dot2[0] - dot1[0]));
	data->deltay = ABS((dot2[1] - dot1[1]));
	data->step = (data->deltax >= data->deltay) ? data->deltax : data->deltay;
	data->sign_x = dot1[0] < dot2[0] ? 1 : -1;
	data->sign_y = dot1[1] < dot2[1] ? 1 : -1;
	data->error = data->deltax - data->deltay;
	data->tmp[0] = dot1[0];
	data->tmp[1] = dot1[1];
}

void	ft_drawing_line(t_fractol *p, int *dot1, int *dot2)
{
	t_draw data;

	drawing_data(&data, dot1, dot2);
	data.n = 0;
	while (data.tmp[0] != dot2[0] || data.tmp[1] != dot2[1])//(p->n++ <= p->step)
	{
		data.color = ft_pixel_color(COLOR1, COLOR2, data.step, data.n);
		if (data.tmp[0] >= 0 && data.tmp[0] <= (p->width - 1) && \
				data.tmp[1] >= 0 && data.tmp[1] <= (p->hight - 1))
			p->draw[data.tmp[0] + data.tmp[1] * p->width] = data.color;
		data.error2 = data.error * 2;
		if (data.error2 > -data.deltay)
		{
			data.error -= data.deltay;
			data.tmp[0] += data.sign_x;
		}
		if (data.error2 < data.deltax)
		{
			data.error += data.deltax;
			data.tmp[1] += data.sign_y;
		}
		data.n  += 1;
	}
}

void	ft_drawing_line_dot(t_fractol *p, t_dot *dot1, t_dot *dot2)
{
	t_dot	tmp;
	double	deltax;
	double	deltay;
	int		step;
	int		n;
  
	deltax = dot2->x - dot1->x;
	deltay = dot2->y - dot1->y;
	step =(ABS(deltax) >= ABS(deltay)) ? ABS(deltax) : ABS(deltay);
	deltax = deltax / step;
	deltay = deltay / step;
	tmp.x = dot1->x;
	tmp.y = dot1->y;
	n = 0;
	while(n <= step)
	{
		tmp.color = ft_pixel_color(dot1->color, dot2->color, step, n);
		if ((int)tmp.x >= 0 && (int)tmp.x <= (WIDHT - 2) \
			&& (int)tmp.y >= 0 && (int)tmp.y <= (HIGHT - 2))
			p->draw[(int)round(tmp.x) + (int)round(tmp.y) * WIDHT] = tmp.color;
		tmp.x += deltax;
		tmp.y += deltay;
		n += 1;
	}
}
