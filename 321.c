#include "get_next_line.h"
#include <stdio.h>

static int		ft_put_in_line(char *tmp, char **line)
{
	char	*p;
	int		a;

	if (!(p = ft_strchr(tmp, '\n')))
	{
		if (ft_strlen(tmp) > 0)
		{
			*line = ft_strdup(tmp);
			free(tmp);
			return (1);
		}
		free(tmp);
		return (0);
	}
	a = p - tmp;
	*line = ft_strsub(tmp, 0, a);
	free(tmp);
	return (1);
}

static	void	ft_check(char **head, char **tmp)
{
	char *p;

	if (!(p = ft_strchr(*head, '\n')))
		*tmp = ft_strnew(0);
	else
	{
		*tmp = ft_strdup(p + 1);
		*p = ' ';
	}
}

int				get_next_line(const int fd, char **line)
{
	int				res;
	char			*tmp;
	char			*clean;
	static char		*head;

	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	if (!head)
		head = ft_strnew(BUFF_SIZE + 1);
	ft_check(&head, &tmp);
	while (!ft_strchr(tmp, '\n') &&
	(res = read(fd, head, BUFF_SIZE)) > 0)
	{
		head[res] = '\0';
		clean = tmp;
		tmp = ft_strjoin(tmp, head);
		free(clean);
	}
	if (res == -1)
		return (-1);
	return (ft_put_in_line(tmp, line));
}
/*
int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
//	int 	a;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDWR);
	else
		return (2);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
//	get_next_line(fd, &line);
//	printf("%s", line);
//	free(line);
//	printf("%lu %lu\n", sizeof(t_list), sizeof(t_str));
	if (argc == 2)
		close(fd);
//	system("leaks a.out");
}
 */