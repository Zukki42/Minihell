/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:37:22 by bavirgil          #+#    #+#             */
/*   Updated: 2026/02/11 16:25:27 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ========== SYSTEM INCLUDES ========== */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

/* ========== PROJECT INCLUDES ========== */

# include "LibFT/libft.h"
# include "parser.h"

/* ========== CORE TYPES ========== */

typedef enum e_redir_type
{
	R_IN,
	R_OUT,
	R_APPEND,
	R_HEREDOC
}	t_redir_type;

typedef struct s_redir
{
	t_redir_type		type;
	char				*target;
	int					heredoc_fd;
	struct s_redir		*next;
}	t_redir;

typedef struct s_cmd
{
	char				**argv;
	t_redir				*redir;
	struct s_cmd		*next;
}	t_cmd;

typedef struct s_shell
{
	char				**env;
	int					last_status;
}	t_shell;

/* ========== CORE LOOP ========== */

int		shell_loop(t_shell *sh);

/* ========== LEXER ========== */
/* lexer_utils.c */
int		is_space(char c);
int		is_metachar(char c);
t_token	*new_token(t_tok_type type, char *value);
void	token_add_back(t_token **list, t_token *new);
void	free_tokens(t_token *list);
int	handle_word(char *line, int i, t_token **list);

/* lexer_quotes.c */
int		read_quoted_word(char *line, int i);

/* lexer.c */
t_token	*lex_line(char *line);

/* ========== PARSER / EXPAND ========== */

/* parse_utils.c */
int		is_redir_token(t_token *tok);
int		argv_size(char **argv);

/* parse_syntax.c */
int		check_syntax(t_token *tok, t_shell *sh);

/* parse_redir.c */
int		parse_redir(t_redir **redir_list, t_token **tok);

/* parse_cmd.c */
t_cmd	*parse_one_command(t_token **tok);
t_cmd	*parse_tokens_to_cmds(t_token *tok);

/* parse_debug.c */
void	debug_print_cmds(t_cmd *cmd);

/* parse_line.c */
t_cmd	*parse_line(char *line, t_shell *sh);

/* expand.c / expand_env.c */
int		expand_tokens(t_token *tok, t_shell *sh);
char	*expand_one(char *str, int *i, t_shell *sh);

/* ========== FREE HELPERS ========== */

/* parse_free.c */
void	free_redir_list(t_redir *redir);
void	free_cmd_list(t_cmd *cmd);

#endif
