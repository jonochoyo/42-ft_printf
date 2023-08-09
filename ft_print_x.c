/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:59:21 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/08/09 16:27:28 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
Used itoa like function to convert an unsigned int into a hexadecimal string
for lower and uppercase hex types. It takes a char to check if it is x or X.
Prints the string and return its length. 
*/

static int	ft_get_size(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

int	ft_print_x(unsigned int n, char c)
{
	char	*str;
	int		size;

	size = ft_get_size(n);
	str = (char *) malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	if (n == 0)
		str[0] = '0';
	str[size] = '\0';
	while (n != 0)
	{
		size--;
		if (c == 'x')
			str[size] = "0123456789abcdef"[n % 16];
		else
			str[size] = "0123456789ABCDEF"[n % 16];
		n = n / 16;
	}
	size = ft_print_s(str);
	free(str);
	return (size);
}
