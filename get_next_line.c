/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:13:47 by seonggoc          #+#    #+#             */
/*   Updated: 2023/05/16 16:54:21 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_remain(char *ptr, char *remain)
{
	int		i;
	int		size;
	int		l_size;
	char	*tmp;

	size = 0;
	l_size = 0;
	if (!ptr)
	{
		remain = ft_free(&remain);
		return (NULL);
	}
	while (remain[size])
	{
		size++;
	}
	while (ptr[l_size])
	{
		l_size++;
	}
	size = size - l_size;
	tmp = (char *)malloc((sizeof(char) * size) + 1);
	if (!tmp)
	{
		remain = ft_free(&remain);
		ptr = ft_free(&ptr);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		tmp[i] = remain[l_size];
		i++;
		l_size++;
	}
	tmp[i] = '\0';
	remain = ft_free(&remain);
	return (tmp);
}

char	*get_return_value(char *remain)
{
	int		i;
	int		size;
	char	*ptr;

	size = 0;
	while (remain[size] && remain[size] != '\n')
	{
		size++;
	}
	if (size == 0 && remain[size] != '\n')
	{
		return (NULL);
	}
	if (remain[size] == '\n')
	{
		size++;
	}
	ptr = (char *)malloc((sizeof(char) * size) + 1);
	if (!ptr)
	{
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		ptr[i] = remain[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_get_line(int fd, char *buf, char *remain)
{
	int		i;
	int		len;

	i = 0;
	len = 1;
	while (len)
	{
		if (!remain)
			return (NULL);
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
		{
			remain = ft_free(&remain);
			return (NULL);
		}
		buf[len] = '\0';
		remain = ft_strjoin(remain, buf);
		while (remain[i])
		{
			if (remain[i] == '\n')
				return (remain);
			i++;
		}
	}
	return (remain);
}

char	*get_next_line(int fd)
{
	char		*ptr;
	char		*buf;
	static char	*remain;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!buf)
		return (NULL);
	if (!remain)
		remain = ft_strdup("");
	remain = ft_get_line(fd, buf, remain);
	buf = ft_free(&buf);
	if (!remain)
	{
		return (NULL);
	}
	ptr = get_return_value(remain);
	remain = get_remain(ptr, remain);
	return (ptr);
}
