#include <stdio.h>
#include "get_next_line.h"

/*

int 		cycle(char *str)
{
	char 	*buff;
	int 	fd;
	ssize_t infa = 0;

	fd = 0;
	while (!ft_strchr(str, '\n')
	{
		buff[infa] = '\0';
		str = ft_strjoin(str, buff);
		if (infa == -1)
			return (-1);
	}
}

*/

int			get_next_line(const int fd, char **line)
{
	int			i;
	char		*k;
	ssize_t 	infa;
	char 		*buff;
	static char *str = NULL;

	
	k = 0;
	if (fd < 0 || !line || (read(fd, (char *)(&i), 0)))
		return (-1);
	i = 0;
	if (str == NULL)
		str = ft_strnew(0);
	buff = ft_strnew(BUFF_SIZE + 1);
//	cycle(str, infa);
	while (!(k = ft_strchr(str, '\n')) && (infa = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[infa] = '\0';
		str = ft_strjoin(str, buff);
	}
	while (str[i] && str[i] != '\n')
		i++;
	*line = ft_strsub(str, 0, i);
	str = ft_strdup(str + i + 1);
/*	if (!k && i)
		return (1);*/
	if (infa == 0 && str[0] == '\0')
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	int 	fd;
	char 	*line;

	line = NULL;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd , &line) == 1)
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}
