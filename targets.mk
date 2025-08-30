# Directories
SRCS_DIR = ./src
LIB_DIR = ./lib

# Source files (with directories applied)
SRCS = $(addsuffix .c, \
	$(addprefix $(SRCS_DIR)/, \
		so_long error_handling \
		handlers/handlers handlers/moves handlers/moves2 \
		parsing/parsing parsing/ft_floodfill \
		rendering/image rendering/rendering \
	) \
)

# Object files convertion
OBJS := $(SRCS:%.c=%.o)

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	MLX_DIR	= $(LIB_DIR)/minilibx-linux
	MLX = $(MLX_DIR)/libmlx.a
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11
else ifeq ($(UNAME_S),Darwin)
	MLX_DIR	= $(LIB_DIR)/minilibx-opengl
	MLX = $(MLX_DIR)/libmlx.a
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

LIBFT_DIR = $(LIB_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR)/include

#Check if both flags (-s -C) can be together
#Run git commands for the submodule before running anything else
$(LIBFT):
	@echo "$(GREEN)Building LIBFT.$(RESET)"
# 	@git submodule update --init $(LIBFT_DIR)
	@make -s -C $(LIBFT_DIR)

#Check if both flags (-s -C) can be together
#Run git commands for the submodule before running anything else
$(MLX):
	@echo "$(GREEN)Building MLX.$(RESET)"
# 	@git submodule update --init $(MLX_DIR)
	@make -s -C $(MLX_DIR)
