# Directories
SRC_DIR	:= ./srcs
OBJ_DIR	:= ./objs
INC_DIR	:= ./includes
LIB_DIR	:= ./lib
MK_DIR	:= ./mk

# Source files organized by folder, using addprefix and addsuffix
SRC_MAIN		:= main
SRC_GRAPHICS	:= $(addprefix graphics/, rendering load_textures put_textures put_sprites)
SRC_HANDLERS	:= $(addprefix handlers/, handlers moves)
SRC_PARSING		:= $(addprefix parsing/, parse_map validate_map)
SRC_UTILS		:= $(addprefix utils/, error_handling memory)

# All source files
SRC := $(addsuffix .c, $(SRC_MAIN) $(SRC_GRAPHICS) $(SRC_HANDLERS) $(SRC_PARSING) $(SRC_UTILS) )

# Object files convertion
OBJ := $(SRC:.c=.o)
OBJ := $(addprefix $(OBJ_DIR)/, $(OBJ))

UNAME_S := $(shell uname -s)

# MLX Linking and Compilation Flags
ifeq ($(UNAME_S),Linux)
	MLX_DIR		:= $(LIB_DIR)/minilibx-linux
	MLX			:= $(MLX_DIR)/libmlx.a
	MLX_FLAGS	:= -L$(MLX_DIR) -lmlx -lXext -lX11
else ifeq ($(UNAME_S),Darwin)
	MLX_DIR		:= $(LIB_DIR)/minilibx-opengl
	MLX			:= $(MLX_DIR)/libmlx.a
	MLX_FLAGS	:= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

$(MLX_DIR)/.git:
	@git submodule update --init --quiet $(MLX_DIR)

$(MLX): $(MLX_DIR)/.git
	@printf "$(GREEN)Building MLX.$(RESET)\n"
	@make -s -C $(MLX_DIR) > /dev/null 2> /dev/null

# LIBFT linking and compilation flags
LIBFT_DIR	:= $(LIB_DIR)/libft
LIBFT		:= $(LIBFT_DIR)/libft.a
LIBFT_FLAGS	:= -L$(LIBFT_DIR)/includes

$(LIBFT_DIR)/.git:
	@git submodule update --init --quiet $(LIBFT_DIR)

$(LIBFT): $(LIBFT_DIR)/.git
	@printf "$(GREEN)Building LIBFT.$(RESET)\n"
	@make -s -C $(LIBFT_DIR) > /dev/null 2> /dev/null
