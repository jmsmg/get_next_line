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
	int			i;
	char		buffer[BUFFER_SIZE];
	char		*ptr;
	static int	ret;

	i = 0;
	ret += read(fd, buffer, BUFFER_SIZE);
	if (ret == -1)
	{
		return (0);
	}	
	ptr = ft_strdup(buffer);
	while (!ft_strchr(buffer, '\n')) // EOF 처리해야함
	{
		printf("%d\n", ret);
		ret += read(fd, buffer, ret + BUFFER_SIZE);
		ptr = ft_strjoin(ptr, buffer);
	}
	return (ptr);
}