/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_movements.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 08:44:26 by chartema      #+#    #+#                 */
/*   Updated: 2022/04/07 09:16:43 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //nodig voor printf

void	ft_swap_a(t_stack *stack)
{
	int	temp;

	if (!stack->array_a)
		return ;
	temp = stack->array_a[0];
	stack->array_a[0] = stack->array_a[1];
	stack->array_a[1] = temp;
	write(1, "sa\n", 3);
}

// void	ft_swap_b(t_stack *stack)
// {
// 	int	temp;

// 	if (!stack->array_b)
// 		return ;
// 	temp = stack->array_b[0];
// 	stack->array_b[0] = stack->array_b[1];
// 	stack->array_b[1] = temp;
// 	write(1, "sb\n", 3);
// }

// void	ft_swap_a_and_b(t_stack *stack)
// {
// 	int	temp1;

// 	if (!stack->array_a && !stack->array_b)
// 		return ;
// 	temp1 = stack->array_a[0];
// 	stack->array_a[0] = stack->array_a[1];
// 	stack->array_a[1] = temp1;
// 	temp1 = stack->array_b[0];
// 	stack->array_b[0] = stack->array_b[1];
// 	stack->array_b[1] = temp1;
// 	write(1, "ss\n", 3);
// }

void	ft_push_a(t_stack *stack)
{
	int	i;

	if (!stack->array_b)
		return ;
	i = stack->size - 1;
	while (i > 0)
	{
		stack->array_a[i] = stack->array_a[i - 1];
		i--;
	}
	stack->array_a[0] = stack->array_b[0];
	i = 1;
	while (i < stack->size_array_b)
	{
		stack->array_b[i - 1] = stack->array_b[i];
		i++;
	}
	stack->array_b[stack->size - 1] = 0;
	stack->size_array_a = stack->size_array_a + 1;
	stack->size_array_b = stack->size_array_b - 1;
	write(1, "pa\n", 3);
}

void	ft_push_b(t_stack *stack)
{
	int	i;

	if (!stack->array_a)
		return ;
	i = stack->size_array_b;
	while (i > 0)
	{
		stack->array_b[i] = stack->array_b[i - 1];
		i--;
	}
	stack->array_b[0] = stack->array_a[0];
	i = 1;
	while (i < stack->size_array_a)
	{
		stack->array_a[i - 1] = stack->array_a[i];
		i++;
	}
	stack->array_a[stack->size - 1] = 0;
	stack->size_array_a = stack->size_array_a - 1;
	stack->size_array_b = stack->size_array_b + 1;
	write(1, "pb\n", 3);
}

void	ft_rotate_a(t_stack *stack)
{
	int	i;
	int	temp;

	if (!stack->array_a)
		return ;
	i = 0;
	temp = stack->array_a[0];
	while (i < stack->size_array_a - 1)
	{
		stack->array_a[i] = stack->array_a[i + 1];
		i++;
	}
	stack->array_a[i] = temp;
	write(1, "ra\n", 3);
}

void	ft_reverse_a(t_stack *stack)
{
	int	i;
	int	temp;

	if (!stack->array_a)
		return ;
	i = stack->size_array_a - 1;
	temp = stack->array_a[i];
	while (i >= 0)
	{
		stack->array_a[i] = stack->array_a[i - 1];
		i--;
	}
	stack->array_a[0] = temp;
	write(1, "rra\n", 4);
}
