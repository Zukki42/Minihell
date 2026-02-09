/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:37:29 by bavirgil          #+#    #+#             */
/*   Updated: 2025/11/27 19:48:22 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef enum e_tok_type
{
	T_WORD,
	T_PIPE,
	T_REDIR_IN,
	T_REDIR_OUT,
	T_REDIR_APPEND,
	T_REDIR_HEREDOC
}	t_tok_type;

typedef struct s_token
{
	t_tok_type		type;
	char			*value;
	struct s_token	*next;
}	t_token;

/* Forward declarations (real structs in minishell.h) */
typedef struct s_shell	t_shell;
typedef struct s_cmd	t_cmd;

/* main parser entry */
t_cmd	*parse_line(char *line, t_shell *sh);

/* lexer */
t_token	*lex_line(char *line);
void	free_tokens(t_token *list);
int		expand_tokens(t_token *tok, t_shell *sh);
int 	is_space(char c);
int 	is_metachar(char c);



#endif
