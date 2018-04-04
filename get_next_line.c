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

static int		ft_check_n(char **buff, char **line, t_str **memory)
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
			(*memory)->buff = ft_strcpy((*memory)->buff, *buff);
			return (1);
		}
		else
			*line = ft_strsub(*buff, 0, i);
		*buff = ft_strsub(*buff, i + 1, ft_strlen(*buff) - i);
		(*memory)->buff = ft_strcpy((*memory)->buff, *buff);
		ft_strdel(&tmp);
	}
	len = ft_strlen(*line);
	len = len > 0 ? 1 : 0;
	return (len);
}


static void		ft_check_fd(t_str **memory, t_str **lst, int fd, char **buff)
{
	if (!(*memory))
	{
		*memory = (t_str *)malloc(sizeof(t_str));
		(*memory)->fd = fd;
		*buff = ft_strnew(BUFF_SIZE);
		(*memory)->buff = ft_strnew(0);
	}
//	(*memory)->buff = ft_strnew(0);
	*lst = *memory;
	*buff = ft_strnew(BUFF_SIZE);
/*	while ((*lst)->fd != fd && (*lst)->next)
		*lst = (*lst)->next;
	if ((*lst)->fd != fd)
	{
		(*lst)->next = (t_str *)malloc(sizeof(t_str));
		*lst = (*lst)->next;
		*buff = ft_strnew(BUFF_SIZE);
		(*memory)->buff = ft_strnew(0);
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
	ft_check_fd(&memory, &lst, fd, &buff);
	*line = NULL;
	if (fd < 0 || !line || read(lst->fd, lst->data, 0) < 0)
		return (-1);
	buff = ft_strcpy(buff, memory->buff);
	while ((flag = read(lst->fd, lst->data, BUFF_SIZE)) > 0)
	{
		lst->data[flag] = '\0';
		clean = buff;
		buff = ft_strjoin(buff, lst->data);
		ft_strdel(&clean);
		if (buff && ft_strchr(buff, '\n'))
			break ;
	}
	flag = ft_check_n(&buff, line, &memory);
	return (flag);
}






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
