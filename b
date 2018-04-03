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
			 return (1);
		}
		else
			*line = ft_strsub(*buff, 0, i);
		*buff = ft_strsub(*buff, i + 1, ft_strlen(*buff) - i);
		ft_strdel(&tmp);
	}
	len = ft_strlen(*line);
	len = len > 0 ? 1 : 0;
	return (len);
}

int				get_next_line(const int fd, char **line)
{
//	t_str static 	*memory;
//	t_str 			*lst;
	char			data[BUFF_SIZE + 1];
	static char		*buff;
	char 			*clean;
	int 			flag;

	flag = 0;
	if (line)
		*line = NULL;
	if (fd < 0 || !line || read(fd, data, 0) < 0)
		return (-1);
	if (!buff)
		buff = ft_strnew(0);
	while ((flag = read(fd, data, BUFF_SIZE)) > 0)
	{
		data[flag] = '\0';
		clean = buff;
		buff = ft_strjoin(clean, data);
		ft_strdel(&clean);
		if (buff && ft_strchr(buff, '\n'))
			break ;
	}
	flag = ft_check_n(&buff, line);
	return (flag);
}