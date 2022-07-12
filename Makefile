# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
<<<<<<< HEAD
#    Created: 2022/04/06 01:35:58 by bmugnol-          #+#    #+#              #
#    Updated: 2022/07/12 21:19:07 by llopes-n         ###   ########.fr        #
=======
#    Created: 2022/07/12 17:05:45 by bmugnol-          #+#    #+#              #
#    Updated: 2022/07/12 17:05:47 by bmugnol-         ###   ########.fr        #
>>>>>>> 11029203740e04a209e6b7602594e9ac0ed51cc4
#                                                                              #
# **************************************************************************** #

# Program name
NAME	:= minishell

# GENERAL OPTIONS
# C Compiler
CC		:=	gcc
# Compiler flags
CFLAGS	:=	-Wall -Wextra -Werror -g 
# Removal tool
RM		:=	rm -rf


# PROGRAM
# Header that includes all headers
MASTER_HEADER := master.h
# Headers
HEADER_DIR	:=	inc/
HEADER		:=	minishell.h
H_INCLUDE	:=	$(addprefix -I, $(HEADER_DIR))

# Source
SRC_DIR		:=	src
SRC			:=	main.c

# Object
OBJ_DIR		:=	obj
OBJ			:=	$(SRC:%.c=$(OBJ_DIR)/%.o)

# Precompiled header
C_HEADER_DIR	:=	pch
C_HEADER		:=	$(MASTER_HEADER:%.h=$(C_HEADER_DIR)/%.h.gch)
C_INCLUDE		:=	$(addprefix -I, $(C_HEADER_DIR))


# LIBFT
LIBFT_DIR		:=	../libft

LIBFT_H_DIR		:=	$(LIBFT_DIR)/inc
LIBFT_H_INC		:=	-I$(LIBFT_H_DIR)

LIBFT_LIB		:=	$(LIBFT_DIR)/libft.a


# Inclusions:
INCLUDE		:=	$(C_INCLUDE) $(LIBFT_H_INC)

# vpath
vpath	%.h		$(HEADER_DIR)
vpath	%.h.gch	$(C_HEADER_DIR)
vpath	%.c		$(SRC_DIR)

# -----------------------RULES------------------------------------------------ #
.PHONY: all norm clean fclean re

# Creates NAME
all: $(NAME)

# Compiles OBJ and LIBFT_LIB into the program NAME
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(H_INCLUDE) -lreadline

# Compiles SRC into OBJ
$(OBJ): $(OBJ_DIR)/%.o: %.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(H_INCLUDE)

# Header precompiling
$(C_HEADER): $(C_HEADER_DIR)/%.h.gch: %.h $(HEADER) | $(C_HEADER_DIR)
	@$(CC) $(CFLAGS) -o $@ $< $(H_INCLUDE)

# Directory making
$(OBJ_DIR) $(C_HEADER_DIR):
	@mkdir -p $@

# Libft compiling
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

# Norm: checks code for norm errors
norm:
	@$(MAKE) -C $(LIBFT_DIR) norm
	@norminette | grep "Error" | cat

# Clean: removes objects' and precompiled headers' directories
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ_DIR) $(C_HEADER_DIR)

# Full clean: same as 'clean', but removes the generated libraries as well
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

# Remake: full cleans and runs 'all' rule
re: fclean all
