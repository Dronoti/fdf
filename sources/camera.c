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
	if (key == 126)
		(*mlx)->moving_y -= 20;
	if (key == 125)
		(*mlx)->moving_y += 20;
	if (key == 123)
		(*mlx)->moving_x -= 20;
	if (key == 124)
		(*mlx)->moving_x += 20;
	if (key == 126 || key == 125 ||key == 123 ||key == 124)
	{
		mlx_clear_window((*mlx)->mlx, (*mlx)->win);
		ft_draw_map(*mlx);
	}
	return (0);
}
