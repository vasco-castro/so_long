# Directories
SRCS_DIR = ./src
INCLUDES_DIR = ./inc
MAPS_DIR = ./maps

# Source files (with directories applied)
SRCS = $(addsuffix .c, \
	$(addprefix $(SRCS_DIR)/, \
		so_long error_handling \
		handlers/handlers handlers/moves handlers/moves2 \
		parsing/parsing parsing/ft_floodfill \
		rendering/image rendering/rendering \
	) \
)

# Object files convertion
OBJ         := $(SRC:.c=.o)
