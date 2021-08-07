/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 07:56:05 by bkael             #+#    #+#             */
/*   Updated: 2021/07/28 07:56:11 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_open(char *name)
{
	int	fd;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		ft_error("Failed open file");
	return (fd);
}

void	ft_close(int fd)
{
	if (close(fd) < 0)
		ft_error("Close error");
}

void	ft_start(t_mlx **mlx)
{
	(*mlx)->mlx = mlx_init();
	if (!(*mlx)->mlx)
		ft_error("MiniLibX error");
	(*mlx)->win = mlx_new_window((*mlx)->mlx, 1280, 720, "FDF");
	if (!(*mlx)->win)
		ft_error("MiniLibX error");
	(*mlx)->img = mlx_new_image((*mlx)->mlx, 1280, 720);
	if (!(*mlx)->img)
		ft_error("MiniLibX error");
	(*mlx)->addr = mlx_get_data_addr((*mlx)->img, &(*mlx)->bits,
			&(*mlx)->line_length, &(*mlx)->endian);
	if ((1280 / (*mlx)->width / 2) < (720 / (*mlx)->height / 2))
		(*mlx)->scale = 1280 / (*mlx)->width / 2;
	else
		(*mlx)->scale = 720 / (*mlx)->height / 2;
	(*mlx)->moving_x = 0;
	(*mlx)->moving_y = 0;
	(*mlx)->angle_x = 0.9;
	(*mlx)->angle_y = 0.9;
}

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	my_mlx_pixel_put(t_mlx **mlx, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < 1280 && y >= 0 && y < 720)
	{
		dst = (*mlx)->addr + (y * (*mlx)->line_length + x * ((*mlx)->bits / 8));
		*(unsigned int *)dst = color;
	}
}
