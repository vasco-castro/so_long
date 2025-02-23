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

FT_PRINTF_DIR = $(INCLUDES_DIR)/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_FLAGS = -L$(FT_PRINTF_DIR)

GNL_DIR = $(INCLUDES_DIR)/get_next_line
GNL = $(GNL_DIR)/get_next_line.a

# Source files (with directories applied)
SRCS = $(addsuffix .c, $(addprefix $(SRCS_DIR)/, so_long handlers parsing))

# Object files convertion
OBJS := $(SRCS:%.c=%.o)

# MAKEFILE RULES
all: $(NAME)

$(NAME): $(MLX) $(FT_PRINTF) $(GNL) $(OBJS)
	@echo "\033[1;35mBuilding $(NAME).\033[0m"
	@$(CC) $(OBJS) $(FT_PRINTF) $(FT_PRINTF_FLAGS) $(GNL) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(FT_PRINTF):
	@echo "\033[1;32mBuilding $(FT_PRINTF).\033[0m"
	@make -s -C $(FT_PRINTF_DIR)

$(GNL):
	@echo "\033[1;32mBuilding $(GNL).\033[0m"
	@make -s -C $(GNL_DIR)

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
	@make fclean -s -C $(FT_PRINTF_DIR)
	@make fclean -s -C $(GNL_DIR)

re: fclean all

.DEFAULT_GOAL := all

.PHONY: all clean fclean re t