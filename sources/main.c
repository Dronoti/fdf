/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:22:54 by bkael             #+#    #+#             */
/*   Updated: 2021/07/26 12:23:25 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_manual(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 100, 17, 0xffffff,
		   "MANUAL | Move: Drag & Drop | Change projection: P | ");
	mlx_string_put(mlx->mlx, mlx->win, 620, 18, 0xffffff,
		   "Rotate: Arrows | Scale: +/- | Restart: R | Exit: Esc");
}

int	main(int argc, char **argv)
{
	int		fd;
	t_mlx	*mlx;

	if (argc != 2)
		ft_error("Invalid number of arguments");
	fd = ft_open(argv[1]);
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		ft_error("Malloc error");
	ft_malloc_map(fd, &mlx);
	ft_close(fd);
	fd = ft_open(argv[1]);
	ft_set_arr(fd, &mlx);
	ft_close(fd);
	ft_start(&mlx);
	ft_draw_map(mlx);
	mlx_hook(mlx->win, 2, 0, &ft_handler_keys, &mlx);
	mlx_hook(mlx->win, 4, 0, &ft_click, &mlx);
	mlx_hook(mlx->win, 5, 0, &ft_unclick, &mlx);
	mlx_hook(mlx->win, 6, 0, &ft_move, &mlx);
	mlx_hook(mlx->win, 17, 0, &ft_exit, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
