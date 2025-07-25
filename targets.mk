# Directories
SRCS_DIR = ./src
INCLUDES_DIR = ./inc
MAPS_DIR = ./maps

# Source files (with directories applied)
SRCS = $(addsuffix .c, $(addprefix $(SRCS_DIR)/, so_long error_handling handlers/handlers handlers/moves handlers/moves2 parsing/parsing parsing/ft_floodfield rendering/image rendering/rendering))

# Object files convertion
OBJS := $(SRCS:%.c=%.o)

#Libraries and it's directories
MLX_DIR	= $(INCLUDES_DIR)/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L. -lXext -L. -lX11

LIBFT_DIR = $(INCLUDES_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR)/inc

#Check if both flags (-s -C) can be together
$(LIBFT):
	@echo "$(GREEN)Building LIBFT.$(RESET)"
	@make -s -C $(LIBFT_DIR)

#Check if both flags (-s -C) can be together
$(MLX):
	@echo "$(GREEN)Building MLX.$(RESET)"
	@make -s -C $(MLX_DIR)