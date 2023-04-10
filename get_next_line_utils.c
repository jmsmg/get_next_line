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

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	size_t	i;

	i = 0;
	while (s1[i])
	{
		i++;
	}
	tmp = malloc(sizeof(char) * i + 1);
	if (!tmp)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int	ft_strchr(const char *s, int c, int ret, int buf_len)
{
	int	i;

	i = 0;
	while (s[ret] && s[ret] != c && i < buf_len)
	{
		i++;
		ret++;
	}
	if (!(s[ret]) && c != '\0')
	{
		return (0);
	}
	return (i);
}