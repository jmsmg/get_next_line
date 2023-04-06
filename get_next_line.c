/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:29:08 by seonggoc          #+#    #+#             */
/*   Updated: 2023/04/06 14:04:08 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int					i;
	int					line;
	char				*ptr;
	char				*buf;
	static ssize_t		ret;

	buf = 0;
	ret += read(fd, buf, 1);
	if (ret == -1 || ret == 0)
	{
		return (0);
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
		ft_memset(ptr, buf[i], 1);
		i++;
	}
	buf[i + 1] = '\0';
	ret = 0;
	ret -= line;
	return (0);
}
