/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 15:05:45 by chartema      #+#    #+#                 */
/*   Updated: 2022/03/10 15:05:48 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	l;
	unsigned int	i;

	if (*needle == 0)
		return ((char *)haystack);
	l = 0;
	while (haystack[l] != '\0' && l < len)
	{
		if (haystack[l] == needle[0])
		{
			i = 1;
			while (needle[i] != '\0' && haystack[l + i] == needle[i]
				&& (l + i) < len)
				i++;
			if (needle[i] == '\0')
				return ((char *)&haystack[l]);
		}
		l++;
	}
	return (0);
}
