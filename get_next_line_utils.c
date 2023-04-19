/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:31:04 by seonggoc          #+#    #+#             */
/*   Updated: 2023/04/19 18:04:58 by seonggoc         ###   ########.fr       */
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	j = dst_len;
	src_len = ft_strlen((char *)src);
	if (dstsize <= dst_len)
	{
		return (src_len + dstsize);
	}
	while (j < dstsize - 1 && src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dst_len + src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
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
	tmp[0] = 0;
	ft_strlcat(tmp, s1, size + 1);
	i = ft_strlen(s1);
	ft_strlcat(&tmp[i], s2, size + 1);
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

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	if (!(s[i]) && c != '\0')
	{
		return (0);
	}
	return ((char *)s + i);
}
