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
	int			tmp;
	char		buffer[BUFFER_SIZE];
	char		*ptr;
	static int	ret;

	tmp = read(fd, buffer, BUFFER_SIZE);
	if (tmp == -1)
	{
		return (0);
	}
	ret += tmp;
	ptr = ft_strdup(buffer);
	while (ft_strchr(buffer)) // EOF 처리해야함
	{
		tmp = read(fd, buffer, ret + BUFFER_SIZE);
		ret += tmp;
		ptr = ft_strjoin(ptr, buffer);
	}
	return (ptr);
}