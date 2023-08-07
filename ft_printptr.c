/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:19:29 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/08/07 17:34:22 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
ft_get_size for pointers takes into account the "0x" when returning the len. 
*/

static int	ft_get_size(long long nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 16;
		len++;
	}
	return (len + 2);
}

char	*ft_printptr(long long ptr)
{
	char	*str;
	int		size;

	size = ft_get_size(ptr);
	str = (char *) malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	if (ptr == 0)
		str[2] = '0';
	str[0] = '0';
	str[1] = 'x';
	str[size] = '\0';
	while (ptr != 0)
	{
		size--;
		str[size] = "0123456789abcdef"[ptr % 16];
		ptr = ptr / 16;
	}
	return (str);
}
