-include mk/config.mk
-include mk/targets.mk

NAME = so_long

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	@printf "$(GREEN)Building $(NAME).$(RESET)\n"
	@$(BANNER)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBFT_FLAGS) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "$(YELLOW)Cleaning objects.$(RESET)\n"
	@$(RM) $(OBJ)

fclean: clean
	@printf "$(YELLOW)Cleaning binaries.$(RESET)\n"
	@$(RM) $(NAME)
	@make clean -sC $(MLX_DIR) > /dev/null 2> /dev/null
	@make fclean -sC $(LIBFT_DIR)

re: fclean all
