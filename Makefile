# Program name
NAME	:=	minishell

# GENERAL OPTIONS
# C Compiler
CC		:=	clang
# Compiler flags
CFLAGS	:=	-Wall -Wextra -Werror -g
# Removal tool
RM		:=	rm -rf


# PROGRAM
# Headers
HEADER_DIR	:=	inc src/utils
HEADER		:=	minishell.h lst.h
H_INCLUDE	:=	$(addprefix -I, $(HEADER_DIR))

# Source
SRC_DIR		:=	src src/utils
SRC			:=	main.c builtins.c exec.c lst_add.c lst_del.c

# Object
OBJ_DIR		:=	obj
OBJ			:=	$(SRC:%.c=$(OBJ_DIR)/%.o)


# LIBFT
LIBFT_DIR		:=	libft

LIBFT_H_DIR		:=	$(LIBFT_DIR)/inc
LIBFT_H_INC		:=	-I$(LIBFT_H_DIR)

LIBFT_LIB		:=	$(LIBFT_DIR)/libft.a


# Inclusions:
INCLUDE		:=	$(H_INCLUDE) $(LIBFT_H_INC)
SYS_LIB		:=	-lreadline

# Suppressions:
SUPP_FILE	:=	readline.supp
define SUPP_TEXT
{
   <Readline>
   Memcheck:Leak
   match-leak-kinds: reachable
   ...
   fun:readline
   ...
}

{
   <Readline/AddHistory>
   Memcheck:Leak
   match-leak-kinds: reachable
   fun:malloc
   fun:xmalloc
   fun:add_history
   ...
}
endef
export SUPP_TEXT

# vpath
vpath	%.h		$(HEADER_DIR)
vpath	%.c		$(SRC_DIR)

# -----------------------RULES------------------------------------------------ #
.PHONY: all norm vg clean fclean re

# Creates NAME
all: $(NAME)

# Compiles OBJ and LIBFT_LIB into the program NAME
$(NAME): $(LIBFT_LIB) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT_LIB) $(INCLUDE) $(SYS_LIB)

# Compiles SRC into OBJ
$(OBJ): $(OBJ_DIR)/%.o: %.c $(C_HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

# Directory making
$(OBJ_DIR) $(C_HEADER_DIR):
	@mkdir -p $@

# Libft compiling
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

# Run program using valgrind
vg: $(SUPP_FILE)
	@$(MAKE)
	valgrind --suppressions=$< --leak-check=full --show-leak-kinds=all ./$(NAME)

# Create suppresion file
$(SUPP_FILE):
	@echo "$$SUPP_TEXT" > $@

# Norm: checks code for norm errors
norm:
	@norminette | grep "Error" | cat
	@$(MAKE) -C $(LIBFT_DIR) norm

# Clean: removes objects' and precompiled headers' directories
clean:
	@$(RM) $(OBJ_DIR) $(C_HEADER_DIR) $(SUPP_FILE)
	@$(MAKE) -C $(LIBFT_DIR) clean

# Full clean: same as 'clean', but removes the generated libraries as well
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Remake: full cleans and runs 'all' rule
re: fclean all
