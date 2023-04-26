/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:46:25 by seonggoc          #+#    #+#             */
/*   Updated: 2023/04/26 16:47:07 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "get_next_line.h"

int	main()
{
	int		fd;

	fd = open("./test1.txt", O_RDONLY);
	if (fd != -1)
	{

		printf("42_with_nl : %s", get_next_line(fd));

		printf("42_with_nl : %s", get_next_line(fd));
		printf("42_with_nl : %s", get_next_line(fd));
		printf("42_with_nl : %s", get_next_line(fd));
		printf("42_with_nl : %s", get_next_line(fd));
		printf("42_with_nl : %s", get_next_line(fd));
		printf("42_with_nl : %s", get_next_line(fd));
		printf("42_with_nl : %s", get_next_line(fd));
		printf("42_with_nl : %s", get_next_line(fd));
		printf("42_with_nl : %s", get_next_line(fd));
		printf("42_with_nl : %s", get_next_line(fd));
		printf("42_with_nl : %s", get_next_line(fd));
		close(fd);
		printf("42_with_nl : %s", get_next_line(fd));
	}
}
