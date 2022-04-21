/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 09:30:55 by chartema      #+#    #+#                 */
/*   Updated: 2022/04/21 13:58:32 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //nodig voor NULL

int	check_number(char *str)
{
	int		i;

	i = 0;
	if (!str)
		ft_error("Error\n");
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error("Error\n");
		i++;
	}
	return (ft_atoi_push_swap(str));
}

void	check_duplicates(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < ac - 1)
	{
		while (j < ac)
		{
			if (av[i] == av[j])
				ft_error("Error\n");
			j++;
		}
		i++;
		j = i + 1;
	}
}

void	parse_input(t_list **list, int ac, char **av)
{
	int		i;
	long	number;
	t_list	*temp;

	i = 1;
	while (i < ac)
	{
		number = check_number(av[i]);
		temp = ft_lstnew(number);
		if (!temp)
		{
			ft_lstclear(list, NULL);
			ft_error("Error\n");
		}
		ft_lstadd_back(list, temp);
		i++;
	}
	check_duplicates(ac, av);
}
