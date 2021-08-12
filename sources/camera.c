/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:55:54 by bkael             #+#    #+#             */
/*   Updated: 2021/07/28 17:55:57 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_handler_keys(int key, t_mlx **mlx)
{
	if (key >= 123 && key <= 126)
	{
		ft_rotate(key, mlx);
		ft_draw_map(*mlx);
	}
	else if (key == 69 || key == 24 || key == 27 || key == 78)
	{
		ft_scale(key, mlx);
		ft_draw_map(*mlx);
	}
	else if (key == 53)
		ft_exit();
	else if (key == 15)
	{
		ft_restart(mlx);
		ft_draw_map(*mlx);
	}
	else if (key == 35)
	{
		ft_projection(mlx);
		ft_draw_map(*mlx);
	}
	return (0);
}

void	ft_rotate(int key, t_mlx **mlx)
{
	if (key == 126)
		(*mlx)->angle_y -= 0.15;
	else if (key == 125)
		(*mlx)->angle_y += 0.15;
	else if (key == 123)
		(*mlx)->angle_x += 0.15;
	else if (key == 124)
		(*mlx)->angle_x -= 0.15;
}

void	ft_scale(int key, t_mlx **mlx)
{
	if (key == 69 || key == 24)
		(*mlx)->scale += 5;
	else if (key == 78 || key == 27)
		(*mlx)->scale -= 5;
	if ((*mlx)->scale <= 0)
		(*mlx)->scale = 1;
}

void	ft_restart(t_mlx **mlx)
{
	if ((1280 / (*mlx)->width / 2) < (720 / (*mlx)->height / 2))
		(*mlx)->scale = 1280 / (*mlx)->width / 2;
	else
		(*mlx)->scale = 720 / (*mlx)->height / 2;
	(*mlx)->moving_x = 0;
	(*mlx)->moving_y = 0;
	(*mlx)->angle_x = 0;
	(*mlx)->angle_y = 0;
	(*mlx)->save_x = 0;
	(*mlx)->save_y = 0;
}

void	ft_projection(t_mlx **mlx)
{
	(*mlx)->angle_x = 0;
	(*mlx)->angle_y = 0;
	if ((*mlx)->projection)
		(*mlx)->projection = 0;
	else
		(*mlx)->projection = 1;
}
