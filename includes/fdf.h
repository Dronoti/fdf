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

typedef struct s_point
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
}				t_point;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits;
	int		line_length;
	int		endian;

	int		width;
	int		height;
	int		**coord;
	int		z0;
	int		z1;
	float	angle_x;
	float	angle_y;

	int		moving_x;
	int		moving_y;
	int		direction;
	int		color;
	int		scale;
}				t_mlx;

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_error(char *str);
void	ft_close(int fd);
int		ft_open(char *name);
void	ft_malloc_map(int fd, t_mlx **mlx);
void	ft_get_size_map(int fd, t_mlx **mlx);
int		ft_count_word(char *s, char c);
void	ft_set_arr(int fd, t_mlx **mlx);
char	**ft_split(char *s, char c);
void	ft_getarr(char **strsplit, char *s, char c, int n);
void	ft_freearr(char ***strsplit, int i);
char	*ft_substr(char *s, int start, int len);
int		ft_atoi(const char *nptr);
void	ft_draw_line(t_point p, t_mlx *mlx);
void	ft_swap(int *a, int *b);
void	ft_draw_map(t_mlx *mlx);
void	ft_set_points(t_point *p, t_mlx *mlx);
void	ft_3d_rotate(t_point *p, t_mlx *mlx);
int		ft_handler_keys(int key, t_mlx **mlx);
void	ft_start(t_mlx **mlx);
void	my_mlx_pixel_put(t_mlx **mlx, int x, int y, int color);
void	ft_print_pixels(t_point p, t_mlx *mlx);

#endif