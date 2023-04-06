/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:31:04 by seonggoc          #+#    #+#             */
/*   Updated: 2023/04/06 18:26:52 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;
	unsigned long	i;

	i = 0;
	tmp = (unsigned char *)b;
	while (i < len)
	{
		tmp[i] = c;
		i++;
	}
	return (b);
}

int	ft_strchr(const char *s, int c)
{
	int		i;
	char	tmp;

	tmp = c;
	i = 0;
	while (s[i] && s[i] != tmp)
	{
		i++;
	}
	if (!(s[i]) && tmp != '\0')
	{
		return (0);
	}
	return (i);
}
