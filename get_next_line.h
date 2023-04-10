/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:33:41 by seonggoc          #+#    #+#             */
/*   Updated: 2023/04/06 18:26:47 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

int	ft_strchr(const char *s, int c, int ret, int buf_len);
char	*get_next_line(int fd);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif