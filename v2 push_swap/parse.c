/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 09:30:55 by chartema      #+#    #+#                 */
/*   Updated: 2022/04/15 13:31:07 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h> //nodig voor max en min INT
#include <stdio.h> //nodig voor printf

// Checks if there are only integers
long	check_number(char *str)
{
	int		i;
	long	number;

	i = 0;
	if (!str)
		ft_error("Error1\n");
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error("Error\n");
		i++;
	}
	number = ft_atoi(str);
	if (number > INT_MAX || number < INT_MIN)
		ft_error("Error\n");
	return (number);
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
			if (*av[i] == *av[j])
				ft_error("Error\n");
			j++;
		}
		i++;
		j = i + 1;
	}
}

// Checks if the input is correct and puts input in a list
// * More than 1 argument GEBEURD DIT??
// * All arguments must be integers
// * No duplicates
void	parse_input(t_list **list, int ac, char **av)
{
	int		i;
	long	number;

	i = 1;
	while (i < ac)
	{
		//printf("Wat is av[i]: %s\n", av[i]);
		number = check_number(av[i]);
		ft_lstadd_back(list, ft_lstnew(number));
		i++;
	}
	check_duplicates(ac, av);
}
