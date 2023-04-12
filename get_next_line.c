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

char	*get_next_line(int fd)
{
	int			i;
	char		buffer[BUFFER_SIZE + 1];
	char		*ptr;
	static int	ret;

	i = 0;
	i = ft_strchr(buf, '\n');
	ptr = (char)malloc((sizeof(char) * i) + 1);
	if (!ptr)
	{
		return (0);
	}
	i = 0;
	while (buf[ret] != '\n' && buf[ret] != '\0')
	{
		ptr[i] = buf[ret];
		i++;
		ret++;
	}
	ret++;
	ptr[i] = '\n';
	ptr[i + 1] = '\0';
	return (ptr);
}