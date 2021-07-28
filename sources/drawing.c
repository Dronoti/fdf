/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 07:56:57 by bkael             #+#    #+#             */
/*   Updated: 2021/07/28 07:57:00 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_3d(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z * 2;
}

void	ft_draw_line(float x0, float y0, float x1, float y1, t_mlx *mlx)
{
	float	deltax;
	float	deltay;
	int		max;
	int		scale;
	int		z0;
	int		z1;
	int		color;

	z0 = mlx->coord[(int)y0][(int)x0];
	z1 = mlx->coord[(int)y1][(int)x1];

	scale = 30;
	x0 *= scale;
	x1 *= scale;
	y0 *= scale;
	y1 *= scale;

	if (z0 || z1)
		color = 0xe80c0c;
	else
		color = 0xffffff;

	ft_3d(&x0, &y0, z0);
	ft_3d(&x1, &y1, z1);

	x0 += mlx->moving_x;
	y0 += mlx->moving_y;
	x1 += mlx->moving_x;
	y1 += mlx->moving_y;

	deltax = (x1 - x0);
	deltay = (y1 - y0);
	if (abs((int)deltax) >= abs((int)deltay))
		max = abs((int)deltax);
	else
		max = abs((int)deltay);
	deltax /= max;
	deltay /= max;
	while ((int)(x0 - x1) || (int)(y0 - y1))
	{
		mlx_pixel_put(mlx->mlx, mlx->win, x0, y0, color);
		x0 += deltax;
		y0 += deltay;
	}
}

void ft_draw_map(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->height)
	{
		x = 0;
		while (x < mlx->width)
		{
			if (x < mlx->width - 1)
				ft_draw_line(x, y, x + 1, y, mlx);
			if (y < mlx->height - 1)
				ft_draw_line(x, y, x, y + 1, mlx);
			x++;
		}
		y++;
	}
}