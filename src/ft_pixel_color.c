#include "../includes/fractol.h"

static int	color_gradient(int start, int end, double percent)
{
	return ((int)(start * (1 - percent) + end * percent));
}

int			ft_pixel_color(int color1, int color2, int step, int n)
{
	int		red;
	int		green;
	int		blue;
	double	percent;

	if (color1 == color2)
		return (color1);
	percent = (step == 0) ? 1.0 : ((double)n / (double)step);
	red = color_gradient((color1 >> 16) & 0xFF, (color2 >> 16) & 0xFF, percent);
	green = color_gradient((color1 >> 8) & 0xFF, (color2 >> 8) & 0xFF, percent);
	blue = color_gradient(color1 & 0xFF, color2 & 0xFF, percent);
	return ((red << 16) | (green << 8) | blue);
}

static int	ft_pixel_color_alfa(double max_speed, double speed)
{
	double	per;
	int		red;
	int		green;
	int		blue;

	if (speed <= max_speed / 2)
		per = speed / (max_speed * 0.5);
	else if (speed <= max_speed * 0.75)
		per = (speed - max_speed * 0.5) / (max_speed * (0.75 - 0.5));
	else if (speed <= max_speed * 0.875)
		per = (speed - max_speed * 0.75) / (max_speed * (0.875 - 0.75));
	else
		per = (speed - max_speed * 0.875) / (max_speed * 0.125);
	red = (int)(9 * (1 - per) * pow(per, 3) * 255);
	green = (int)(15 * pow((1 - per), 2) * pow(per, 2) * 255);
	blue = (int)(8.5 * pow((1 - per), 3) * per * 255);
	return ((red << 16) | (green << 8) | blue);
}

int			function_color(t_fractol *data, int speed)
{
	int color;
	int max_iter;

	color = 0x0;
	max_iter = data->num_iter;
	if (data->color_function == 1)
		color = ft_pixel_color_alfa(max_iter, speed);
	else if (data->color_function == 2)
	{
		if (speed == max_iter)
			color = 0x0;
		else
			color = mlx_get_color_value(data->mlx_ptr, speed * data->color);
	}
	return (color);
}

// static int	ft_pixel_color_betta(t_fractol *data, int max_speed, int speed)
// {
// 	int	color;

// 	if (speed == max_speed)
// 		color = 0x0;
// 	else
// 		color = mlx_get_color_value(data->mlx_ptr, speed * data->color);
// 	return (color);
// }

// static int	color_alfa(double per)
// {
// 	t_color	pixel;

// 	pixel.red = (int)(9 * (1 - per) * pow(per, 3) * 255);
// 	pixel.green = (int)(15 * pow((1 - per), 2) * pow(per, 2) * 255);
// 	pixel.blue = (int)(8.5 * pow((1 - per), 3) * per * 255);
// 	return ((pixel.red << 16) | (pixel.green << 8) | pixel.blue);
// }
