/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:46:25 by seonggoc          #+#    #+#             */
/*   Updated: 2023/04/10 12:49:36 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "get_next_line.h"

int	main()
{
	int		fd;
	char	*a;
	char	*b;

	fd = open("./test1.txt", O_RDONLY);
	read(fd, a, BUFFER_SIZE);
	printf("%s\n", a);
	read(fd, a, BUFFER_SIZE);
	printf("%s", a);
	read(fd, a, BUFFER_SIZE);
	printf("%s", a);
	close(fd);
}
