/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:17:53 by aszhilki          #+#    #+#             */
/*   Updated: 2019/10/19 16:02:13 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define BUF_SIZE 1

int		get_next_line(const int fd, char **line)
{
	char buf[BUF_SIZE];
//	static char left;
	if (fd < 1 || read(fd, buf, 0))
		return (-1);
	while (read(fd, buf, BUF_SIZE))
	{
		printf("%s\n", buf);
		ft_strjoin(*line, buf);
	}
	printf("%s\n", *line);
	return(1);
}

int		main(void)
{
	char	*line;
	int		fd;

	fd = open("some.txt", O_RDONLY);
	get_next_line(fd, &line);
}
