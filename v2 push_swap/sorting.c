/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/15 10:01:04 by chartema      #+#    #+#                 */
/*   Updated: 2022/04/21 10:31:08 by chartema      ########   odam.nl         */
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
	else if (first->value > third->value && third->value > second->value)
		rotate_a(list_a);
	else if (second->value > first->value && first->value > third->value)
		reverse_a(list_a);
	else if (second->value > third->value && third->value > first->value)
	{
		swap_a(list_a);
		rotate_a(list_a);
	}
	else if (first->value > second->value && second->value > third->value)
	{
		swap_a(list_a);
		reverse_a(list_a);
	}
}

void	sort_four(t_list **list_a, t_list **list_b)
{
	int	pos_lowest;

	pos_lowest = find_pos_lowest(list_a);
	if (pos_lowest > 1)
	{
		if (pos_lowest == 2)
			swap_a(list_a);
		else if (pos_lowest == 3)
		{
			reverse_a(list_a);
			reverse_a(list_a);
		}
		else if (pos_lowest == 4)
			reverse_a(list_a);
	}
	push_b(list_a, list_b);
	sort_three(list_a);
	push_a(list_a, list_b);
}

void	sort_five(t_list **list_a, t_list **list_b)
{
	int	pos_lowest;

	pos_lowest = find_pos_lowest(list_a);
	if (pos_lowest > 1)
	{
		if (pos_lowest == 2)
			swap_a(list_a);
		else if (pos_lowest == 3)
		{
			rotate_a(list_a);
			rotate_a(list_a);
		}
		else if (pos_lowest == 4)
		{
			reverse_a(list_a);
			reverse_a(list_a);
		}
		else if (pos_lowest == 5)
			reverse_a(list_a);
	}
	push_b(list_a, list_b);
	sort_four(list_a, list_b);
	push_a(list_a, list_b);
}

void	sorting_machine(t_list **list_a, t_list **list_b, int ac)
{
	int	arguments;

	arguments = ac - 1;
	if (check_if_sorted(list_a))
	{
		if (arguments == 2)
			sort_two(list_a);
		else if (arguments == 3)
			sort_three(list_a);
		else if (arguments == 4)
			sort_four(list_a, list_b);
		else if (arguments == 5)
			sort_five(list_a, list_b);
		else
			sort_big(list_a, list_b, ac);
	}
}
