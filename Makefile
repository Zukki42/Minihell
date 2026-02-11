# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dstreck <dstreck@student.42heilbronn.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/27 18:36:41 by bavirgil          #+#    #+#              #
#    Updated: 2026/02/11 16:30:44 by dstreck          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#----------------------------------COMPILER------------------------------------#
NAME		:= minishell

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g

INCLUDES	:= -IIncludes -ILibFT
INCL_DIR	:= incl
SRCs_DIR	:= srcs
OBJS_DIR	:= objs
#------------------------------------LIBFT-------------------------------------#
LIBFT_DIR	:= $(INCL_DIR)/LibFT
LIBFT_LIB	:= $(INCL_DIR)/LibFT/libft.a
#------------------------OBJECT DEPENDENCY COMPILATION-------------------------#
SRC			=	$(SRC_DIR)/main.c \
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

OBJS		:=	$(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
#---------------------------------COMPILATION----------------------------------#
all:			$(NAME)

$(LIBFT_LIB):
	@printf "$(YELLOW)Compiling LibFT...$(WHITE)\n"
	@$(MAKE) -C $(LIBFT_DIR)
	@printf "$(GREEN)LibFT has been compiled successfully.$(WHITE)\n"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c|	$(OBJS_DIR)
	@printf "$(YE)Compiling $<...$(WH)\n"
	@$(CC) $(CFLAGS) -I $(INCL_DIR) -c $< -o $@
	@printf "$(GR)$< has been successfully compiled!$(WH)\n"

$(NAME):		$(OBJ) $(LIBFT_LIB)
	@printf "$(YE)Compiling $(NAME)...$(WH)\n"
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(INCLUDES) -o $(NAME) -lreadline
	@printf "$(GR)$(NAME) has been successfully compiled!$(WH)\n"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJ)
	@printf "$(GR)All LibFT and Minishell .o files have been removed!$(WH)\n"

fclean:			clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@printf "(GR)All compiled files have been removed!$(WH)\n"

re:			fclean all
#-----------------------------------IGNORE-------------------------------------#
.PHONY:		all clean fclean re bonus

WH	=	\033[0m
GR	=	\033[32;01m
YE	=	\033[33;01m
RE	=	\033[31;01m
