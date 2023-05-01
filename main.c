<<<<<<< HEAD
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:46:25 by seonggoc          #+#    #+#             */
/*   Updated: 2023/04/26 22:41:32 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "get_next_line.h"
>>>>>>> parent of e0694ec (1차 제출)

int	main()
{
	int		fd;

<<<<<<< HEAD
	fd = open("test.txt", O_RDONLY);
	if (fd != -1)
	{
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));

		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
=======
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
		printf("42_with_nl : %s", get_next_line(fd));
		close(fd);
		printf("42_with_nl : %s", get_next_line(fd));
>>>>>>> parent of e0694ec (1차 제출)
	}
}
