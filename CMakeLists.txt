cmake_minimum_required(VERSION 3.31)
project(cub3D C)

set(CMAKE_C_STANDARD 11)

include_directories(lib/jal/include include lib/mlx)

add_executable(cub3D
        lib/jal/include/jal_char.h
        lib/jal/include/jal_colour.h
        lib/jal/include/jal_conversion.h
        lib/jal/include/jal_error.h
        lib/jal/include/jal_gnl.h
        lib/jal/include/jal_list.h
        lib/jal/include/jal_memory.h
        lib/jal/include/jal_print.h
        lib/jal/include/jal_string.h
        lib/jal/src/char/ft_isalnum.c
        lib/jal/src/char/ft_isalpha.c
        lib/jal/src/char/ft_isascii.c
        lib/jal/src/char/ft_isdigit.c
        lib/jal/src/char/ft_isprint.c
        lib/jal/src/conversion/atoll_valid.c
        lib/jal/src/conversion/ft_atoi.c
        lib/jal/src/conversion/ft_itoa.c
        lib/jal/src/conversion/ft_tolower.c
        lib/jal/src/conversion/ft_toupper.c
        lib/jal/src/error/error.c
        lib/jal/src/gnl/get_next_line.c
        lib/jal/src/gnl/get_next_line_utils.c
        lib/jal/src/list/ft_lstadd_back_bonus.c
        lib/jal/src/list/ft_lstadd_front_bonus.c
        lib/jal/src/list/ft_lstclear_bonus.c
        lib/jal/src/list/ft_lstdelone_bonus.c
        lib/jal/src/list/ft_lstiter_bonus.c
        lib/jal/src/list/ft_lstlast_bonus.c
        lib/jal/src/list/ft_lstmap_bonus.c
        lib/jal/src/list/ft_lstnew_bonus.c
        lib/jal/src/list/ft_lstsize_bonus.c
        lib/jal/src/list/lstdel_safely.c
        lib/jal/src/list/lstdetach.c
        lib/jal/src/list/lstdup.c
        lib/jal/src/list/lstget_int.c
        lib/jal/src/list/lstnew_int.c
        lib/jal/src/memory/free_matrix.c
        lib/jal/src/memory/free_partial_matrix.c
        lib/jal/src/memory/ft_bzero.c
        lib/jal/src/memory/ft_calloc.c
        lib/jal/src/memory/ft_memchr.c
        lib/jal/src/memory/ft_memcmp.c
        lib/jal/src/memory/ft_memcpy.c
        lib/jal/src/memory/ft_memmove.c
        lib/jal/src/memory/ft_memset.c
        lib/jal/src/memory/realloc.c
        lib/jal/src/memory/sort_tab.c
        lib/jal/src/print/ft_printf.c
        lib/jal/src/print/ft_putchar_fd.c
        lib/jal/src/print/ft_putendl_fd.c
        lib/jal/src/print/ft_putnbr_fd.c
        lib/jal/src/print/ft_putstr_fd.c
        lib/jal/src/print/put_characters.c
        lib/jal/src/print/put_numbers.c
        lib/jal/src/string/ft_split.c
        lib/jal/src/string/ft_strcat.c
        lib/jal/src/string/ft_strchr.c
        lib/jal/src/string/ft_strcmp.c
        lib/jal/src/string/ft_strdup.c
        lib/jal/src/string/ft_striteri.c
        lib/jal/src/string/ft_strjoin.c
        lib/jal/src/string/ft_strlcat.c
        lib/jal/src/string/ft_strlcpy.c
        lib/jal/src/string/ft_strlen.c
        lib/jal/src/string/ft_strmapi.c
        lib/jal/src/string/ft_strncmp.c
        lib/jal/src/string/ft_strnstr.c
        lib/jal/src/string/ft_strrchr.c
        lib/jal/src/string/ft_strtrim.c
        lib/jal/src/string/ft_substr.c
        lib/jal/src/string/intlen.c
        lib/jal/src/string/strarrcount.c
        lib/jal/src/string/strarrdup.c
        lib/jal/src/string/strcpy.c
        lib/jal/src/string/strjoin_free.c
        lib/jal/src/string/strndup.c
        lib/jal/Makefile
)

