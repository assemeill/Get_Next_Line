#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

static void	ft_write(char **tmp, char **left, char **line)
{
	int i;

	i = 0;
	while ((*tmp)[i] != '\n' && (*tmp)[i] != '\0')
		i++;
	if (*line)
		ft_strdel(line);
	else
		*line = NULL;
	*line = ft_strsub(*tmp, 0, i);
	i++;
	if ((*tmp)[i] != '\0' && ft_strchr(*tmp, '\n'))
	{
		if (*left)
			ft_strdel(&(*left));
		*left = ft_strdup(*tmp + i);
	}
	ft_strdel(tmp);
}

int		ft_return(char *left, int number, char **line)
{
	if (number < 0)
		return (-1);
	else if (number == 0 && !left && !(*line))
		return (0);
	else
		return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*left[FD_MAX];
	char		*save;
	char		*tmp;
	char		buf[BUFF_SIZE + 1];
	int			number;

	tmp = NULL;
	if ((read(fd, buf, 0) < 0) || (fd < 0 || line == NULL))
		return (-1);
	*line = NULL;
	if (left[fd])
	{
		tmp = ft_strdup(left[fd]);
		ft_strdel(&left[fd]);
	}
	while ((number = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[number] = '\0';
		if (!tmp)
			tmp = ft_strdup(buf);
		else
		{
			save = tmp;
			tmp = ft_strjoin(tmp, buf);
			ft_strdel(&save);
		}
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (tmp)
		ft_write(&tmp, &(left[fd]), line);
	return (ft_return(left[fd], number, line));
}
