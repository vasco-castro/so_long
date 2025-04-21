include colors.mk

NAME = so_long

CC = cc -Wall -Wextra -Werror

# Directories
SRCS_DIR = ./src
INCLUDES_DIR = ./inc
MAPS_DIR = ./maps

#Libraries and it's directories
MLX_DIR	= $(INCLUDES_DIR)/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L. -lXext -L. -lX11

LIBFT_DIR = $(INCLUDES_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR)/inc

# Source files (with directories applied)
SRCS = $(addsuffix .c, $(addprefix $(SRCS_DIR)/, so_long error_handling handlers/handlers handlers/moves parsing/parsing parsing/ft_floodfield rendering/image rendering/rendering rendering/render_image))

# Object files convertion
OBJS := $(SRCS:%.c=%.o)

# MAKEFILE RULES
all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	@echo "$(GREEN)Building $(NAME).$(RESET)"
	@$(SO_BANNER)
	@$(CC) $(OBJS) $(LIBFT) $(LIBFT_FLAGS) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	@echo "$(GREEN)Building LIBFT.$(RESET)"
	@make -s -C $(LIBFT_DIR)

$(MLX):
	@echo "$(GREEN)Building MLX.$(RESET)"
	@make -s -C $(MLX_DIR)

clean:
	@echo "$(YELLOW)Cleaning objects.$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(YELLOW)Cleaning binaries.$(RESET)"
	@rm -f $(NAME)
	@make clean -s -C $(MLX_DIR)
	@make fclean -s -C $(LIBFT_DIR)

re: fclean all

.DEFAULT_GOAL := all

.PHONY: all clean fclean re t