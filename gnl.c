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
	if (!memory)
	{
		memory = (t_str *)ft_lstnew(*buff, BUFF_SIZE);
		(*memory).fd = fd;
		free(*buff);
	}
	while ((*memory).fd != fd && (*memory).next)
		memory = (*memory).next;
	if ((*memory).fd != fd)
	{
		(*memory).next = (t_str *)ft_lstnew(*buff, BUFF_SIZE);
		(*memory).fd = fd;
		free(*buff);
	}
}
*/
static int		ft_check_n(t_str *lst, char *buff, char **line)
{
	int 	i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	*line = ft_strsub(buff, 0, i + 1);
	lst->data_xvost = ft_strsub(buff, i + 1, ft_strlen(buff) - i);
	free(buff);
	return (1);
//	printf("%s", lst->data);
//	*buff = *lst->data;
/*	buff = NULL;
	buff = ft_strnew(BUFF_SIZE);
*/
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
//	t_str			memory;
	static char		*buff;
//	char			*clean;
	int				flag;

	flag = 0;
	if (fd < 0 || !line)
		return (-1);
//	lst.fd = fd;
	lst.data = ft_strnew(BUFF_SIZE);
	lst.data_xvost = ft_strnew(BUFF_SIZE);
	buff = ft_strnew(BUFF_SIZE);
//	ft_check_fd(&memory, &buff, fd);
	while (/*!ft_strchr(, '\n') &&*/
	(flag = read(lst.fd, lst.data, BUFF_SIZE)) > 0)
	{
//		lst.data[flag] = '\0';
//		clean = buff;
		buff = ft_strjoin(buff, lst.data);
//		free(clean);
	}
//		printf("%s", buff);
	ft_check_n(&lst, buff, line);
/*	if ((!flag && lst.data_xvost) > 0)
	{
		ft_check_n(&lst, lst.data_xvost, line);
	}*/
//	ft_check_n(&lst, lst.data, line);
	if (flag == -1)
		return (-1);
}