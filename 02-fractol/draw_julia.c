/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:11:07 by aramos-m          #+#    #+#             */
/*   Updated: 2025/06/25 20:10:41 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_julia(double zr, double zi, t_data *fractal)
{
	int		i;
	double	tmp;

	i = 0;
	while (zr * zr + zi * zi <= 4 && i < MAX_ITER)
	{
		tmp = zr * zr - zi * zi + fractal->julia.vr;
		zi = 2 * zr * zi + fractal->julia.vi;
		zr = tmp;
		i++;
	}
	return (i);
}

int	draw_julia(t_data *fractal)
{
	int		xy[2];
	int		i;
	double	zr;
	double	zi;

	xy[1] = 0;
	while (xy[1] < HEIGHT)
	{
		xy[0] = 0;
		while (xy[0] < WIDTH)
		{
			zr = (xy[0] - WIDTH / 2.0) / fractal->zoom + fractal->offset_x;
			zi = (xy[1] - HEIGHT / 2.0) / fractal->zoom + fractal->offset_y;
			i = calc_julia(zr, zi, fractal);
			put_pixel(fractal, xy[0], xy[1], get_color(i, MAX_ITER));
			xy[0]++;
		}
		xy[1]++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr,
		fractal->img.img_ptr, 0, 0);
	return (0);
}
