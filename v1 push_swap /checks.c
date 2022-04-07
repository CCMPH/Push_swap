/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 11:21:02 by chartema      #+#    #+#                 */
/*   Updated: 2022/03/25 09:59:09 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_stack *stack)
{
	if (stack->array_a)
		free(stack->array_a);
	if (stack->array_b)
		free(stack->array_b);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_check_input(char *str, t_stack *stack)
{
	//long	number;
	int		negorpos;

	//number = 0;
	negorpos = 1;
	// if (*str == '-')
	// 	negorpos = -1;
	while (*str != '\0')
	{
		if (*str != '-' && !(*str >= '0' && *str <= '9'))
			ft_error(stack);
		str++;
		// nog iets inbouwen met min max input
	}
}

void	ft_check_doubles(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < stack->size - 1)
	{
		while (j < stack->size)
		{
			if (stack->array_a[i] == stack->array_a[j])
				ft_error(stack);
			j++;
		}
		i++;
		j = i + 1;
	}
}

int	ft_check_if_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->array_a[i] > stack->array_a[i + 1])
			return (1);
		i++;
	}
	return (0);
}
