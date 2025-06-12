/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:52:19 by aramos-m          #+#    #+#             */
/*   Updated: 2025/06/12 22:26:11 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int key_hook(int key_code, void *param);

// Función para poner un pixel en la imagen
void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// Función para calcular si un punto pertenece al conjunto mandelbrot
int calc_mandelbrot(double cr, double ci, int max_iter)
{
    double  zr;
    double  zi;
    double  tmp;
    int     i;

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
int get_color(int iter, int max_iter)
{
    if (iter == max_iter)
        return (0x000000);
    return (0xFFFFFF - (iter * 255 / max_iter) * 0x010101);
}

// Función para dibujar Mandelbrot
void draw_mandelbrot(t_data *img)
{
    int x;
    int y;
    double scale;

    y = 0;
    scale = 3.0 / WIDTH;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            double x0 = (x - WIDTH / 2.0) * scale - 0.5;
            double y0 = (y - HEIGHT / 2.0) * scale;
            int iter = calc_mandelbrot(x0, y0, MAX_ITER);
            put_pixel(img, x, y, get_color(iter, MAX_ITER));
            x++;
        }
        y++;
    }
}

int main(void)
{
    t_data  img;

    img.mlx = mlx_init();
    img.win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "Mandelbrot");
    img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    draw_mandelbrot(&img);
    mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
    mlx_key_hook(img.win, key_hook, &img);
    mlx_hook(img.win, ON_DESTROY, 0, close_win, &img);
    mlx_loop(img.mlx); 
    return (0);
}
