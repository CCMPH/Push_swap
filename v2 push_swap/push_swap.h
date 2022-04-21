/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 13:13:53 by chartema      #+#    #+#                 */
/*   Updated: 2022/04/21 13:59:22 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	int				value;
	int				position;
	struct s_list	*next;
}				t_list;

// FUNCTIONS

// Parse & Checks
void	parse_input(t_list **list, int ac, char **av);
int		check_if_sorted(t_list **list);

// Error
void	ft_error(char *error);

// Sorting
void	sorting_machine(t_list **list_a, t_list **list_b, int ac);
void	sort_big(t_list **list_a, t_list **list_b, int ac);
int		find_pos_lowest(t_list **list_a);
void	swap_a(t_list **list_a);
void	rotate_a(t_list **list_a);
void	reverse_a(t_list **list_a);
void	push_b(t_list **list_a, t_list **list_b);
void	push_a(t_list **list_a, t_list **list_b);

//Utils
int		ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_atoi_push_swap(const char *str);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int value);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)());
void	ft_lstclear(t_list **lst, void (*del)());

// testen
int		what_is_happening_b(t_list *list_a, t_list *list_b);
#endif