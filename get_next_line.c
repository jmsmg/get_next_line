/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:29:08 by seonggoc          #+#    #+#             */
/*   Updated: 2023/04/25 20:04:14 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*get_remain(char *ptr)
{
	int		i;
	char	*tmp;

	i = 0;
	while (ptr[i] && ptr[i] != '\n' )
	{
		i++;
	}
	if (ptr[i] == '\0' || ptr[i + 1] == '\0')
	{
		return (NULL);
	}
	tmp = ft_substr(ptr, i + 1, ft_strlen(ptr));
	if (tmp == NULL)
	{
		return (NULL);
	}
	ptr[i + 1] = '\0';
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
		if (remain == NULL)
			return (NULL);
		while (buf[i])
		{
			if (buf[i] == '\n')
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
	{
		remain = ft_strdup("");
	}
	ptr = get_return_value(fd, buf, remain);
	free(buf);
	buf = NULL;
	if (!ptr || ptr[0] == '\0')
	{
		free(remain);
		remain = NULL;
		return (remain);
	}
	remain = get_remain(ptr);
	return (ptr);
}
