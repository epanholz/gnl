/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: epanholz <epanholz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/24 14:51:56 by epanholz       #+#    #+#                */
/*   Updated: 2020/02/06 16:47:35 by epanholz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strclen(const char *s, char c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	if (!dst && !src)
		return (dst);
	d = dst;
	s = src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return ((void *)dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strclen(s1, '\0');
	len_s2 = ft_strclen(s2, '\0');
	if (!s1)
	{
		new = (char *)malloc((len_s2 + 1) * sizeof(char));
		ft_memcpy(new, s2, len_s2 + 1);
		if (new == NULL)
			return (NULL);
		return (new);
	}
	new = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, s1, len_s1);
	free(s1);
	ft_memcpy(new + len_s1, s2, len_s2 + 1);
	return (new);
}

char	*ft_trim_right(char *s)
{
	int		i;
	char	*new;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	new = (char *)malloc((i + 1) * sizeof(char));
	if (new == NULL)
	{
		free(s);
		return (NULL);
	}
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	free(s);
	return (new);
}
