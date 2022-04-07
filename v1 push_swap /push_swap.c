/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 11:12:18 by chartema      #+#    #+#                 */
/*   Updated: 2022/04/07 09:18:13 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //voor printf




void	ft_fill_array(t_stack *stack, char *av, int i)
{
	int	number;

	number = ft_atoi(av);
	stack->array_a[i] = number;
	stack->array_c[i] = number;
	// Dit is om ft_swap_a_and_b te te testen 
	// stack->array_b[0] = 1;
	// stack->array_b[1] = 4;
	// stack->array_b[2] = 6;
}

void	ft_what_is_happening(t_stack *stack)
{
	int	i = 0;
	while (i < stack->size_array_a)
	{
		printf("Stack %03d a: %d\n", i, stack->array_a[i]);
		i++;
	}
	i = 0;
	write(1, "\n", 1);
	while (i < stack->size_array_b)
	{
		printf("Stack %03d b: %d \n", i, stack->array_b[i]);
		i++;
	}
	//ft_push_b(stack);
	//int	j = 0;
	// write(1, "\n", 1);
	// while (j < stack->size)
	// {
	// 	printf("Stack %03d a: %d\n", j, stack->array_a[j]);
	// 	j++;
	// }
	// j = 0;
	// write(1, "\n", 1);
	// while (j < stack->size + 1)
	// {
	// 	printf("Stack %03d b: %d\n", j, stack->array_b[j]);
	// 	j++;
	// }
}

int	main(int ac, char **av)
{
	t_stack	stack;
	int		arguments;

	if (ac <= 2 || !av)
		return (0);
	arguments = ac - 1;
	stack.size = arguments;
	printf("Stacksize = %d\n", stack.size);
	stack.array_a = ft_calloc(stack.size, sizeof(int));
	stack.array_b = ft_calloc(stack.size, sizeof(int));
	stack.array_c = ft_calloc(stack.size, sizeof(int));
	stack.pos_c = ft_calloc(stack.size, sizeof(int));
	if (!stack.array_a || !stack.array_b || !stack.array_c || !stack.pos_c)
		ft_error(&stack);
	while (arguments > 0)
	{
		ft_check_input(av[arguments], &stack);
		ft_fill_array(&stack, av[arguments], arguments - 1);
		arguments--;
	}
	ft_check_doubles(&stack);
	stack.size_array_a = stack.size;
	// deze zin is nodig om goed te kunnen printen
	ft_what_is_happening(&stack);
	ft_sorting_machine(&stack);
	ft_what_is_happening(&stack);
	//system("leaks push_swap");
	return (0);
}

// gcc -Wall -Wextra -Werror push_swap.c libft/*.c