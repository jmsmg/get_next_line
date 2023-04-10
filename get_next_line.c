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
	int				i;
	int				line;
	char			*buf;
	char			*ptr;
	static ssize_t	ret;

	i = 0;
	buf_len = read(fd, buf, BUFFER_SIZE);
	if (buf_len == -1 || buf_len == 0)
	{
		return (0);
	}
	// 버퍼 안에 \n이 포함 될 경우, 안될 경우 두가지로 나눠야함
	// 못찾는 경우 (찾을 때까지 계속 돌림)
	while (ft_strchr(buf, '\n') != 0)
	{
		buf_len += read(fd, buf, BUFFER_SIZE);
		i++;
	}
	line = ft_strchr(buf, '\n');
	if (line == 0)
	{
		ptr = malloc(sizeof(char *) * ret + 1);
	}
	else
	{
		ptr = malloc(sizeof(char *) * line + 1);
	}
	i = 0;
	while (buf[i] != '\n' || buf[i] != 0)
	{
		ft_memmove(ptr, buf[i], 1);
		i++;
	}
	buf[i + 1] = '\0';
	ret = 0;
	ret -= line;
	return (0);
}
