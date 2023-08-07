/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:59:21 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/08/07 17:45:54 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
Used itoa like function to get an unsigned int and format it like a hexadecimal
string for printing.
*/

static int	ft_get_size(unsigned int nb)
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
	return (len);
}

char	*ft_printlhex(unsigned int n)
{
	char	*str;
	int		size;

	size = ft_get_size(n);
	str = (char *) malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[size] = '\0';
	while (n != 0)
	{
		size--;
		str[size] = "0123456789abcdef"[n % 16];
		n = n / 16;
	}
	return (str);
}
