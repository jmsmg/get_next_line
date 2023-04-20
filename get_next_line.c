/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:29:08 by seonggoc          #+#    #+#             */
/*   Updated: 2023/04/20 18:02:54 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	split_nl(int len, char *ptr, char *buf, char *remain)
{
	int		i;

	i = 0;
	while (i < len && buf[i] != '\n')
	{
		i++;
	}
	remain = ft_substr(buf, i - 1, ft_strlen(buf));
	ptr = ft_substr(buf, 0, ft_strlen(ptr) - i);
}

char	*get_return_value(int fd, char *buf, char *ptr, char *remain)
{
	int		len;

	len = 1;
	while (0 <= len)
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
		ptr = ft_strjoin(ptr, buf);
		split_nl(len, ptr, buf, remain);
		if (ptr[ft_strlen(ptr) - 1])
		{
			return (ptr);
		}
	}
	return (ptr);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*ptr;
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
