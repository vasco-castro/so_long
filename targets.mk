# Directories
SRCS_DIR = ./src
LIB_DIR = ./lib


# Source files organized by folder, using addprefix and addsuffix
SRCS_MAIN = main
SRCS_GRAPHICS = $(addprefix graphics/, rendering load_textures put_textures put_sprites)
SRCS_HANDLERS = $(addprefix handlers/, handlers moves)
SRCS_PARSING = $(addprefix parsing/, parsing ft_floodfill)
SRCS_UTILS = $(addprefix utils/, error_handling memory)

# All source files
SRCS = $(addprefix $(SRCS_DIR)/, \
	$(addsuffix .c, \
		$(SRCS_MAIN) \
		$(SRCS_GRAPHICS) \
		$(SRCS_HANDLERS) \
		$(SRCS_PARSING) \
		$(SRCS_UTILS) \
	) \
)

# Object files convertion
OBJS := $(SRCS:%.c=%.o)

UNAME_S := $(shell uname -s)

# MLX Linking and Compilation Flags
ifeq ($(UNAME_S),Linux)
	MLX_DIR	= $(LIB_DIR)/minilibx-linux
	MLX = $(MLX_DIR)/libmlx.a
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11
else ifeq ($(UNAME_S),Darwin)
	MLX_DIR	= $(LIB_DIR)/minilibx-opengl
	MLX = $(MLX_DIR)/libmlx.a
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

$(MLX_DIR)/.git:
	git submodule update --init $(MLX_DIR)

$(MLX): $(MLX_DIR)/.git
	@printf "$(GREEN)Building MLX.$(RESET)\n"
	@make -s -C $(MLX_DIR)

# LIBFT linking and compilation flags
LIBFT_DIR = $(LIB_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR)/include

$(LIBFT_DIR)/.git:
	git submodule update --init $(LIBFT_DIR)

$(LIBFT): $(LIBFT_DIR)/.git
	@printf "$(GREEN)Building LIBFT.$(RESET)\n"
	@make -s -C $(LIBFT_DIR)
