/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:29:47 by dstreck           #+#    #+#             */
/*   Updated: 2025/03/26 18:13:32 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*output;
	void	*cont;

	if (!lst || !f || !del)
		return (NULL);
	output = NULL;
	while (lst)
	{
		cont = (*f)(lst->content);
		new = ft_lstnew(cont);
		if (!new)
		{
			del(cont);
			ft_lstclear(&output, *del);
			return (NULL);
		}
		ft_lstadd_back(&output, new);
		lst = lst->next;
	}
	return (output);
}
