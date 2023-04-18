/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:33:41 by seonggoc          #+#    #+#             */
/*   Updated: 2023/04/18 14:31:23 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

typedef struct node
{
	int			fd;
    void		*save;
    struct node	next;
}   node;

int 	ft_strchr(const char *s);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strnjoin(char const *s1, char const *s2, int n);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
#endif
