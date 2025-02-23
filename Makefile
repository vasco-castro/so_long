NAME = so_long

CC = cc -Wall -Wextra -Werror

# Directories
SRCS_DIR = ./src
INCLUDES_DIR = ./includes
MAPS_DIR = ./maps

#Libraries and it's directories
MLX_DIR	= $(INCLUDES_DIR)/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L. -lXext -L. -lX11

LIBFT_DIR = $(INCLUDES_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR)

# Source files (with directories applied)
SRCS = $(addsuffix .c, $(addprefix $(SRCS_DIR)/, so_long handlers parsing))

# Object files convertion
OBJS := $(SRCS:%.c=%.o)

# MAKEFILE RULES
all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	@echo "\033[1;35mBuilding $(NAME).\033[0m"
	@$(CC) $(OBJS) $(LIBFT) $(LIBFT_FLAGS) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	@echo "\033[1;32mBuilding $(LIBFT).\033[0m"
	@make -s -C $(LIBFT_DIR)

$(MLX):
	@echo "\033[1;32mBuilding $(MLX).\033[0m"
	@make -s -C $(MLX_DIR)

clean:
	@echo "\033[1;31mCleaning objects...\033[0m"
	@rm -f $(OBJS)

fclean: clean
	@echo "\033[1;31mCleaning binaries...\033[0m"
	@rm -f $(NAME)
	@make clean -s -C $(MLX_DIR)
	@make fclean -s -C $(LIBFT_DIR)

re: fclean all

.DEFAULT_GOAL := all

.PHONY: all clean fclean re t