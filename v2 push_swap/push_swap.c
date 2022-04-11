/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 13:12:55 by chartema      #+#    #+#                 */
/*   Updated: 2022/04/07 13:14:35 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_number(char *str)
{
	int		i;
	long	nr;

	i = 0;
	if (!str[i])
		//ERROR
	while (str[i])
	{
		nr = ft_atoi(str[i]);
		if (nr > INT_MAX || nr < INT_MIN)
			//ERROR
		i++;
	}
}

// Checks if there are dublicates KORTER MAKEN!!
void	check_dublicates(int ac, char **av)
{
	int	i;
	int	j;
	int	*array;

	i = 0;
	array = malloc(sizeof(int) * ac - 1);
	if (!array)
		//ERROR
	while (i < ac - 1)
	{
		array[i] = ft_atoi(av[i]);
		i++;
	}
	i = 0
	j = 1;
	while (i < ac - 1)
	{
		while (j < ac)
		{
			if (array[i] == array[j])
				//ERROR
			j++;
		}
		i++;
		j = i + 1;
	}
	free(array);
}

// Checks if the input is correct
// * More than 1 argument GEBEURD DIT??
// * All arguments must be integers
// * No duplicates
void	check_input(int ac, char **av)
{
	int	i;
	int	arguments;
	int	*array;

	i = 1;
	arguments = ac - 1;
	while (i < arguments)
	{
		check_number(av[i]);
		i++;
	}
	check_dublicates(ac, av);
}

int	main(int ac, char **av)
{
	t_stack	*list_a;
	t_stack	*list_b;

	if (ac == 1 ||!av)
		return (0);
	list_a = NULL;
	list_b = NULL;

	check_input(ac, av);
	return (0);
	}

	// https://github.com/pderksen98/push_swap/blob/master/src/error.c
	// https://github.com/rvan-mee/push_swap/blob/master/src/mandatory/main.c
	