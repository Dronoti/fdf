/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:43:17 by bkael             #+#    #+#             */
/*   Updated: 2021/07/26 19:43:20 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_count_word(char *s, char c)
{
	int	j;
	int	count;
	int	len;

	j = 0;
	count = 0;
	while (s[j] != '\0')
	{
		while (s[j] && s[j] == c)
			j++;
		len = 0;
		while (s[j + len] && (s[j + len] != c))
			len++;
		if (!len)
			return (count);
		count++;
		j += len;
	}
	return (count);
}

void	ft_get_size_map(int fd, t_mlx **mlx)
{
	char	*line;
	int		height;
	int		read;

	height = 0;
	read = get_next_line(fd, &line);
	while (read > 0)
	{
		if (height == 0)
			(*mlx)->width = ft_count_word(line, ' ');
		free(line);
		height++;
		read = get_next_line(fd, &line);
	}
	free(line);
	if (read < 0)
		ft_error("Read error");
	else
		(*mlx)->height = height;
}

void	ft_malloc_map(int fd, t_mlx **mlx)
{
	int	i;

	i = 0;
	ft_get_size_map(fd, mlx);
	if (!(*mlx)->height || !(*mlx)->width)
		ft_error("Invalid map");
	(*mlx)->coord = (int **)malloc(sizeof(int *) * (*mlx)->height);
	if (!(*mlx)->coord)
		ft_error("Malloc error");
	while (i < (*mlx)->height)
	{
		(*mlx)->coord[i] = (int *)malloc(sizeof(int) * (*mlx)->width);
		if (!(*mlx)->coord[i])
			ft_error("Malloc error");
		i++;
	}
}

void	ft_set_arr(int fd, t_mlx **mlx)
{
	char	*line;
	char	**nbrs;
	int		read;
	int		x;
	int		y;

	y = 0;
	read = get_next_line(fd, &line);
	while (read > 0)
	{
		x = -1;
		nbrs = ft_split(line, ' ');
		while (nbrs[++x])
		{
			(*mlx)->coord[y][x] = ft_atoi(nbrs[x]);
			free(nbrs[x]);
		}
		free(nbrs);
		free(line);
		y++;
		read = get_next_line(fd, &line);
	}
	free(line);
	if (read < 0)
		ft_error("Read error");
}
