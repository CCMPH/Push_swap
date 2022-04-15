/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 13:12:55 by chartema      #+#    #+#                 */
/*   Updated: 2022/04/15 13:31:00 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //nodig voor printf

// Writes the given error message and exit the program
void	ft_error(char *error)
{
	write(1, error, ft_strlen(error));
	exit (1);
}

int	what_is_happening(t_list *list_a, t_list *list_b)
{
	while (list_a != NULL)
	{
		printf("List a: %ld\n", list_a->value);
		list_a = list_a->next;
	}
	while (list_b != NULL)
	{
		printf("list b: %ld\n", list_b->value);
		list_b = list_b->next;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*list_a;
	t_list	*list_b;

	if (ac == 1 ||!av)
		return (0);
	list_a = NULL;
	list_b = NULL;
	parse_input(&list_a, ac, av);
	what_is_happening(list_a, list_b);
	sorting_machine(&list_a, ac);
	what_is_happening(list_a, list_b);
	//system("leaks push_swap");
	return (0);
}
