/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:57:39 by bkael             #+#    #+#             */
/*   Updated: 2021/08/13 15:57:43 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*substr;
	int		i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

void	ft_freearr(char ***strsplit, int i)
{
	int	k;

	k = 0;
	while (k < i)
	{
		free(*strsplit + i);
		i++;
	}
	free(*strsplit);
	*strsplit = NULL;
}

void	ft_getarr(char **strsplit, char *s, char c, int n)
{
	int	i;
	int	start;
	int	len;

	i = 0;
	start = 0;
	while (i < n)
	{
		while (s[start] && s[start] == c)
			start++;
		len = 0;
		while (s[start + len] && s[start + len] != c)
			len++;
		strsplit[i] = ft_substr(s, start, len);
		if (!strsplit[i])
		{
			ft_freearr(&strsplit, i);
			ft_error("Malloc error");
		}
		start += len;
		i++;
	}
	if (i == n)
		strsplit[n] = NULL;
}

char	**ft_split(char *s, char c)
{
	char	**strsplit;
	int		n;

	if (!s)
		ft_error("Invalid map");
	n = ft_count_word(s, c);
	strsplit = (char **)malloc(sizeof(char *) * (n + 1));
	if (!strsplit)
		ft_error("Malloc error");
	ft_getarr(strsplit, s, c, n);
	return (strsplit);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	long long		num;
	long long		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		if (num > 2147483647 && sign == 1)
			return (-1);
		if (num > 2147483648 && sign == -1)
			return (0);
		i++;
	}
	return (num * sign);
}
