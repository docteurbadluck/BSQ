# Name of the executable
NAME = bsq

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = allocate_manager.c error_manager.c manip_str_2.c map_handling_2.c \
	map_handling.c input_manager.c str_manip.c process_manager.c \
	algo.c algo2.c input_manager_2.c bsq.c


# Object files
OBJS = $(SRCS:.c=.o)

# Header file
HEADERS = bsq_map.h

# Default rule to compile the program
all: $(NAME)

# Rule to link the object files into the executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Rule to compile the source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove object files
clean:
	rm -f $(OBJS)

# Fclean rule to remove object files and the executable
fclean: clean
	rm -f $(NAME)

# Rule to clean and recompile everything
re: fclean all

# Phony targets to prevent conflicts with files
.PHONY: all clean fclean re
