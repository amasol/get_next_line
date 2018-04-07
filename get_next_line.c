/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:36:14 by amasol            #+#    #+#             */
/*   Updated: 2018/03/19 20:59:14 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_check_n(char **line, t_str **memory)
{
	int 	j;
	int 	i;
	int 	len;
	char 	*tmp;

	i = 0;
	len = 0;
	tmp = (*memory)->buff;
	if ((*memory)->buff)
	{
		while ((*memory)->buff[i] && (*memory)->buff[i] != '\n')
			i++;
		j = 0;
		if ((*memory)->buff[j] == '\n')
		{
			*line = ft_strdup("\0");
			(*memory)->buff = ft_strsub((*memory)->buff, i + 1, ft_strlen((*memory)->buff) - i);
			return (1);
		}
		else
			*line = ft_strsub((*memory)->buff, 0, i);
		(*memory)->buff = ft_strsub((*memory)->buff, i + 1, ft_strlen((*memory)->buff) - i);
		ft_strdel(&tmp);
	}
	len = ft_strlen(*line);
	len = len > 0 ? 1 : 0;
	return (len);
}

static void		ft_check_fd(t_str **memory, t_str **lst, int fd)
{
	if (!(*memory))
	{
		*memory = (t_str *)malloc(sizeof(t_str));
		(*memory)->fd = fd;
		(*memory)->buff = ft_strnew(0);
	}
	*lst = *memory;
	while ((*lst)->fd != fd && (*lst)->next)
		*lst = (*lst)->next;
	if ((*lst)->fd != fd)
	{
		(*lst)->next = (t_str *)malloc(sizeof(t_str));
		*lst = (*lst)->next;
		(*lst)->fd = fd;
		(*memory)->buff = ft_strnew(0);
	}
}

int				get_next_line(const int fd, char **line)
{
	t_str			*lst;
	static t_str	*memory;
	char 			*clean;
	int 			flag;

	flag = 0;
	*line = NULL;
	if (fd < 0 || !line /*|| read(lst->fd, lst->data, 0) < 0*/)
			return (-1);
	ft_check_fd(&memory, &lst, fd);
	while ((flag = read(lst->fd, lst->data, BUFF_SIZE)) > 0)
	{
		lst->data[flag] = '\0';
		clean = memory->buff;
		memory->buff = ft_strjoin(memory->buff, lst->data);
		ft_strdel(&clean);
		if (memory->buff && ft_strchr(memory->buff, '\n'))
			break ;
	}
	flag = ft_check_n(line, &memory);
	return (flag);
}

/*
int		main(int argc, char **argv)
{
	int fd;
	char *line;

	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
}
*/

int		main(int ac, char **av)
{
	int fd3;
	int fd4;
	int fd5;
	char *line;

	line = NULL;
	fd3 = open("test", O_RDONLY);
//	fd4 = open("test2", O_RDONLY);
	fd5 = open("test3", O_RDONLY);
	if (get_next_line(fd3, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
	if (get_next_line(fd5, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
/*	if (get_next_line(fd4, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
	}*/
	if (get_next_line(fd3, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
	return (0);
}
