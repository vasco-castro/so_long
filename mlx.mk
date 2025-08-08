

# MLX
UNAME_S     := $(shell uname -s)

# MLX_DIR     :=
# MLX_FLAGS   :=
# MLX_LIB     :=

# ifeq ($(UNAME_S), Darwin) # macOS
# 	MLX_DIR   := $(INCLUDES_DIR)/minilibx_opengl
# 	MLX_FLAGS := -framework OpenGL -framework AppKit
# 	MLX_LIB   := -L$(MLX_DIR) -lmlx
# else ifeq ($(UNAME_S), Linux)
# 	MLX_DIR   := $(INCLUDES_DIR)/minilibx-linux
# 	MLX_FLAGS := -lXext -lX11 -lm
# 	MLX_LIB   := -L$(MLX_DIR) -lmlx
# endif

#Libraries and it's directories
MLX_DIR	= $(INCLUDES_DIR)/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L. -lXext -L. -lX11

#Check if both flags (-s -C) can be together
#Run git commands for the submodule before running anything else
$(MLX):
	@echo "$(GREEN)Building MLX.$(RESET)"
	@make -s -C $(MLX_DIR)