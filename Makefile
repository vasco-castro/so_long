# **************************************************************************** #
#                               CONFIGURATION                                  #
# **************************************************************************** #

include libft.mk
NAME        := so_long
# Directories
SRCS_DIR = ./src
INCLUDES_DIR = ./inc
MAPS_DIR = ./maps

# Source files (with directories applied)
SRCS = $(addsuffix .c, \
	$(addprefix $(SRCS_DIR)/, \
		so_long error_handling \
		handlers/handlers handlers/moves handlers/moves2 \
		parsing/parsing parsing/ft_floodfill \
		rendering/image rendering/rendering \
	) \
)
OBJS         := $(SRCS:.c=.o)

UNAME_S     := $(shell uname -s)

# Default empty values (will be set per OS)
MLX_DIR     :=
MLX_FLAGS   :=
MLX_LIB     :=

CC          := cc
CFLAGS      := -Wall -Wextra -Werror

# **************************************************************************** #
#                             OS DETECTION                                     #
# **************************************************************************** #

ifeq ($(UNAME_S), Darwin) # macOS
	MLX_DIR   := $(INCLUDES_DIR)/minilibx_opengl
	MLX_FLAGS := -framework OpenGL -framework AppKit
	MLX_LIB   := -L$(MLX_DIR) -lmlx
else ifeq ($(UNAME_S), Linux)
	MLX_DIR   := $(INCLUDES_DIR)/minilibx-linux
	MLX_FLAGS := -lXext -lX11 -lm
	MLX_LIB   := -L$(MLX_DIR) -lmlx
endif

# **************************************************************************** #
#                                 RULES                                        #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBFT_FLAGS) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
