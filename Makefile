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
HEADER_DIR	:=	inc
HEADER_DIR	+=	src/builtin src/parsing src/pipe_lst src/var_lst
HEADER		:=	minishell.h struct.h
HEADER		+=	builtin.h parsing.h pipe_lst.h var_lst.h
H_INCLUDE	:=	$(addprefix -I, $(HEADER_DIR))

# Source
SRC_DIR		:=	src src/builtin src/parsing src/pipe_lst src/var_lst src/signals
SRC_DIR 	+=	src/parsing/redirects_in_out src/parsing/builds src/errors_frees
SRC_DIR 	+=	src/parsing/expansion
SRC			:=	main.c exec_cmd.c signal_setup.c hash_builds.c init.c error.c
SRC			+=	signal_handler.c expansion_utils.c
SRC			+=	expansion.c parsing_pipe.c parsing.c parsing_utils.c
SRC			+=	redirect_utils.c frees_and_closes.c heredoc.c
SRC 		+=	build_ins.c commands.c recognize_redirects.c
SRC			+=	var_lst_add.c var_lst_del.c var_lst_get.c
SRC			+=	pipe_lst_add.c pipe_lst_del.c
SRC			+=	cd.c echo.c env.c exit.c export.c pwd.c unset.c

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
.PHONY: all norm vg clean fclean re lulu

# Creates NAME
all: $(NAME)

# Compiles OBJ and LIBFT_LIB into the program NAME
$(NAME): $(LIBFT_LIB) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT_LIB) $(INCLUDE) $(SYS_LIB)
	@echo "$$LULU"
	@echo "\t\t\t\t\tWELCOME TO LULU HELL!\n"

# Compiles SRC into OBJ
$(OBJ): $(OBJ_DIR)/%.o: %.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

# Directory making
$(OBJ_DIR):
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
	@$(RM) $(OBJ_DIR) $(SUPP_FILE)
	@$(MAKE) -C $(LIBFT_DIR) clean

# Full clean: same as 'clean', but removes the generated libraries as well
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Remake: full cleans and runs 'all' rule
re: fclean all

# Just make your terminal big and enjoy :)
lulu:
	@echo "$$LULU"

define LULU

████████████████████████████████████████████████████████████████████████████████████████████████████
████████████████████████████████████████████████████████████████████████████████████████████████████
███████████████████████████████████████████████████████▀████████████████████████████████████████████
██████████████████████████████████████████████▀▀░▄▓▒▒▒▒▒▀█▀█░█▄░▀███████████████████████████████████
██████████████████████████████████████████▀▀░▒▒▒▒▒▒▒▒▒▓▒░▒░▒░▐▀▒░▐▓▄░▀███████████▓███▓██████████████
███████████████████████████████████▓████▀░▒▒▒▒▒▒▒▒▒▒▒▄▓▀▒▒▒   ░▒▒▒▄▒▓▓▄░▀███▓██████▀████████████████
█████████████████████████████████████▀░▒▒▒▄▒▒▒▒▄▄▄█▀▀▒▒▒▒  ▓▒▒▒▓▄ ▒▒▓▄▒▒▒ ▀█████▀▄██ ██▓████████████
█████████████████████████▓████▓████░▒▒▒▒▄▀▒░█▓█▀▀▒▒▒▒▒░░▄▓▒▒▒▒▒▒▒▒▄ ░▀██▓██░ ▀▓█████████▓███████████
████████████████████▐█▀█████████▀░▒▒▒░▓▌ ▒▐██▒▒▒▒▒▄▄▓▓▒▒▒▒▒▒▒▓▓▒▒▓▒▓▓▓▓▓▄▒▀██▄ ▀██▀██▐▐█████████████
████████████████▓██▌██████▄▒█▄▄ ▒▒▒▒░▀▀▄█▓░░▒░▄▓▓▒▒▓▀▀░░░░▓▓▓▓▓▓▓▓▓▓ ░▀▓▓▓▓▓▄▀███▄░███▐█████████████
████████████████▓██ ████████████▒ ░▒▄███░▒░▄▓▒▒▒▓▓░▄▄██▄ ░░▓▓▓ ▓▓▓▓▓ ▀  ░░▓▓▓▓░███▐██░██▌███████████
████████████████▓██▐████▄▀▀████▒▒▒░ ██▀▒▒ ▓▓▓▓▓▓░▄▄▄▄▄▄░▀▄░▓▓░░▐▓▓▌▄ ███▄▄░░▓▓▓▄▀█▌█▌▐██████████████
████████████████▌██ ████▌▒▒▒▒▒▒▒▒░▒██░▒▒ ▓▓▓▓▓▓ ██████████▐▓ ░░▐▓▓▓▓▐██████ ░░▓▓▄▀█▐ ██▌████████████
████████████████▌███▀████░▒▒▒▒▒▒░▒▐█░▒░▄▓▓▓▓▓▓░██████████▄██▌ ░▓▓▓▀▄████████ ░ ▀▓▓░ ▀███▒▓██████████
███████████████▓███▀ ███▓█▄▓▓▒▒▒░▒▀▀░▄▓▓▓▓▓▓▓▌▐█▀▀▀  ░▀▀▓▓██ ░▀▀▓▄██▀ ▄▄▄  ▀▌░░░ ▀▓▄▒▀█▀█▌██████████
█████████████████▀ ▒░▒ ▓▓▓▓▓▓▒▒▒▒▐█    ▄▓▓▓▀▀  ▄▄█░░▒▒░░▒ █████████  ▒  ▒░█▄  ░░░   ▄████▓██████████
████████████▓███ ▒░░░░▒ ▓▓▓▓▓▒▒░▒ ░▄▄▓▓▓▓▓▀░▐▄▐██▌░▒ ▀ ░░█▄▀██▓███▌▐░▒▀ ▒░█ ▓ ░░░ ▀████▌▒███████████
██████████████▀▒░░░░░░▒░░▀▒▒▒▒▒░░█   ░░  ░░ ▐▓▓▌ ▀▀     ▄▄▓█████▀▀▀▀██▄▄▄▄▄███ ░░░░ ▀█████▓█████████
█████████████ ▒░░░░░░▒░░░░░ ░░░░▐▌▒░▒  ░░░  ▓▓▓▓▓▓█████████████▄███▄▄██████████▌░▓▓▓▓▓▓ ██▌█████████
████████████ ░░░░░░░░░░░░░░░░░░░█░░▒ ▓▓▓▓▓▓ ▒▓▓█████████████████████████████████▌▓▓▓▓▓▓ ██▌█████████
████████▌██ ▒░░░░░░░▒░░░ ░░░▒░ ██░ ▓▓▓▓▓▓▓▓▄░▓████████████████░▀  ▄▄▄▒▒▀████████ ▒▒▒▒▒░ ██▌█████████
████████▓██ ░░░░▒▒▒ ░░░▄ ░▒░▀▌▐█▌▒ ░░▓▓▓▓▓▓▓▓▄▄▀▀████▀█████████ ░░░░ ▓█▌████▀▀▒▒▒▒▒▒▒░░▐██▓█████████
████████▓██▄▒▒▒▒▒▒▒░░ ██ ▒░░░▐▓█░░▒  ░ ░▒▓▒▒▒▒▒▒▒▒▒▒░▄██████████████ ▓▓ ███▀▀░░▒▒▒▒░░ ▄██▌██████████
████████████ ▒▒▒▒▒▒▒▒▒▒▓▒▒░░ ▓▓▌▒░░▒   ░░ ░░░▒░░ ░░ ▓███████████████ ▓▓ ▓▓▀     ░░  ▄███▓███████████
█████████████▄▒▒▒▒▒▒▒▒▒▒▒░░ ▓▓▓░░▒  ░░░░░░░░░░░░  ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▄▓▒      ░▒░███▌▀███████████████
███████████▓███▄▒▒▒▒▒▒▒▒░░ ▒▓▓▌▒░▄▓▒░░░░░░░░░░░░░░░                ░▓▓▌ ▄▓▓▓▒▀ ▒░███▓░████████▀█████
███████████████████▄░░░░ ▐▒ ░▒▓▒▒▓▒▀░          ░░░░░   ▒▒▒▒▒   ▄▄▓▓▓▓▓▒░       ▒▒▒▀█▓▓▓▒███▀▒▓▒ ██▓█
█████████████▓█▓▓██████▒▒▒▒▓▓      ░░         ░░     ░   ░  ▒▀░░░░▄▄░▀▓▓▓▄▄  ░░   ▒░▀█▓▓▓▄▓▒▒▒▒ ██▓█
██████▓███▒██████████▒▓▒▒▒▒▓░  ░             ░  ░░  ░ ▄▄▄▄  ▒▒▒▀▀▓▓▓▓▓▓▓▄░    ▄▄▄ ░    ▒▀▀▀▀▀▒▒▐████
█████████ ▓▓▓▒▒▀██▀▒▒▒▒▒▒▓▀ ░    ░▒▒▒        ▄▒▒▒ ░ ▄████▀▀ ▒▒▒▄▄▄▓▓▓▓▒  ▓▓░▓▓████▌   ░   ▒▒▒▒ ██▌██
██████████▄▀▒▒▒▒▒▓▒▒▒▒▒▓░░▒▒▒▒▒▒▒▒▒▒▒       ▓▒▒▒▒▒ ▄██████▒▓ ▒▓▀▓▓▓▓▓▓▓▓▓▓▓▐▓████▓▌     ░▒▒  ▄██████
████████▓███▄▀▓▒▒▒▒▒▓▓▀▒ ▒▒▒▒▒▒▒▒▒▒▒▒░    ░▐▒▒▒▒▒▒ ████▀██▌▒▄▒░▀▀▒▒▄▄▒▒░▒░▓ ▒▀▓▀▀█ ░    ░░░▒ ██▌████
██████████████▄ ▒▀▀▒▒▒▒▒▒ ▒▒▒▒▒▒▒▒▒▒▒░░    ▒▒▒▒▒▒▒░ █████▀▒▒▒▒▒▒▒▒▒▓▓▒▓▓▓▓▓░▒▒███▌      ░▒░░░▐██████
████████████▓████▄▒▒▒▒▒▒▒░ ░▒▒▒▒▒▒▒▒▒▒      ░░░░░░░ ▐██▄▄▄▒▒ ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▒██▓ ▒▒░░▒▒█ ░▒ ██▌████
███████████████████████████▄ ░▒▒▒▒▒▒▒▒▒░▀▀▀▒▒▓▓▓▓▓▒▒ ▓▓▓▒    ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ▓▓▓ ░░░░▄▒  ▄█████████
████████████████████████▓▓███▄ ░░▒▒▒▒▒▒▒▒  ▐▒▒▒▄▒▒▒░ ▀▀▒░▒ ████▄▄▄░░░░▄▄▄██ ▒▒▒▄▄▄▄▒▒▒▒▄████████████
███████████████████████████▓█████▄▄▄░    ░░   ▒▒▒▓▓▓▓▓▓▒ ▄████████████████████▄▄▄▄▒██████▓██████████
███████████████████████████████████████████████▄▄▄▄▄▄██████▓████████████████████████████████████████
████████████████████████████████████████████████████████████████████████████████████████████████████
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
endef
export LULU
