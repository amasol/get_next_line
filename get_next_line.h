/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:36:24 by amasol            #+#    #+#             */
/*   Updated: 2018/03/15 16:14:39 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./libft/libft.h"

# define BUFF_SIZE 10

typedef struct		s_str
{
	int				fd;
	char			data[BUFF_SIZE + 1];
	char			*buff;
	struct s_str	*next;
}					t_str;

typedef struct		s_help
{
	int				j;
	int				i;
	char			*tmp;
	int				len;
}					t_help;

int					get_next_line(const int fd, char **line);

#endif
