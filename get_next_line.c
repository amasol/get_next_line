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

static int		ft_check_n(char **buff, char **line)
{
	int 	j;
	int 	i;
	int 	len;
	char 	*tmp;

	i = 0;
	len = 0;
	tmp = *buff;
	if (*buff)
	{
		while ((*buff)[i] && (*buff)[i] != '\n')
			i++;
		j = 0;
		if ((*buff)[j] == '\n')
		{
			*line = ft_strdup("\0");
			*buff = ft_strsub(*buff, i + 1, ft_strlen(*buff) - i);
			ft_strcpy(&g_buff[0], *buff);
			return (1);
		}
		else
			*line = ft_strsub(*buff, 0, i);
		*buff = ft_strsub(*buff, i + 1, ft_strlen(*buff) - i);
		ft_strdel(&tmp);
	}
	ft_strcpy(&g_buff[0], *buff);
	len = ft_strlen(*line);
	len = len > 0 ? 1 : 0;
	return (len);
}

static void		ft_check_fd(t_str **memory, t_str **lst, char **buff, int fd)
{
	if (!(*memory))
	{
		*memory = (t_str *)malloc(sizeof(t_str));
		(*memory)->fd = fd;
		*buff = ft_strnew(BUFF_SIZE);
	}
	*buff = ft_strnew(BUFF_SIZE);
	*lst = *memory;
/*	while ((*lst)->fd != fd && (*lst)->next)
		*lst = (*lst)->next;
	if ((*lst)->fd != fd)
	{
		(*lst)->next = (t_str *)malloc(sizeof(t_str));
		*lst = (*lst)->next;
//		(*lst)->data[BUFF_SIZE] = '\0';
		*buff = ft_strnew(BUFF_SIZE);
		(*lst)->fd = fd;
//		free(*buff);
	}*/
}
int				get_next_line(const int fd, char **line)
{
	t_str			*lst;
	static t_str	*memory;
	char 			*clean;
	char 			*buff;
	int 			flag;

	flag = 0;
	ft_check_fd(&memory, &lst, &buff, fd);
	*line = NULL;
	if (fd < 0 || !line || read(lst->fd, lst->data, 0) < 0)
		return (-1);
	buff = ft_strjoin(&g_buff[0], buff);
//	ft_bzero(&g_buff[0], ft_strlen(&g_buff[0]));
//	free(&g_buff);
	g_buff[0] = '\0';
	while ((flag = read(lst->fd, lst->data, BUFF_SIZE)) > 0)
	{
		lst->data[flag] = '\0';
		clean = buff;
		buff = ft_strjoin(buff, lst->data);
		ft_strdel(&clean);
		if (buff && ft_strchr(buff, '\n'))
			break ;
	}
	flag = ft_check_n(&buff, line);
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