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

void	ft_set_points(t_point *p, t_mlx *mlx)
{
	mlx->z0 = mlx->coord[p->y0][p->x0];
	mlx->z1 = mlx->coord[p->y1][p->x1];
	if (mlx->z0 || mlx->z1)
		mlx->color = 0xe80c0c;
	else
		mlx->color = 0xffffff;
	p->x0 = p->x0 * mlx->scale - (mlx->width * mlx->scale) / 2;
	p->x1 = p->x1 * mlx->scale - (mlx->width * mlx->scale) / 2;
	p->y0 = p->y0 * mlx->scale - (mlx->height * mlx->scale) / 2;
	p->y1 = p->y1 * mlx->scale - (mlx->height * mlx->scale) / 2;
	mlx->z0 *= mlx->scale;
	mlx->z1 *= mlx->scale;
	ft_3d_rotate(p, mlx);
	p->x0 += 1280 / 2 + mlx->moving_x;
	p->x1 += 1280 / 2 + mlx->moving_x;
	p->y0 += (720 + mlx->height * mlx->scale) / 2 + mlx->moving_y;
	p->y1 += (720 + mlx->height * mlx->scale) / 2 + mlx->moving_y;
}

void	ft_3d_rotate(t_point *p, t_mlx *mlx)
{
	p->x0 = (p->x0 - p->y0) * cos(mlx->angle_x);
	p->y0 = (p->x0 + p->y0) * sin(mlx->angle_y) - mlx->z0;
	p->x1 = (p->x1 - p->y1) * cos(mlx->angle_x);
	p->y1 = (p->x1 + p->y1) * sin(mlx->angle_y) - mlx->z1;
}

void	ft_print_pixels(t_point p, t_mlx *mlx)
{
	int	delta_x;
	int	delta_y;
	int	error;
	int	y_step;

	delta_x = p.x1 - p.x0;
	delta_y = abs(p.y1 - p.y0);
	error = delta_x / 2;
	y_step = -1;
	if (p.y0 < p.y1)
		y_step = 1;
	while (p.x0 <= p.x1)
	{
		if (mlx->direction)
			my_mlx_pixel_put(&mlx, p.y0, p.x0, mlx->color);
		else
			my_mlx_pixel_put(&mlx, p.x0, p.y0, mlx->color);
		error -= delta_y;
		if (error < 0)
		{
			p.y0 += y_step;
			error += delta_x;
		}
		p.x0++;
	}
}

void	ft_draw_line(t_point p, t_mlx *mlx)
{
	ft_set_points(&p, mlx);
	mlx->direction = 0;
	if (abs(p.y1 - p.y0) > abs(p.x1 - p.x0))
	{
		ft_swap(&p.x0, &p.y0);
		ft_swap(&p.x1, &p.y1);
		mlx->direction = 1;
	}
	if (p.x0 > p.x1)
	{
		ft_swap(&p.x0, &p.x1);
		ft_swap(&p.y0, &p.y1);
	}
	ft_print_pixels(p, mlx);
}

void	ft_draw_map(t_mlx *mlx)
{
	t_point	p;

	p.y0 = 0;
	while (p.y0 < mlx->height)
	{
		p.x0 = 0;
		while (p.x0 < mlx->width)
		{
			if (p.x0 < mlx->width - 1)
			{
				p.x1 = p.x0 + 1;
				p.y1 = p.y0;
				ft_draw_line(p, mlx);
			}
			if (p.y0 < mlx->height - 1)
			{
				p.x1 = p.x0;
				p.y1 = p.y0 + 1;
				ft_draw_line(p, mlx);
			}
			p.x0++;
		}
		p.y0++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
