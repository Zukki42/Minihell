/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:25:44 by dstreck           #+#    #+#             */
/*   Updated: 2026/02/19 16:46:37 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_argv(char *arg)
{
	int	i;

	i = 0;
	if (arg == NULL || ft_strncmp(arg[0], "exit"))
		return (1);
	
}

int	ft_exit(t_cmd *cmd, )
{
	int		
}