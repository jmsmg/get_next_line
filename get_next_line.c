/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:29:08 by seonggoc          #+#    #+#             */
/*   Updated: 2023/05/08 19:26:29 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_ptr(char *ptr, char *remain)
{
	char	*tmp;

	if (!ptr)
	{
		remain = ft_free(&remain);
		return (NULL);
	}
	tmp = ft_strdup(ptr);
	if (!tmp)
	{
		ptr = ft_free(&ptr);
		remain = ft_free(&remain);
		return (NULL);
	}
	ft_free(&ptr);
	return (tmp);
}

static char	*get_remain(char *ptr)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (ptr[i] && ptr[i] != '\n' )
	{
		i++;
	}
	if (ptr[i] == '\0' || ptr[i + 1] == '\0')
	{
		return (NULL);
	}
	if (i < ft_strlen(ptr))
	{
		tmp = ft_strdup(ptr + i + 1);
		if (!tmp)
		{
			ptr = ft_free(&ptr);
			return (NULL);
		}
		ptr[i + 1] = '\0';
	}
	return (tmp);
}

static char	*get_return_value(int fd, char *buf, char *remain)
{
	int		i;
	int		len;

	i = 0;
	len = 1;
	while (len)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
			return (NULL);
		if (len == 0)
			return (remain);
		buf[len] = '\0';
		remain = ft_strjoin(remain, buf);
		if (!remain)
			return (NULL);
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
	char		*buf;
	char		*ptr;
	static char	*remain;

	ptr = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!buf)
		return (NULL);
	if (!remain)
		remain = ft_strdup("");
	if (!remain)
		return (ft_free(&buf));
	ptr = get_return_value(fd, buf, remain);
	ft_free(&buf);
	if ((!ptr || ptr[0] == '\0'))
	{
		remain = ft_free(&remain);
		return (NULL);
	}
	remain = get_remain(ptr);
	ptr = get_ptr(ptr, remain);
	return (ptr);
}
