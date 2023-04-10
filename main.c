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
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int	main()
{
	char	buff[BUFF_SIZE];
	int		fd;

	fd = open("./test1.txt", O_RDONLY);
	read(fd, buff, BUFF_SIZE);
	printf("%s", buff);
	close(fd);
}
