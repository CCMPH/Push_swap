/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/15 13:11:08 by chartema      #+#    #+#                 */
/*   Updated: 2022/04/21 13:41:21 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //nodig voor NULL
#include <unistd.h> //nodig voor write

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
}

void	rotate_a(t_list **list_a)
{
	t_list	*temp;
	t_list	*last;

	if (ft_lstsize(*list_a) == 1)
		return ;
	temp = *list_a;
	last = ft_lstlast(*list_a);
	last->next = temp;
	*list_a = (*list_a)->next;
	temp->next = NULL;
	write(1, "ra\n", 3);
}

void	reverse_a(t_list **list_a)
{
	t_list	*temp;
	t_list	*last;

	if (ft_lstsize(*list_a) == 1)
		return ;
	temp = *list_a;
	last = ft_lstlast(*list_a);
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next = NULL;
	last->next = *list_a;
	*list_a = last;
	write(1, "rra\n", 4);
}

void	push_b(t_list **list_a, t_list **list_b)
{
	t_list	*temp;

	temp = *list_a;
	if (temp == NULL)
		return ;
	*list_a = temp->next;
	temp->next = *list_b;
	*list_b = temp;
	write(1, "pb\n", 3);
}

void	push_a(t_list **list_a, t_list **list_b)
{
	t_list	*temp;

	temp = *list_b;
	if (temp == NULL)
		return ;
	*list_b = temp->next;
	temp->next = *list_a;
	*list_a = temp;
	write(1, "pa\n", 3);
}
