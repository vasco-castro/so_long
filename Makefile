NAME = so_long

CC = cc -Wall -Wextra -Werror
MLXFLAGS = -L. -lXext -L. -lX11

# Directories
SRCS_DIR = ./src/
MAPS_DIR = ./maps/
MLX_DIR	= ./minilibx-linux/
MLX = $(MLX_DIR)/libmlx.a

# Source files (with directories applied)
MAIN_SRCS = $(addsuffix .c, $(addprefix $(SRCS_DIR), so_long))

# MAPS_FTS = ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_islower ft_isupper
# MAPS_SRCS = $(addsuffix .c, $(addprefix $(MAPS_DIR), $(MAPS_FTS)))

SRCS = $(MAIN_SRCS) #$(MAPS_SRCS)

# Object files convertion
OBJS := $(SRCS:%.c=%.o)

# MAKEFILE RULES
all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	@echo "Building $(NAME)."
	@$(CC) $(OBJS) $(MLX) $(MLXFLAGS) -o $(NAME)

$(MLX):
	@echo "Building $(MLX)."
	@make -s -C $(MLX_DIR)

clean:
	@echo "Cleaning all objects."
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning all $(NAME) files."
	@rm -f $(NAME)
	@make clean -s -C $(MLX_DIR)

re: fclean all

.DEFAULT_GOAL := all

.PHONY: all clean fclean re t