/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:29:08 by seonggoc          #+#    #+#             */
/*   Updated: 2023/04/19 18:25:37 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	split_nl(int len, char *ptr, char *buf, char *remain)
{
	int		i;
	char	tmp[len];

	i = 0;
	while (i < len && buf[i] != '\n')
	{
		tmp[i] = buf[i];
		i++;
	}
	tmp[i] = '\0';
	ft_strjoin(ptr, tmp);
	while (i < len)
	{
		remain[i] = buf[i];
		i++;
	}
	remain[i] = '\0';
}

char	*get_return_value(int fd, char *buf, char *remain)
{
	int		len;

	len = 1;
	while (0 < len)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len < -1)
		{
			return (0);
		}
		if (len == 0)
		{
			return (buf);
		}
		buf[len] = '\0';
		if (ft_strchr(buf, len) == 0 && len != 0)
		{
			buf = ft_strjoin(ptr, ptr);
		}
		else if (ft_strchr(buf, len) != 0 && len != 0)
		{
			split_nl(len, ptr, buf, remain);
			return (ptr);
		}
	}
	return (ptr);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*remain;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
	{
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE < 1)
	{
		return (NULL);
	}
	ptr = get_return_value(fd, remain);
	return (ptr);
}
