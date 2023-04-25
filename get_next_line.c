/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:29:08 by seonggoc          #+#    #+#             */
/*   Updated: 2023/04/25 17:03:08 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_remain(char *ptr)
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

char	*get_return_value(int fd, char *buf, char *ptr, char *remain)
{
	int	i;
	int	len;

	i = 0;
	len = 1;
	while (len)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
			return (NULL);
		else if (len == 0)
			return (remain);
		buf[len] = '\0';
		ptr = remain;
		remain = ft_strjoin(ptr, buf);
		free(ptr);
		if (remain == NULL)
		{
			return (NULL);
		}
		while (buf[i] && buf[i] == '\n')
		{
			return (remain);
		}
	}
	return (remain);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*ptr;
	static char	*remain;

	ptr = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
	{
		return (NULL);
	}
	if (!remain)
	{
		remain = ft_strdup("");
	}
	ptr = get_return_value(fd, buf, ptr, remain);
	if (!ptr || ptr[0] == '\0')
	{
		free(remain);
		remain = NULL;
		return (NULL);
	}
	remain = get_remain(ptr);
	return (ptr);
}
