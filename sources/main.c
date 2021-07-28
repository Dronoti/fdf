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

int	main (int argc, char **argv)
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
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1280, 720, "FDF");
	ft_draw_map(mlx);
	mlx_key_hook(mlx->win, &ft_handler_keys, &mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
