/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 15:04:02 by chartema      #+#    #+#                 */
/*   Updated: 2022/03/10 15:04:05 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*dest;
	unsigned const char	*str;

	i = 0;
	dest = dst;
	str = src;
	if (str == 0 && dest == 0)
		return (NULL);
	while (i < n)
	{
		dest[i] = str[i];
		i++;
	}
	return (dst);
}
