/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 13:13:53 by chartema      #+#    #+#                 */
/*   Updated: 2022/04/15 13:55:28 by chartema      ########   odam.nl         */
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
void	sorting_machine(t_list **list_a, int ac);
//void	sorting_machine(t_list **list_a, t_list **list_b, int ac);
void	sort_two(t_list **list_a);
void	sort_three(t_list **list_a);
void	swap_a(t_list **list_a);
#endif