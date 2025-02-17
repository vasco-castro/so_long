NAME = get_next_line.a

COMPILER = cc
CFLAGS = -Wall -Werror -Wextra -O3

RM = rm -f
AR = ar rcs

SRCS = get_next_line.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Building $(NAME)."
	@$(AR) $(NAME) $(OBJS)

clean:
	@echo "Cleaning all objects."
	@$(RM) $(OBJS)

fclean: clean
	@echo "Cleaning all $(NAME) files."
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re