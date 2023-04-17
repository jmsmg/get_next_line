/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:29:08 by seonggoc          #+#    #+#             */
/*   Updated: 2023/04/10 12:41:17 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	int			n;
	char		buffer[BUFFER_SIZE];
	char		*ptr;
	static int	ret;

	n = read(fd, buffer, BUFFER_SIZE);
	if (n == -1)
	{
		return (NULL);
	}
	ptr = ft_strdup(buffer, BUFFER_SIZE);
	while (!ft_strchr(ptr))
	{
		ret += read(fd, buffer, BUFFER_SIZE);
		ft_strjoin(ptr, )
	}
	while ()
	{
		ret += tmp;
		ptr = ft_strjoin(ptr, buffer);
	}
	return (ptr);
}