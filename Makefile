include colors.mk
include config.mk
include targets.mk

NAME = so_long

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	@echo "$(GREEN)Building $(NAME).$(RESET)"
	@$(SO_BANNER)
	@$(COMPILE) $(OBJS) $(LIBFT) $(LIBFT_FLAGS) $(MLX) $(MLX_FLAGS) -o $(NAME)

#Check if both flags (-s -C) can be together
clean:
	@echo "$(YELLOW)Cleaning objects.$(RESET)"
	@$(REMOVE) $(OBJS)

#Check if both flags (-s -C) can be together
fclean: clean
	@echo "$(YELLOW)Cleaning binaries.$(RESET)"
	@$(REMOVE) $(NAME)
	@make clean -s -C $(MLX_DIR)
	@make fclean -s -C $(LIBFT_DIR)

re: fclean all