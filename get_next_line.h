/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:53:59 by aszhilki          #+#    #+#             */
/*   Updated: 2019/11/02 14:24:33 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/stat.h>
# include <sys/types.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFF_SIZE 32
# define FD_MAX 256

int		get_next_line(const int fd, char **line);

#endif
