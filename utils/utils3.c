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
