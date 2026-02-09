# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bavirgil <bavirgil@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/27 18:36:41 by bavirgil          #+#    #+#              #
#    Updated: 2025/11/29 15:46:04 by bavirgil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = minishell

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

INCLUDES = -IIncludes -ILibFT
LIBFT_DIR   = LibFT
LIBFT       = $(LIBFT_DIR)/libft.a

SRC_DIR     = src

SRC         =  $(SRC_DIR)/main.c \
              $(SRC_DIR)/loop.c \
              $(SRC_DIR)/parser/parse_line.c \
			  $(SRC_DIR)/parser/parse_free.c \
			  $(SRC_DIR)/parser/parse_utils.c \
			  $(SRC_DIR)/parser/parse_syntax.c \
			  $(SRC_DIR)/parser/parse_cmd.c \
			  $(SRC_DIR)/parser/parse_redir.c \
			  $(SRC_DIR)/parser/parse_debug.c \
			  $(SRC_DIR)/parser/expand.c \
			  $(SRC_DIR)/parser/expand_env.c \
              $(SRC_DIR)/parser/lexer.c \
			  $(SRC_DIR)/parser/lexer_utils.c \
			  $(SRC_DIR)/parser/lexer_quotes.c \




OBJ         = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(INCLUDES) -o $(NAME) -lreadline

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
