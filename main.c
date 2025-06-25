/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:55:08 by aramos-m          #+#    #+#             */
/*   Updated: 2025/06/25 23:21:14 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && s2[i] && s1[i])
	{
		if (s2[i] != s1[i])
			return ((unsigned const char)s1[i] - (unsigned const char)s2[i]);
		i++;
	}
	if (i != n)
		return ((unsigned const char)s1[i] - (unsigned const char)s2[i]);
	return (0);
}

int	check_values(int argc, char *name[], t_data *pict)
{
	if ((argc == 2) && (ft_strncmp(name[1], "mandelbrot", 11) == 0))
	{
		pict->flag = 1;
		return (0);
	}
	if ((argc == 4) && (ft_strncmp(name[1], "julia", 6) == 0))
	{
		pict->flag = 0;
		pict->julia.vr = atod(name[2]);
		pict->julia.vi = atod(name[3]);
		if (!isnan(pict->julia.vr) && !isnan(pict->julia.vi) \
			&& pict->julia.vr <= 2.0 && pict->julia.vr >= -2.0 && \
			pict->julia.vi <= 2.0 && pict->julia.vi >= -2.0)
			return (0);
	}
	return (1);
}

void	draw_fractals(t_data *figure)
{
	if (figure->flag == 1)
		mlx_loop_hook(figure->mlx_ptr, draw_mandelbrot, figure);
	else
		mlx_loop_hook(figure->mlx_ptr, draw_julia, figure);
}

int	main(int argc, char *name[])
{
	t_data	data;

	if (check_values(argc, name, &data) == 0)
	{
		data.zoom = 100.0;
		data.offset_x = -0.5;
		data.offset_y = 0.0;
		data.mlx_ptr = mlx_init();
		data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Fractol");
		data.img.img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
		data.img.pix_ptr = mlx_get_data_addr(data.img.img_ptr,
				&data.img.bpp, &data.img.line_length, &data.img.endian);
		mlx_mouse_hook(data.win_ptr, mouse, &data);
	}
	else
	{
		write(2, "Enter:\n mandelbrot\n julia <value_1> <value_2>\n", 47);
		exit (1);
	}
	draw_fractals(&data);
	mlx_key_hook(data.win_ptr, key_hook, &data);
	mlx_mouse_hook(data.win_ptr, mouse, &data);
	mlx_hook(data.win_ptr, ON_DESTROY, 0, close_win, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
