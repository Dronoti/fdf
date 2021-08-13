/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 20:40:38 by bkael             #+#    #+#             */
/*   Updated: 2021/08/13 20:40:41 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_check_hex(char n)
{
	char	*base1;
	char	*base2;
	int		i;

	base1 = "0123456789ABCDEF";
	base2 = "0123456789abcdef";
	i = 0;
	while (base1[i] || base2[i])
	{
		if (n == base1[i] || n == base2[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_convert_color(char *nptr)
{
	unsigned int	num;
	unsigned int	i;

	num = 0;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] != '0' && !(nptr[i + 1] == 'x' || nptr[i + 1] == 'X'))
		return (num);
	i += 2;
	while (ft_check_hex(nptr[i]) >= 0)
	{
		num = num * 16 + ft_check_hex(nptr[i]);
		i++;
	}
	return ((int)num);
}

void	ft_set_num_n_color(int x, int y, char *nbr, t_mlx **mlx)
{
	char	**split;
	int		i;

	split = ft_split(nbr, ',');
	(*mlx)->coord[y][x] = ft_atoi(split[0]);
	if (!split[1])
		(*mlx)->color[y][x] = -1;
	else
		(*mlx)->color[y][x] = ft_convert_color(split[1]);
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
