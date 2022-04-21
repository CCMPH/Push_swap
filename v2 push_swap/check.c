/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/15 11:06:38 by chartema      #+#    #+#                 */
/*   Updated: 2022/04/21 10:31:26 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos_lowest(t_list **list_a)
{
	int		i;
	int		lowest;
	t_list	*temp;

	i = 1;
	temp = *list_a;
	lowest = temp->value;
	while (temp != NULL)
	{
		if (temp->value < lowest)
			lowest = temp->value;
		temp = temp->next;
	}
	temp = *list_a;
	while (temp->value != lowest)
	{
		i++;
		temp = temp->next;
	}
	return (i);
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
