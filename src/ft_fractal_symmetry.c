#include "fractol.h"

int		ft_symmetry_check(t_fractol *data, double c_re, double c_im)
{
	double	tmp;
	double	z_re;
	double	z_im;
	double	orbit;
	int		iter;

	z_re = c_re;
	z_im = c_im;
	orbit = c_re * c_re + c_im * c_im;
	iter = 0;
	while (iter < data->num_iter && orbit <= 4)
	{
		tmp = z_re;
		z_re = z_re * z_re - z_im * z_im + data->const_re;
		z_im = 2 * tmp * ABS(z_im) + data->const_im;
		orbit = z_re * z_re + z_im * z_im;
		iter += 1;
	}
	return (iter);
}
