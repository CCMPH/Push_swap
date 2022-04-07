/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 08:58:27 by chartema      #+#    #+#                 */
/*   Updated: 2022/04/06 14:26:55 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct stack
{
	int	*array_a;
	int	*array_b;

	int	size;
	int	size_array_a;
	int	size_array_b;

	int	smallest;
	int	pos_smallest;
	int	max_bits;

	int	*array_c;
	int	*pos_c;
}	t_stack;

void		ft_swap_a(t_stack *stack);
void		ft_swap_b(t_stack *stack);
void		ft_swap_a_and_b(t_stack *stack);
void		ft_push_a(t_stack *stack);
void		ft_push_b(t_stack *stack);
void		ft_sorting_machine(t_stack *stack);
void		ft_error(t_stack *stack);
void		ft_check_input(char *str, t_stack *stack);
void		ft_check_doubles(t_stack *stack);
int			ft_check_if_sorted(t_stack *stack);
void		ft_rotate_a(t_stack *stack);
void		ft_reverse_a(t_stack *stack);
void		ft_sort_big(t_stack *stack);
void		ft_what_is_happening(t_stack *stack);

#endif