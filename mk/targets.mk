
# Directories
SRCS_DIR		:= srcs/
OBJS_DIR		:= objs/
INCS_DIR		:= includes/
LIBS_DIR		:= libs/

CFLAGS			+= -I./ -I$(INCS_DIR)

# Source files organized by folder, using addprefix and addsuffix
SRC_MAIN		:= main
SRC_GRAPHICS	:= $(addprefix graphics/, rendering load_textures put_textures put_sprites)
SRC_HANDLERS	:= $(addprefix handlers/, handlers moves)
SRC_PARSING		:= $(addprefix parsing/, parse_map validate_map)
SRC_UTILS		:= $(addprefix utils/, error_handling memory)

# All source files
SRCS			:= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_MAIN) $(SRC_GRAPHICS) $(SRC_HANDLERS) $(SRC_PARSING) $(SRC_UTILS)))

# Create object files and dependency files from source files
OBJS 			:= $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)
DEPS 			:= $(OBJS:.o=.d)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)
# LIBFT linking and compilation flags
LIBFT_DIR		:= $(LIBS_DIR)libft/
LIBFT			:= $(LIBFT_DIR)libft.a
LIBFT_FLAGS		:= -L$(LIBFT_DIR) -lft

CFLAGS			+= -I$(LIBFT_DIR)

$(LIBFT_DIR).git:
	@git submodule update --init --quiet $(LIBFT_DIR)

$(LIBFT): $(LIBFT_DIR).git
	@printf "$(GREEN)Building LIBFT.$(RESET)\n"
	@make -sC $(LIBFT_DIR) > /dev/null 2> /dev/null

UNAME_S			:= $(shell uname -s)

# MLX Linking and Compilation Flags
ifeq ($(UNAME_S),Linux)
	MLX_DIR		:= $(LIBS_DIR)minilibx-linux/
	MLX			:= $(MLX_DIR)libmlx.a
	MLX_FLAGS	:= -L$(MLX_DIR) -lmlx -lXext -lX11
else ifeq ($(UNAME_S),Darwin)
	MLX_DIR		:= $(LIBS_DIR)minilibx-opengl/
	MLX			:= $(MLX_DIR)libmlx.a
	MLX_FLAGS	:= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

CFLAGS			+= -I$(MLX_DIR)

$(MLX_DIR).git:
	@git submodule update --init --quiet $(MLX_DIR)

$(MLX): $(MLX_DIR).git
	@printf "$(GREEN)Building MLX.$(RESET)\n"
	@make -sC $(MLX_DIR) > /dev/null 2> /dev/null


