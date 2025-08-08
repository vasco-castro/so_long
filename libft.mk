
LIBFT_DIR = $(INCLUDES_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR)/inc

#Check if both flags (-s -C) can be together
#Run git commands for the submodule before running anything else
$(LIBFT):
	@echo "$(GREEN)Building LIBFT.$(RESET)"
	@make -s -C $(LIBFT_DIR)