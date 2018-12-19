NAME = libft.a
FLAGS = -Wall -Wextra -Werror -I includes/ -c -g
FILES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
    ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
    ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar.c ft_putstr.c \
    ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c \
    ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
    ft_strnstr.c ft_strrchr.c ft_strstr.c ft_tolower.c ft_toupper.c \
    ft_memalloc.c ft_memdel.c ft_memdel.c ft_strdel.c ft_strclr.c \
    ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
    ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
    ft_itoa.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
    ft_putendl_fd.c ft_putnbr_fd.c ft_strnew.c \
	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	ft_lstmap.c ft_lstpush.c ft_lstremove.c

OBJ = $(FILES:%.c=%.o)

all:
	@$(MAKE) $(NAME)

$(NAME):
	#$(OBJ)
	@echo "Building..."
	@gcc $(FLAGS) $(FILES)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Build completed"

# %.o: %.c
# 	gcc $(FLAGS) -c $^ -o $@

copy:
	@cp -f libc/*.c .
	@cp -f additional/*.c .
	@cp -f bonus/*.c .
	@cp -f extend/*.c .
	@echo "Source files copied to root"

test: re
	gcc -g -I. tests/main.c -L. -lft -o test_libft

clean:
	@rm -f $(OBJ)
	#@rm -f $(FILES)
	@echo "Object files removed"

fclean: clean
	@rm -f $(NAME)
	@echo "Build removed"

re: fclean all

.PHONY: all copy clean fclean test re