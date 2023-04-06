/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:29:08 by seonggoc          #+#    #+#             */
/*   Updated: 2023/04/06 13:40:31 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			i;
	char		tmp;
	ssize_t		ret;
	static void	*buf;

	i = 0;
	ret = read(fd, buf, 1);
	if (ret == -1 || ret == 0)
	{
		return (0);
	}
	while (ret != '\n' || ret != 0)
	{
		ft_memset(tmp);
		buf++;
	}
	return (0);
}
