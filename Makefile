# COMPILATION
LINKER			= cc
COMPILER		= $(LINKER) -c

# SHELL COMMANDS
REMOVE			= rm
REMOVE_FORCE	= $(REMOVE) -rf
MAKE_DIR		= mkdir -p
DEBUG			= gdb -q -tui
MEMCHECK		= valgrind

# SELECTIONS
ifdef GDB
FLAG_C			+= -g3
endif

ifdef GCC
LINKER			= gcc
endif

ARGL			=

# COMPILATION FLAG
FLAG_C			+= -Wall -Wextra -Werror
FLAG_LEAK		+= -s

# DIRECTORIES
PATH_OBJECT		= objects
PATH_INCLUDE	= includes
PATH_SOURCE		= sources
PATH_PRINTF		= $(PATH_INCLUDE)/printf

# LIBRARIES AND BINARY
NAME			= push_swap
PRINTF			= $(PATH_PRINTF)/libftprintf.a

# FILE
INCLUDES		= -I$(PATH_INCLUDE) -I$(PATH_PRINTF)

FILE_SOURCES	=	close.c check.c create_set_stack.c manipulate_.c \
					manipulate.c operations__.c operations_.c operations.c \
					push_swap.c sort_tiny.c sort.c utils.c \

FILE_OBJECTS	= $(SOURCE:$(PATH_SOURCE)/%.c=$(PATH_OBJECT)/%.o)
FILE_HEADER		= $(PATH_INCLUDE)/push_swap.h
SOURCE			= $(addprefix $(PATH_SOURCE)/, $(FILE_SOURCES))

all: $(NAME)

$(NAME): $(PRINTF) $(PATH_OBJECT) $(FILE_OBJECTS) $(FILE_HEADER)
	$(LINKER) $(FLAG_C) $(FILE_OBJECTS) $(PRINTF) -o $@

$(PRINTF):
	$(MAKE) -C $(PATH_PRINTF) all

$(PATH_OBJECT)/%.o: $(PATH_SOURCE)/%.c $(FILE_HEADER)
	@$(COMPILER) $(FLAG_C) $(INCLUDES) $< -o $@

$(PATH_OBJECT):
	$(MAKE_DIR) $(PATH_OBJECT)

clean:
	$(REMOVE_FORCE) $(PATH_OBJECT)
	@$(MAKE) -C $(PATH_PRINTF) clean

fclean: clean
	$(REMOVE_FORCE) $(NAME)
	@$(MAKE) -C $(PATH_PRINTF) fclean

re: fclean all