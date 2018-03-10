/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:36:24 by amasol            #+#    #+#             */
/*   Updated: 2018/02/22 17:36:26 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	 GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"

# define BUFF_SIZE 20

int		get_next_line(const int fd, char **line);

# endif
