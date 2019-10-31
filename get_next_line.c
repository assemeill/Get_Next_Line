#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

static void	ft_write(char *tmp, char *left, char **line)
{
	int i;

	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	*line = ft_strsub(tmp, 0, i);
	printf("%s\n", *line);
	i++;
	if (tmp[i] != '\0' && tmp[i] != '\n')
	{
		if (!(left))
			left = ft_strdup(&tmp[i]);
		else if (*left == '\n')
		{
			left++;
			left = ft_strjoin(left, &tmp[i]);
		}
	}
}

int		ft_return(char *left, int number, char **line)
{
	if (number < 0)
		return(-1);
	else if ((number == 1) && !left && !(*line))
		return(0);
	else
		return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*left[FD_MAX];
	char		*tmp;
	char		buf[BUFF_SIZE + 1];
	int			number;
	int			i;

	i = 0;
	tmp = NULL;
	*line = NULL;
	if ((read(fd, buf, 0) < 0) || !fd)
		return (-1);
	if (left[fd])
	{
		tmp = left[fd];
		while (left[fd][i] != '\n' && left[fd][i] != '\0')
			i++;
		if (left[fd][i] == '\0')
			ft_strdel(&left[fd]);
	}
	while ((number = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[number] = '\0';
		if (!tmp)
			tmp = ft_strdup(buf);
		else
		{
			//free mem
			tmp = ft_strjoin(tmp, buf);
		}
		if (strchr(buf, '\n'))
			break ;
	}
	if (tmp)
		ft_write(tmp, &left[fd][i], line);
	return (ft_return(left[fd], number, line));
}

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/*
** 2 lines with 8 chars with Line Feed
*/

int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "gnl1_2.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (count_lines == 0 && strcmp(line, "1234567") != 0)
				errors++;
			if (count_lines == 1 && strcmp(line, "abcdefg") != 0)
				errors++;
			count_lines++;
			if (count_lines > 50)
				break ;
		}
		close(fd);
		if (count_lines != 2)
			printf("-> must have returned '1' twice instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"1234567\" and \"abcdefg\"\n");
		if (count_lines == 2 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
}
