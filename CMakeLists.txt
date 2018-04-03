cmake_minimum_required(VERSION 3.8)
project(gnl)

set(CMAKE_C_STANDARD 99)

# You need to download and compile the Libft specificly for you machine
# put header file and .a file in "Libft" folder in your project
#link_directories(${PROJECT_SOURCE_DIR}/libft)
#include_directories(${PROJECT_SOURCE_DIR}/libft)

set(SOURCE_FILES get_next_line.c get_next_line.h main.c)

add_executable(gnl ${SOURCE_FILES}
        libft/ft_strdup.c
        libft/ft_strdel.c
        libft/ft_strchr.c
        libft/ft_strjoin.c
        libft/ft_strnew.c
        libft/ft_memcpy.c
        libft/ft_strlen.c
        libft/ft_bzero.c
        libft/ft_putstr.c
        libft/ft_putchar.c)
#target_link_libraries(gnl -lft)
