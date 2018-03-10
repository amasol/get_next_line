/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:36:14 by amasol            #+#    #+#             */
/*   Updated: 2018/03/02 17:17:58 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
/*
static void		check_n(char **str, char **tmp)
{
	char 	*s;

	if (!(s = ft_strchr(*str, '\n')))
		*tmp = ft_strnew(0);
}
*/


int			get_next_line(const int fd, char **line)
{
	int			i;
	int 		ret;
	int			k;
	char 		*tmp;
//	static char str[BUFF_SIZE + 1];
	static char *str;

	i = 0;
	k = 0;
	str = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	tmp = ft_strnew(1);
	if (fd < 0 || !line)
		return (-1);
	// check_n(&str, &tmp);
	while ((ret = read(fd, str, BUFF_SIZE)) > 0)
	{
		str[ret] = '\0';
		tmp = ft_strjoin(tmp, str);
	}
	*line = ft_strdup(tmp);
	return (1);
}

int		main(int ac, char **av)
{
	int 	fd;
	char *line;

	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (get_next_line(fd, &line) == 1)
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
	close(fd);
	return (0);
}