/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:36:14 by amasol            #+#    #+#             */
/*   Updated: 2018/03/16 17:51:26 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
static void		ft_check_fd(t_str *memory, char **buff, int fd)
{
	if (!(memory))
	{
		memory = (t_str *)ft_lstnew(*buff, BUFF_SIZE);
		(*memory).size = fd;
		free(*buff);
	}
	while ((*memory).size != fd && (*memory).next)
		memory = (*memory).next;
	if ((*memory).size != fd)
	{
		(*memory).next = (t_str *)ft_lstnew(*buff, BUFF_SIZE);
		(*memory).size = fd;
		free(*buff);
	}
}
*/
static void		ft_check_n(t_str *lst, char *buff, char **line)
{
	int 	i;
	int		j;
//	char 	*tmp;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	*line = ft_strsub(buff, 0, i + 1);
	lst->cont = ft_strsub(buff, i + 1, ft_strlen(buff) - i);
//	*buff = *lst->cont;
//	printf("%s\n", lst->cont);
/*	buff = NULL;
	buff = ft_strnew(BUFF_SIZE);
	buff = lst->cont;
//	printf("%s", lst->cont);
	while (buff[j] && buff[j] != '\n')
		j++;
	*line = ft_strsub(buff, 0, j + 1);
//	*line = ft_strjoin(tmp, lst.cont);
	lst->cont = ft_strsub(buff, j + 1, ft_strlen(buff) - j);
	tmp = ft_strsub();
//	printf("%s", lst->cont);*/
}

static int 		check_n(char *line)
{
	if (!line)
		return (1);
	while(*line && *line != '\n')
		line++;
	if (*line == '\n')
		return (0);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
//	static t_str	memory;
	static	t_str	lst;
	char			*buff;
	int				flag;

	flag = 0;
	if (fd < 0 || !line)
		return (-1);
	lst.size = fd;
	lst.cont = ft_strnew(BUFF_SIZE);
	buff = ft_strnew(BUFF_SIZE);
	/* buff strjoin lst->cont */
//	ft_check_fd(&memory, &buff, fd);
	while (check_n(*line) &&
	(flag = read(lst.size, lst.cont, BUFF_SIZE)) > 0)
	{
		lst.cont[flag] = '\0';
		buff = ft_strjoin(buff, lst.cont);
		ft_check_n(&lst, buff, line);
//		if (ft_strchr(buff, '\n'))
//			break;
//		printf("%s\n", buff);
	}
//	printf("%s\n", buff);
//	printf("%s", *line);
	printf("%s\n", lst.cont);		//находиться хвост
	if (flag == -1)
		return (-1);
	return (0);
}