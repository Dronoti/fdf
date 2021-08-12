/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:23:39 by bkael             #+#    #+#             */
/*   Updated: 2021/08/11 19:23:44 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_click(int key, int x, int y, t_mlx **mlx)
{
	if (key == 1)
	{
		(*mlx)->prev_x = x;
		(*mlx)->prev_y = y;
		(*mlx)->click = 1;
	}
	return (0);
}

int	ft_unclick(int key, int x, int y, t_mlx **mlx)
{
	x = 0;
	y = 0;
	if (key == 1)
	{
		(*mlx)->save_x = (*mlx)->moving_x;
		(*mlx)->save_y = (*mlx)->moving_y;
		(*mlx)->click = 0;
	}
	return (0);
}

int	ft_move(int x, int y, t_mlx **mlx)
{
	if ((*mlx)->click)
	{
		(*mlx)->moving_y = (y - (*mlx)->prev_y) + (*mlx)->save_y;
		(*mlx)->moving_x = (x - (*mlx)->prev_x) + (*mlx)->save_x;
		ft_draw_map(*mlx);
	}
	return (0);
}

int	ft_exit(void)
{
	exit(EXIT_SUCCESS);
}
