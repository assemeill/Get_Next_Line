/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:17:53 by aszhilki          #+#    #+#             */
/*   Updated: 2019/10/23 14:03:17 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define BUF_SIZE 7  

static char	*ft_store(char *buf)
{
	int		i;
	char	*tmp;

	i = 0;
	while (buf[i] != '\n')
		i++;
	buf[i++] = '\0';
	tmp = ft_strdup(&(buf[i]));
	return (tmp);
}

int			get_next_line(const int fd, char **line)
{
	char 		buf[BUF_SIZE + 1];
	static char left;
	char 		*tmp;
/* check if file can be read  */
	if (fd < 0 || read(fd, buf, 0))
		return (-1);
	*line = NULL;
	tmp = NULL;
	if (read(fd, buf, BUF_SIZE) > 0)
	{
/* check if there is new line in buf  */
		buf[BUF_SIZE] = '\0';
		if (ft_strstr(buf, "\n"))
		{
			tmp = ft_store(buf);
			ft_strcat(&left, tmp);
		}
		//printf("%s\n", *line);
		if (!(*line))
			*line = ft_strdup(buf);
		else
			*line = ft_strjoin(*line, buf);
	}
	//printf("%s\n", *line);
	return(1);
}

int		main(void)
{
	char	*line;
	int		fd;

	fd = open("some.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("1 %s\n", line);
	//ft_strclr(line);
	get_next_line(fd, &line);
	printf("2 %s\n", line);
}
