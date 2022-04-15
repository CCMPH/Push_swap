/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/15 13:11:08 by chartema      #+#    #+#                 */
/*   Updated: 2022/04/15 13:41:50 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **list_a)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *list_a;
	if (temp1 == NULL)
		return ;
	temp2 = temp1->next;
	if (temp2 == NULL)
		return ;
	temp1->next = temp2->next;
	temp2->next = temp1;
	*list_a = temp2;
	write(1, "sa\n", 3);
	// Zijn de if statements nodig?
}
