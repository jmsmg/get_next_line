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
	int			buf_len;
	char		buf[BUFFER_SIZE];
	char		*ptr;
	static int	ret;

	i = 0;
	buf_len = read(fd, buf, BUFFER_SIZE);
	// when the read function fails or nothing to read exception handling
	if (buf_len == -1 || buf_len == 0)
	{
		return (0);
	}
	// get index for return
	i = ft_strchr(buf, '\n', ret, buf_len);
	// allocate temporary memory
	ptr = malloc(sizeof(char *) * (i - ret) + 2);
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