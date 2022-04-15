/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/15 10:01:04 by chartema      #+#    #+#                 */
/*   Updated: 2022/04/15 13:48:03 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //nodig voor printf

void	sorting_machine(t_list **list_a, int ac)
//void	sorting_machine(t_list **list_a, t_list **list_b, int ac)
{
	int	arguments;

	arguments = ac - 1;
	if (check_if_sorted(list_a))
	{
		printf("is sorted: Nee\n");
		if (arguments == 2)
			sort_two(list_a);
		else if (arguments == 3)
			sort_three(list_a);
		// else if (ac == 4)
		// 	sort_four(list_a);
		// else if (ac == 5)
		// 	sort_five(list_a);
		// else
		// 	sort_big(list_a);
	}
}
