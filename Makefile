-include mk/config.mk
-include mk/targets.mk

NAME	:= so_long

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@printf "$(GREEN)Building $(NAME).$(RESET)\n"
	@$(BANNER)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBFT_FLAGS) $(MLX) $(MLX_FLAGS) -o $(NAME)

clean:
	@printf "$(YELLOW)Cleaning objects.$(RESET)\n"
	@$(RM) $(OBJS)

fclean: clean
	@printf "$(YELLOW)Cleaning binaries.$(RESET)\n"
	@$(RM) $(NAME)
	@make clean -sC $(MLX_DIR) > /dev/null 2> /dev/null
	@make fclean -sC $(LIBFT_DIR)

re: fclean all
