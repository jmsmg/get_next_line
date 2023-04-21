/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:29:08 by seonggoc          #+#    #+#             */
/*   Updated: 2023/04/21 12:20:19 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*split_nl(char *remain)
{
	int		i;
	char	*ptr;

	i = 0;
	while (remain[i] && remain[i] != '\n')
	{
		i++;
	}
	ptr = ft_substr(remain, 0, i);
	remain = ft_substr(remain, i, ft_strlen(remain));
	return (ptr);
}

char	*get_return_value(int fd, char *buf, char *ptr, char *remain)
{
	int		len;

	len = 1;
	while (0 < len)
	{
		if (remain[0] == '\0')
		{
			len = read(fd, buf, BUFFER_SIZE);
			if (len < -1)
			{
				return (0);
			}
			if (len == 0)
			{
				return (ptr);
			}
			buf[len] = '\0';
			remain = ft_strjoin(remain, buf);
		}
		ptr = split_nl(remain);
		if (ptr[ft_strlen(ptr) - 1])
		{
			return (ptr);
		}
	}
	return (ptr);
}

char	*get_next_line(int fd)
{
	char		*ptr;
	char		buf[BUFFER_SIZE + 1];
	static char	*remain;

	if (fd < 0 || BUFFER_SIZE < 1)
	{
		return (NULL);
	}
	if (!remain)
	{
		ptr = ft_strdup("");
		remain = ft_strdup("");
	}
	else
	{
		ptr = ft_strdup(remain);
	}
	ptr = get_return_value(fd, buf, ptr, remain);
	return (ptr);
}
