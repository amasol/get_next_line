#include "get_next_line.h"
#include "./libft/libft.h"

int		main(int ac, char **av)
{
	int fd3;
	int fd4;
	int fd5;
	int fd6;
	char *line;

	line = NULL;
	fd3 = open("test", O_RDONLY);
	fd4 = open("test2", O_RDONLY);
	fd5 = open("test3", O_RDONLY);
	fd6 = open("test4", O_RDONLY);
	if (get_next_line(fd3, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
		line = NULL;
	}
	if (get_next_line(fd5, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
		line = NULL;
	}
	if (get_next_line(fd4, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
	if (get_next_line(fd3, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
		line = NULL;
	}
	if (get_next_line(fd5, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
		line = NULL;
	}
	if (get_next_line(fd5, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
		line = NULL;
	}
	if (get_next_line(fd6, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
		line = NULL;
	}
	return (0);
}

/*
int		main(int ac, char **av)
{
	int 	fd;
	char 	*line;
	int i;

	i = 6;
	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (ac != 2)
		return (0);
	while (i)
	{
		get_next_line(fd , &line);
//		ft_putstr(line);
		free(line);
		i--;
	}
	close(fd);
	return (0);
}
*/
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
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) > 0)
	{
//		printf("%s\n", line);
//		free(line);
	}
	if (argc == 2)
		close(fd);
//	system("leaks a.out");
}
*/
/*
int			main(int ac, char **av)
{
	int 	fd;
	int 	fd1;
	char 	*line;

	line = NULL;
	fd = open(av[1], O_RDONLY);
	fd1 = open(av[2], O_RDONLY);
	if (get_next_line(fd , &line) > 0)
		printf("%s\n", line);
	if (get_next_line(fd1 , &line) > 0)
		printf("%s\n", line);
	if (get_next_line(fd , &line) > 0)
		printf("%s\n", line);
	//ft_putendl(line);
	ft_strdel(&line);
	close(fd);
	return (0);
}
*/
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