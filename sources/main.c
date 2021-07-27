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
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("Failed open file");
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		ft_error("Malloc error");
	ft_malloc_map(fd, &mlx);
	ft_close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("Failed open file");
	ft_set_arr(fd, &mlx);
	ft_close(fd);
	free(mlx);
	return (0);
}
