NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRCS_DIR = ./srcs
INC_DIR = ./includes
OBJ_DIR = ./obj
LIBS_DIR = ./libs

SRCS =	main.c \
		calculate.c \
		validation.c \
		checkfile.c \
		additional.c

OBJ = $(addprefix $(OBJ_DIR)/,$(SRCS:%.c=%.o))

all:
	@$(MAKE) -C $(LIBS_DIR)/libft
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) -L$(LIBS_DIR)/libft -lft $(OBJ) -o $(NAME)
	@echo "Compile build"

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@gcc $(FLAGS) -I$(INC_DIR) -I$(LIBS_DIR)/libft/includes -o $@ -c $<
	@echo "Compile object files"

clean:
	@$(MAKE) clean -C $(LIBS_DIR)/libft
	@rm -rf $(OBJ_DIR)
	@echo "Clean object files"

fclean: clean
	@$(MAKE) fclean -C $(LIBS_DIR)/libft
	@rm -f $(NAME)
	@echo "Clean build"

re: fclean all

.PHONY: all fclean clean re