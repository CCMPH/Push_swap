/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_big.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 13:49:15 by chartema      #+#    #+#                 */
/*   Updated: 2022/04/07 09:15:41 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //voor printf

void	ft_find_pos(t_stack *stack);

void	ft_find_max_bits(t_stack *stack)
{
	int	i;
	int	max_num;

	i = 0;
	max_num = stack->size - 1;
	// while (i < stack->size)
	// {
	// 	if (stack->array_c[i] > stack->max)
	// 		stack->max = stack->array_c[i];
	// 	i++;
	// }
	while (max_num >> stack->max_bits != 0)
		stack->max_bits++;
	//printf("wat is max_bits %d\n", stack->max_bits);
}

void	ft_radix(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	//printf("wat is max_bits %d\n", stack->max_bits);
	// printf("Stack %03d a: %d Pos : %d\n", i, stack->array_a[0], stack->pos_c[0]);
	// printf("Stack %03d a: %d Pos : %d\n", i, stack->array_a[1], stack->pos_c[1]);
	// printf("Stack %03d a: %d Pos : %d\n", i, stack->array_a[2], stack->pos_c[2]);
	// printf("Stack %03d a: %d Pos : %d\n", i, stack->array_a[3], stack->pos_c[3]);
	// printf("Stack %03d a: %d Pos : %d\n", i, stack->array_a[4], stack->pos_c[4]);
	// printf("Stack %03d a: %d Pos : %d\n", i, stack->array_a[5], stack->pos_c[5]);
	while (i < stack->max_bits)
	{
		j = 0;
		ft_find_pos(stack);
		while (j < stack->size)
		{
			//printf("Dit is array_c[j] %d\n", stack->array_c[j]);
			if (((stack->pos_c[j] >> i) & 1) == 0)
				ft_push_b(stack);
			else
				ft_rotate_a(stack);
			j++;
			//ft_what_is_happening(stack);
		}
		while (stack->size_array_b > 0)
			ft_push_a(stack);
		i++;
	}
}

void	ft_find_pos(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < stack->size)
	{
		while (i < stack->size)
		{
			if (stack->array_c[i] == stack->array_a[j])
				stack->pos_c[j] = i;
			i++;
		}
		i = 0;
		j++;
	}
	// printf("Stack %03d a: %d Pos : %d\n", i, stack->array_a[0], stack->pos_c[0]);
	// printf("Stack %03d a: %d Pos : %d\n", i, stack->array_a[1], stack->pos_c[1]);
	// printf("Stack %03d a: %d Pos : %d\n", i, stack->array_a[2], stack->pos_c[2]);
	// printf("Stack %03d a: %d Pos : %d\n", i, stack->array_a[3], stack->pos_c[3]);
	// printf("Stack %03d a: %d Pos : %d\n", i, stack->array_a[4], stack->pos_c[4]);
	// printf("Stack %03d a: %d Pos : %d\n", i, stack->array_a[5], stack->pos_c[5]);
}

void	ft_sort_copy_stack(t_stack *stack)
{
	int	i;
	int	temp;
	int	swap;

	i = 0;
	swap = 1;
	while (swap != 0)
	{
		swap = 0;
		while (i < stack->size - 1)
		{
			if (stack->array_c[i] > stack->array_c[i + 1])
			{
				swap++;
				temp = stack->array_c[i];
				stack->array_c[i] = stack->array_c[i + 1];
				stack->array_c[i + 1] = temp;
			}
			i++;
		}
		i = 0;
	}
	// printf("dit is array c: %d\n", stack->array_c[0]);
	// printf("dit is array c: %d\n", stack->array_c[1]);
	// printf("dit is array c: %d\n", stack->array_c[2]);
	// printf("dit is array c: %d\n", stack->array_c[3]);
	// printf("dit is array c: %d\n", stack->array_c[4]);
	// printf("dit is array c: %d\n", stack->array_c[5]);
}

void	ft_sort_big(t_stack *stack)
{
	ft_sort_copy_stack(stack);
	ft_find_pos(stack);
	ft_find_max_bits(stack);
	ft_radix(stack);
}
