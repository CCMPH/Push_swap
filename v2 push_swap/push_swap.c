/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 13:12:55 by chartema      #+#    #+#                 */
/*   Updated: 2022/04/21 14:21:55 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h> //nodig voor write
#include <stdlib.h> //nodig voor exit
#include <stdio.h> //nodig voor printf

void	ft_error(char *error)
{
	write(1, error, ft_strlen(error));
	exit (1);
}

int	what_is_happening_a(t_list *list_a, t_list *list_b)
{
	(void) list_b;
	printf("\n");
	while (list_a != NULL)
	{
		printf("List a value: %d\t", list_a->value);
		printf("List a pos: %d\n", list_a->position);
		list_a = list_a->next;
	}
	return (0);
}

int	what_is_happening_b(t_list *list_a, t_list *list_b)
{
	(void) list_a;
	printf("\n");
	while (list_b != NULL)
	{
		printf("list b: %d\t", list_b->value);
		printf("List b: %d\n", list_b->position);
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
	//what_is_happening_a(list_a, list_b);
	//what_is_happening_b(list_a, list_b);
	sorting_machine(&list_a, &list_b, ac);
	//what_is_happening_a(list_a, list_b);
	//what_is_happening_b(list_a, list_b);
	//system("leaks push_swap");
	return (0);
}
