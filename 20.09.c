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
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

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
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	*line = ft_strsub(buff, 0, i + 1);
	lst->data_xvost = ft_strsub(buff, i + 1, ft_strlen(buff) - i);
	printf("%s", lst->data_xvost);
//	*buff = *lst->data;
//	buff = NULL;
//	buff = ft_strnew(BUFF_SIZE);
}


// static void		ft_check_lst(t_str *lst, char *buff, char **line)
// {
// 	if (lst->data)
// 	{
// 		if (ft_strchr(lst->data, '\n'))
// 		{
// 			ft_bzero(buff, ft_strlen(buff));
// 			ft_check_n(lst, buff, line);
// 		}
// 	}
// 	else
// 		lst->data = "";
// }

int				get_next_line(const int fd, char **line)
{
	static	t_str	lst;
	char			*buff;
	int				flag;

	flag = 0;
	if (fd < 0 || !line)
		return (-1);
	lst.fd = fd;
	buff = ft_strnew(BUFF_SIZE);
	lst.data = ft_strnew(BUFF_SIZE);
//	ft_check_fd(&memory, &buff, fd);
	while (/*!ft_strchr(buff, '\n') &&*/
	(flag = read(lst.fd, lst.data, BUFF_SIZE)) > 0)
	{
		lst.data[flag] = '\0';
		buff = ft_strjoin(buff, lst.data);
	}
	ft_check_n(&lst, buff, line);
//	printf("%d\n", flag);
//	printf("%s\n", buff);
//	printf("%d\n", i);
//	ft_check_n(&lst, buff, line);
//	if (lst.data)
/*	if ((!i && !flag && ft_strlen(lst.data)) > 0)
	{
		ft_check_n(&lst, lst.data, line);
		printf("%s\n", lst.data);
	}*/
//	ft_check_n(&lst, buff, line);
//	printf("%s\n", *line);
	if (flag == -1)
		return (-1);
	return (1);
}
------------------------------------------------------
/*
ft_check_mlfd(&memory, &lst, fd);
static void		ft_check_mlfd(t_str **memory, t_str **lst, int fd)
{
	if (!(*memory))
	{
		*memory = (t_str *)malloc(sizeof(t_str));
		(*memory)->data[BUFF_SIZE] = '\0';
		(*memory)->fd = fd;
	}
	*lst = *memory;
	while ((*lst)->fd != fd && (*lst)->next)
		*lst = (*lst)->next;
	if ((*lst)->fd != fd)
	{
		(*lst)->next = (t_str *)malloc(sizeof(t_str));
		*lst = (*lst)->next;
		(*lst)->data[BUFF_SIZE] = '\0';
		(*lst)->fd = fd;
	}
}
*/
/*
//	ft_check_n(buff, line, data_xvost);
static void		ft_check_n(char *buff, char **line, char **data_xvost)
{
	int		i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	*line = ft_strsub(buff, 0, i + 1);
	*data_xvost = ft_strsub(buff, i + 1, ft_strlen(buff) - i);
}

*/