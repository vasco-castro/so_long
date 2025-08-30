include colors.mk
include config.mk
include targets.mk

NAME = so_long

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	@printf "$(GREEN)Building $(NAME).$(RESET)\n"
	@$(BANNER)
	@$(COMPILE) $(OBJS) $(LIBFT) $(LIBFT_FLAGS) $(MLX) $(MLX_FLAGS) -o $(NAME)

#Check if both flags (-s -C) can be together
clean:
	@printf "$(YELLOW)Cleaning objects.$(RESET)\n"
	@$(REMOVE) $(OBJS)

#Check if both flags (-s -C) can be together
fclean: clean
	@printf "$(YELLOW)Cleaning binaries.$(RESET)\n"
	@$(REMOVE) $(NAME)
	@make clean -s -C $(MLX_DIR)
	@make fclean -s -C $(LIBFT_DIR)

re: fclean all
