#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

static void	ft_write(char *tmp, char **left, char **line)
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
		if (*left)
			ft_strdel(left);
		*left = ft_strdup(&tmp[i]);
//		if (!(*left))
//			*left = ft_strdup(&tmp[i]);
//		else if (**left == '\n')
//		{
//			(*left)++;
//			*left = ft_strjoin(*left, &tmp[i]);
//		}
	}
}

int		ft_return(char *left, int number, char **line)
{
	if (number < 0)
		return(-1);
	else if ((number == 0) && !left && !(*line))
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

	tmp = NULL;
	*line = NULL;
	if ((read(fd, buf, 0) < 0) || !fd)
		return (-1);
	if (left[fd])
	{
		tmp = left[fd];
		ft_strdel(&left[fd]);
//		if (ft_strchr(tmp, '\n'))
//			left[fd] = ft_strdup(ft_strchr(tmp, '\n'));
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
		ft_write(tmp, &(left[fd]), line);
	return (ft_return(left[fd], number, line));
}
