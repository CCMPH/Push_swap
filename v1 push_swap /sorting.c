/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 11:19:30 by chartema      #+#    #+#                 */
/*   Updated: 2022/03/31 13:43:40 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //nodig voor printf

void	ft_find_smallest(t_stack *stack)
{
	int	i;

	i = 0;
	stack->smallest = stack->array_a[i];
	stack->pos_smallest = i;
	while (i < stack->size_array_a)
	// is het handig size_array_a. of kan je dit ook anders doen?
	{
		if (stack->array_a[i] < stack->smallest)
		{
			stack->smallest = stack->array_a[i];
			stack->pos_smallest = i;
		}
		i++;
	}
	// printf("wat is smallest: %d\n", stack->smallest);
	// printf("wat is position: %d\n", stack->pos_smallest);
}

void	ft_swap_four(t_stack *stack)
{
	if (stack->pos_smallest == 0)
		ft_push_b(stack);
	else if (stack->pos_smallest == 1)
	{
		ft_swap_a(stack);
		ft_push_b(stack);
	}
	else if (stack->pos_smallest == 2)
	{
		ft_reverse_a(stack);
		ft_reverse_a(stack);
		ft_push_b(stack);
	}
	else if (stack->pos_smallest == 3)
	{
		ft_reverse_a(stack);
		ft_push_b(stack);
	}
	// if (ft_check_if_sorted(stack))
	// 	ft_push_b(stack);
	// nadenken, stel ik zet alle push uit. En ik push alleen wanneer er nog
	// niet gesorteerd is. Functie check_if_sorted wel ombouwen om dit te kunnen. 
	// Dit dan ook doen in de functie swap_five
}

void	ft_swap_five(t_stack *stack)
{
	if (stack->pos_smallest == 0)
		ft_push_b(stack);
	else if (stack->pos_smallest == 1)
	{
		ft_swap_a(stack);
		ft_push_b(stack);
	}
	else if (stack->pos_smallest == 2)
	{
		ft_rotate_a(stack);
		ft_rotate_a(stack);
		ft_push_b(stack);
	}
	else if (stack->pos_smallest == 3)
	{
		ft_reverse_a(stack);
		ft_reverse_a(stack);
		ft_push_b(stack);
	}
	else if (stack->pos_smallest == 4)
	{
		ft_reverse_a(stack);
		ft_push_b(stack);
	}
}

void	ft_sort_two(t_stack *stack)
{
	if (stack->array_a[0] > stack->array_a[1])
		ft_swap_a(stack);
}

void	ft_sort_three(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->array_a[0];
	second = stack->array_a[1];
	third = stack->array_a[2];
	if (third > first && first > second)
		ft_swap_a(stack);
	else if (first > third && third > second)
		ft_rotate_a(stack);
	else if (second > first && first > third)
		ft_reverse_a(stack);
	else if (second > third && third > first)
	{
		ft_swap_a(stack);
		ft_rotate_a(stack);
	}
	else if (first > second && second > third)
	{
		ft_swap_a(stack);
		ft_reverse_a(stack);
	}
}

void	ft_sort_four(t_stack *stack)
{
	ft_find_smallest(stack);
	ft_swap_four(stack);
	ft_sort_three(stack);
	ft_push_a(stack);
}

void	ft_sort_five(t_stack *stack)
{
	ft_find_smallest(stack);
	ft_swap_five(stack);
	ft_sort_four(stack);
	ft_push_a(stack);
}

void	ft_sorting_machine(t_stack *stack)
{
	stack->size_array_a = stack->size;
	stack->size_array_b = 0;
	if (ft_check_if_sorted(stack))
	{
		//printf("is sorted: Nee");
		if (stack->size == 2)
			ft_sort_two(stack);
		else if (stack->size == 3)
			ft_sort_three(stack);
		else if (stack->size == 4)
			ft_sort_four(stack);
		else if (stack->size == 5)
			ft_sort_five(stack);
		else
			ft_sort_big(stack);
	}
}
