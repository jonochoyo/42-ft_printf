/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:08:30 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/08/09 16:25:32 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
Used itoa like function to convert an unsigned int into a string.
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
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	ft_print_u(unsigned int n)
{
	char			*str;
	int				size;

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
		str[size] = (n % 10) + '0';
		n = n / 10;
	}
	size = ft_print_s(str);
	free(str);
	return (size);
}
