/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 15:03:09 by chartema      #+#    #+#                 */
/*   Updated: 2022/04/15 11:58:47 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(long))
{
	if (!lst)
		return ;
	if (del != NULL)
		del(lst -> value);
	free(lst);
}
