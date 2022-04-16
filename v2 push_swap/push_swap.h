/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 13:13:53 by chartema      #+#    #+#                 */
/*   Updated: 2022/04/16 13:30:28 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

// FUNCTIONS

// Parse & Checks
void	parse_input(t_list **list, int ac, char **av);
int		check_if_sorted(t_list **list);

// Error
void	ft_error(char *error);

// Sorting
void	sorting_machine(t_list **list_a, t_list **list_b, int ac);
void	swap_a(t_list **list_a);
void	rotate_a(t_list **list_a);
void	reverse_a(t_list **list_a);
void	push_b(t_list **list_a, t_list **list_b);
void	push_a(t_list **list_a, t_list **list_b);
#endif