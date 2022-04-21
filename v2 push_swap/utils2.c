/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 12:52:16 by chartema      #+#    #+#                 */
/*   Updated: 2022/04/21 15:11:41 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h> //nodig voor NULL
#include <stdlib.h> //nodig voor malloc

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new -> value = value;
	new -> next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst)
		return ;
	if (*lst != NULL)
	{
		temp = ft_lstlast(*lst);
		temp -> next = new;
	}
	else
		*lst = new;
}

void	ft_lstdelone(t_list *lst, void (*del)())
{
	if (!lst)
		return ;
	if (del != NULL)
		del(lst -> value);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)())
{
	t_list	*temp;

	if (!*lst)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}
