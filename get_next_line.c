/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:29:08 by seonggoc          #+#    #+#             */
/*   Updated: 2023/04/24 14:54:16 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_return_value(char *remain)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	while (remain[i] && remain[i] != '\n' )
	{
		i++;
	}
	ptr = ft_substr(ptr, 0, i);
	return (ptr);
}

char	*get_remain(char *buf, char *remain)
{
	int	i;
	int	j;

	i = 0;
	while (remain[i] && remain[i] != '\n')
	{
		i++;
	}
	j = ft_strlen(remain);
	if (i != j)
	{
		remain = ft_substr(remain, i, j);
		return (remain);
	}
	return(remain);
}

char	*get_next_line(int fd)
{
	int			len;
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	char		*ptr;
	static char	*remain;

	len = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!remain)
		remain = ft_strdup("");
	while (0 < len)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len < -1)
			return (0);
		if (len == 0)
			return (remain);
		buf[len] = '\0';
		remain = ft_strjoin(remain, buf);
		ptr = get_return_value(buf, remain);
		remain = get_remain(buf, remain);
		if (ft_strlen(remain))
		{
		}
	}
	return (ptr);
}
