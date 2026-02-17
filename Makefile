# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dstreck <dstreck@student.42heilbronn.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/27 18:36:41 by bavirgil          #+#    #+#              #
#    Updated: 2026/02/17 18:02:39 by dstreck          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----------------------------------COMPILER------------------------------------#
NAME		:= minishell

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g

INCLUDES	:= -I./incl -ILibFT
INCL_DIR	:= incl
SRCS_DIR	:= srcs
OBJS_DIR	:= objs
O_PARSER	:= objs/parser
O_EXECUT	:= objs/execution
O_GARCOL	:= objs/garbage_collector
#------------------------------------LIBFT-------------------------------------#
LIBFT_DIR	:= $(INCL_DIR)/LibFT
LIBFT_LIB	:= $(INCL_DIR)/LibFT/libft.a
#------------------------OBJECT DEPENDENCY COMPILATION-------------------------#
SRCS		=	$(SRCS_DIR)/main.c \
				$(SRCS_DIR)/loop.c \
				$(SRCS_DIR)/parser/parse_line.c \
				$(SRCS_DIR)/parser/parse_free.c \
				$(SRCS_DIR)/parser/parse_utils.c \
				$(SRCS_DIR)/parser/parse_syntax.c \
				$(SRCS_DIR)/parser/parse_cmd.c \
				$(SRCS_DIR)/parser/parse_redir.c \
				$(SRCS_DIR)/parser/parse_debug.c \
				$(SRCS_DIR)/parser/expand.c \
				$(SRCS_DIR)/parser/expand_env.c \
				$(SRCS_DIR)/parser/lexer.c \
				$(SRCS_DIR)/parser/lexer_utils.c \
				$(SRCS_DIR)/parser/lexer_quotes.c \

OBJS		:=	$(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
#---------------------------------COMPILATION----------------------------------#
all:			$(NAME)

# Compiles the LibFT
$(LIBFT_LIB):
	@printf "$(YELLOW)Compiling LibFT...$(WHITE)\n"
	@$(MAKE) -C $(LIBFT_DIR)
	@printf "$(GREEN)LibFT has been compiled successfully.$(WHITE)\n"

# Creates a directory for all the object files
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(O_PARSER)
	@mkdir -p $(O_EXECUT)
	@mkdir -p $(O_GARCOL)

# Compiles the object files into said directory
$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c|	$(OBJS_DIR)
	@printf "$(YE)Compiling $<...$(WH)\n"
	@$(CC) $(CFLAGS) -I $(INCL_DIR) -c $< -o $@
	@printf "$(GR)$< has been successfully compiled!$(WH)\n"

# Compiles minishell object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compiles minishell in its entirity
$(NAME):		$(OBJS) $(LIBFT_LIB)
	@printf "$(YE)Compiling $(NAME)...$(WH)\n"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(INCLUDES) -o $(NAME) -lreadline
	@printf "$(GR)$(NAME) has been successfully compiled!$(WH)\n"

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)
	@printf "$(GR)All LibFT and Minishell .o files have been removed!$(WH)\n"

fclean:			clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@printf "$(GR)All compiled files have been removed!$(WH)\n"

re:			fclean all
#-----------------------------------IGNORE-------------------------------------#
.PHONY:		all clean fclean re bonus

# Colours for terminal output (WHite, GReen, YEllow and REd)
WH	=	\033[0m
GR	=	\033[32;01m
YE	=	\033[33;01m
RE	=	\033[31;01m
