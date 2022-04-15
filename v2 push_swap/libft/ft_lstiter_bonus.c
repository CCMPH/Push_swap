/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 15:03:17 by chartema      #+#    #+#                 */
/*   Updated: 2022/04/15 11:58:11 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(long))
{
	if (!lst)
		return ;
	while (lst != NULL)
	{
		f(lst -> value);
		lst = lst -> next;
	}
}
