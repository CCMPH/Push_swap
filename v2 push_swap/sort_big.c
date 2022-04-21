/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_big.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/16 15:03:33 by chartema      #+#    #+#                 */
/*   Updated: 2022/04/21 13:40:19 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //nodig voor NULL

int	get_position(t_list **list_a, int input)
{
	t_list	*temp;
	int		position;

	temp = *list_a;
	position = 0;
	while (temp != NULL)
	{
		if (input > temp->value)
			position += 1;
		temp = temp->next;
	}
	return (position);
}

int	find_max_bits(int ac)
{
	int	max_num;
	int	max_bits;

	max_num = ac - 1;
	max_bits = 0;
	while (max_num >> max_bits != 0)
		max_bits++;
	return (max_bits);
}

void	radix(t_list **list_a, t_list **list_b, int ac)
{
	int		i;
	int		j;
	int		bit_compare;
	int		max_bits;

	i = 0;
	max_bits = find_max_bits(ac);
	while (i < max_bits)
	{
		j = 0;
		while (j < ac - 1 && check_if_sorted(list_a))
		{
			bit_compare = ((*list_a)->position >> i) & 1;
			if (bit_compare == 0)
				push_b(list_a, list_b);
			else
				rotate_a(list_a);
			j++;
		}
		while ((*list_b) != NULL)
		{
			push_a(list_a, list_b);
		}
		i++;
	}
}

void	sort_big(t_list **list_a, t_list **list_b, int ac)
{
	t_list	*temp;

	temp = *list_a;
	while (temp != NULL)
	{
		temp->position = get_position(list_a, temp->value);
		temp = temp->next;
	}
	radix(list_a, list_b, ac);
}
