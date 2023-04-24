/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:29:08 by seonggoc          #+#    #+#             */
/*   Updated: 2023/04/24 17:39:35 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_remain(char *remain)
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
		remain = ft_substr(remain, i + 1, j);
		return (remain);
	}
	return(remain);
}

char	*get_return_value(char *remain)
{
	int		i;
	char	*ptr;

	i = 0;
	while (remain[i] && remain[i] != '\n' )
	{
		i++;
	}
	ptr = ft_substr(remain, 0, i);
	if (remain[i] == '\n')
	{
		ptr = ft_strcat(ptr, "\n");
	}
	return (ptr);
}

char	*get_next_line(int fd)
{
	int			len;
	char		buf[BUFFER_SIZE + 1];
	char		*ptr;
	static char	*remain;

	len = 1;
	ptr = ft_strdup("");
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!remain)
		remain = ft_strdup("");
	while (0 < len)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len < -1)
			return (0);
		buf[len] = '\0';
		remain = ft_strjoin(remain, buf);
		ptr = get_return_value(remain);
		remain = get_remain(remain);
		if (ptr[ft_strlen(ptr) - 1] == '\n')
			break;
	}
	return (ptr);
}
