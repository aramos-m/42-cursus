/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:52:01 by aramos-m          #+#    #+#             */
/*   Updated: 2025/06/25 20:01:12 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	apply_zoom(t_data *pic, double mx, double my, double var)
{
	double	prev_x;
	double	prev_y;

	prev_x = (mx - (WIDTH / 2.0)) / pic->zoom + pic->offset_x;
	prev_y = (my - (HEIGHT / 2.0)) / pic->zoom + pic->offset_y;
	pic->zoom = pic->zoom * var;
	pic->offset_x = prev_x - (mx - WIDTH / 2.0) / pic->zoom;
	pic->offset_y = prev_y - (my - HEIGHT / 2.0) / pic->zoom;
}

int	mouse(int button, int x, int y, t_data *pic)
{
	if (button == 4)
		apply_zoom(pic, x, y, 1.1);
	else if (button == 5)
		apply_zoom(pic, x, y, 0.9);
	if ((pic->flag) == 1)
		draw_mandelbrot(pic);
	else
		draw_julia(pic);
	return (0);
}
