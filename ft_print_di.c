/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:46:37 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/08/09 16:37:54 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
Used itoa like function to convert an integer into a string.
Prints the string and return its length. 
*/

static int	ft_get_size(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	ft_print_di(int n)
{
	char			*str;
	int				size;
	unsigned int	nbr;

	size = ft_get_size(n);
	str = (char *) malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	nbr = n;
	if (n < 0)
	{
		str[0] = '-';
		nbr = n * (-1);
	}
	if (nbr == 0)
		str[0] = '0';
	str[size] = '\0';
	while (nbr != 0)
	{
		str[--size] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	size = ft_print_s(str);
	free(str);
	return (size);
}
