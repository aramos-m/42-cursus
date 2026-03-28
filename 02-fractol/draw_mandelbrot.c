/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:52:19 by aramos-m          #+#    #+#             */
/*   Updated: 2025/06/25 20:07:40 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Función para poner un pixel en la imagen
void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > WIDTH)
		return ;
	if (y < 0 || y > HEIGHT)
		return ;
	dst = data->img.pix_ptr + (y * data->img.line_length
			+ x * (data->img.bpp / 8));
	*(unsigned int *)dst = color;
}

// Función para calcular si un punto pertenece al conjunto mandelbrot
int	calc_mandelbrot(double cr, double ci, int max_iter)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	zr = 0;
	zi = 0;
	i = 0;
	while (zr * zr + zi * zi <= 4.0 && i < max_iter)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		i++;
	}
	return (i);
}

// Función para elegir el color a pintar
int	get_color(int i, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)i / max_iter;
	r = (int)(5 * (1 - t) * t * t * t * 255);
	g = (int)(20 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(12 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

// Función para dibujar Mandelbrot
int	draw_mandelbrot(t_data *img)
{
	int		x;
	int		y;
	int		i;
	double	cr;
	double	ci;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cr = ((x - (WIDTH / 2.0)) / img->zoom) + img->offset_x;
			ci = ((y - (HEIGHT / 2.0)) / img->zoom) + img->offset_y;
			i = calc_mandelbrot(cr, ci, MAX_ITER);
			put_pixel(img, x, y, get_color(i, MAX_ITER));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(img->mlx_ptr,
		img->win_ptr, img->img.img_ptr, 0, 0);
	return (0);
}
