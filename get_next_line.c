/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:29:08 by seonggoc          #+#    #+#             */
/*   Updated: 2023/04/18 15:12:05 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	node	list;
	char	buffer[BUFFER_SIZE];
	char	*ptr;

	ptr = (char *)malloc(1);
	if (!ptr)
		return (NULL);
	ptr[0] = '\0';
	while (!ft_strchr(ptr))
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
			return (NULL);
		ptr = ft_strnjoin(ptr, buffer, n);
		ret += n;
	}
	return (ptr);
}
