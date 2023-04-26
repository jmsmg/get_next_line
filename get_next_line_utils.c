/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:31:04 by seonggoc          #+#    #+#             */
/*   Updated: 2023/04/26 17:47:43 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dst, const char *src)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	size;
	char	*tmp;

	size = ft_strlen(s1) + ft_strlen(s2);
	tmp = (char *)malloc(size + 1);
	if (!tmp)
	{
		return (0);
	}
	tmp[0] = '\0';
	ft_strcat(tmp, s1);
	i = ft_strlen(s1);
	ft_strcat(tmp + i, s2);
	return (tmp);
}

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	size_t	i;

	i = 0;
	while (s1[i])
	{
		i++;
	}
	tmp = malloc(sizeof(char) * i + 1);
	if (!tmp)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;
	size_t	size;

	size = (size_t)ft_strlen(s);
	if (size <= start)
		size = 0;
	else if (size <= start + len)
		size = size - start;
	else
		size = len;
	tmp = (char *)malloc(size + 1);
	if (!tmp)
	{
		return (0);
	}
	i = 0;
	while (i < size)
	{
		tmp[i] = s[start];
		start++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
