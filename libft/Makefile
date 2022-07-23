# -----------------------LIBRARY---------------------------------------------- #
# Generated static library name
NAME	:=	libft.a

# -----------------------COMPILER--------------------------------------------- #
# C Compiler
CC		:=	clang
# Compiler flags
CFLAGS	:=	-Wall -Wextra -Werror -g
#	(Turn on all warning flags and extra warnings, treat warnings as errors)

# -----------------------ARCHIVER--------------------------------------------- #
# Archiver
AR		:= 	ar
# Archiver flags
ARFLAGS	:=	rcs
#	(Inserts files with replacement, creates the archive if not existent,
#		add index to archive)

# -----------------------HEADERS---------------------------------------------- #
# Headers files
HEADER		:=	libft.h ft_printf.h
# Headers directories
HEADER_DIR	:=	inc
# Headers inclusion
INCLUDE		:=	$(addprefix -I, $(HEADER_DIR))

# -----------------------PRECOMPILED HEADERS---------------------------------- #
# Compiled headers directory
C_HEADER_DIR	:=	pch
# Compiled headers files
C_HEADER		:=	$(HEADER:%.h=$(C_HEADER_DIR)/%.h.gch)
# Compiled headers inclusion
C_INCLUDE		:=	$(addprefix -include-pch , $(C_HEADER))

# -----------------------SOURCES---------------------------------------------- #
# Source directories
SRC_DIR		:=	src src/ctype	src/ft_printf		src/libft_put
SRC_DIR		+=	src/libft_str	src/linked_list 	src/stdlib
SRC_DIR		+=	src/string_mem	src/string_str		src/strings
SRC_DIR		+=	src/string_bsd	src/custom/misc		src/custom/to_str
# Source files
####<ctype.h>
SRC	:=	ft_isalpha.c	ft_isalnum.c	ft_isascii.c	ft_isdigit.c\
		ft_isprint.c	ft_toupper.c	ft_tolower.c
###	<stdlib.h>
SRC	+=	ft_atoi.c		ft_atoll.c		ft_calloc.c
###	<strings.h>
SRC	+=	ft_bzero.c
###	<string.h>
SRC	+=	ft_memchr.c		ft_memcmp.c		ft_memcpy.c		ft_memmove.c\
		ft_memset.c 	# Memory
SRC	+=	ft_strlen.c		ft_strdup.c		ft_strchr.c		ft_strrchr.c\
		ft_strncmp.c	# Strings
SRC	+=	ft_strlcpy.c	ft_strlcat.c								\
		ft_strnstr.c	# <bsd/string.h>
###	Libft specific
SRC	+=	ft_substr.c		ft_strjoin.c	ft_strtrim.c	ft_split.c	\
		ft_strmapi.c	ft_striteri.c
###	Libft specific
SRC	+=	ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c
###	Custom
SRC	+=	ft_itoa.c		ft_utoa.c		ft_ptoa.c		ft_xtoa.c	\
		ft_xto_uppercase_a.c	ft_base_converter.c		# To string
SRC	+=	get_next_line.c	ft_null_free.c	ft_free_matrix.c			\
		ft_strmerge.c	ft_atoi_base.c	ft_free_char_matrix.c		\
		ft_partial_split.c ft_strnchr.c	ft_strtok.c			# Miscellaneous
###	Linked list
SRC	+=	ft_lstnew.c			ft_lstsize.c		ft_lstlast.c		\
		ft_lstadd_front.c	ft_lstadd_back.c	ft_lstdelone.c		\
		ft_lstclear.c		ft_lstiter.c		ft_lstmap.c
###	ft_printf
SRC	+=	ft_printf.c

# -----------------------OBJECTS---------------------------------------------- #
# Object directory
OBJ_DIR	:=	obj
# Object files
OBJ		:=	$(SRC:%.c=$(OBJ_DIR)/%.o)

# -----------------------VPATH------------------------------------------------ #
vpath	%.h	$(HEADER_DIR)
vpath	%.c	$(SRC_DIR)

# -----------------------COLORS----------------------------------------------- #
NONE		=	'\033[0m'
RED 		=	'\033[1;31m'
GREEN		=	'\033[32m'
YELLOW		=	'\033[33m'
GRAY		=	'\033[2;37m'
CURSIVE		=	'\033[3m'

# -----------------------RULES------------------------------------------------ #
.PHONY: all norm clean fclean re

# Creates the target NAME
all: $(NAME)

# Lib making based on SRC
$(NAME): $(OBJ)
	@ echo $(CURSIVE) $(YELLOW) " - Compressing Objects in $(NAME)..." $(NONE)
	@ $(AR) $(ARFLAGS) $@ $^
	@ echo $(CURSIVE) $(GREEN) " - Libft Created" $(NONE)

# Compiling SRC into OBJ
$(OBJ): $(OBJ_DIR)/%.o: %.c $(C_HEADER) | $(OBJ_DIR)
	@ echo $(CURSIVE) $(YELLOW) " - Making object $<..." $(NONE)
	@ $(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE) $(C_INCLUDE)
	@ echo $(CURSIVE) $(GREEN) " - Objects Created" $(NONE)

# Header precompiling
$(C_HEADER): $(C_HEADER_DIR)/%.h.gch: %.h $(HEADER) | $(C_HEADER_DIR)
	@ echo $(CURSIVE) $(YELLOW) " - Pre Compiling $@..." $(NONE)
	@ $(CC) $(CFLAGS) -o $@ $<
	@ echo $(CURSIVE) $(GREEN) " - $@ Compiled" $(NONE)

# Directory making
$(OBJ_DIR) $(C_HEADER_DIR):
	@ echo $(CURSIVE) $(YELLOW) " - Creating Folder $@..." $(NONE)
	@ mkdir -p $@
	@ echo $(CURSIVE) $(GREEN) " $@ Folder Created" $(NONE)

# Norm: checks code for norm errors
norm:
	@norminette | grep "Error" | cat

# Clean: removes objects' and precompiled headers' directories
clean:
	@ echo $(CURSIVE) $(RED) " - Removing Object files of libft..." $(NONE)
	@ rm -rf $(OBJ_DIR) $(C_HEADER_DIR)
	@ echo $(GREEN) " - Objects deleted !" $(NONE)

# Full clean: same as 'clean', but removes the generated libraries as well
fclean: clean
	@ echo $(CURSIVE) $(RED) " - removing $(NAME)..." $(NONE)
	@ rm -rf $(NAME)
	@ echo $(GREEN) " - $(NAME) deleted !" $(NONE)

# Remake: full cleans and runs 'all' rule
re: fclean all
