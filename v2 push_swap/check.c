/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/15 11:06:38 by chartema      #+#    #+#                 */
/*   Updated: 2022/04/15 16:32:39 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //nodig voor printf

void	sort_two(t_list **list_a)
{
	t_list	*temp;

	temp = *list_a;
	if (temp->value > temp->next->value)
		swap_a(list_a);
}

void	sort_three(t_list **list_a)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *list_a;
	second = first->next;
	third = second->next;
	if (third->value > first->value && first->value > second->value)
		swap_a(list_a);
		//HIER VERDER MET BOUWEN
}

int	check_if_sorted(t_list **list)
{
	t_list	*temp;

	temp = *list;
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (1);
		temp = temp->next;
	}
	return (0);
}
