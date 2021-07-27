/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:10:47 by bkael             #+#    #+#             */
/*   Updated: 2021/07/26 12:12:45 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../utils/get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
# include <math.h>
#include <stdio.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*win;

	int		width;
	int		height;
	int		**coord;
}				t_mlx;

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_error(char *str);
void	ft_close(int fd);
void	ft_malloc_map(int fd, t_mlx **mlx);
void	ft_get_size_map(int fd, t_mlx **mlx);
int		ft_count_word(char *s, char c);
void	ft_set_arr(int fd, t_mlx **mlx);
char	**ft_split(char *s, char c);
void	ft_getarr(char **strsplit, char *s, char c, int n);
void	ft_freearr(char ***strsplit, int i);
char	*ft_substr(char *s, int start, int len);
int		ft_atoi(const char *nptr);

#endif