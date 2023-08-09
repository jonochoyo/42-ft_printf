/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:19:29 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/08/09 16:39:15 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
Used itoa like function to convert an unsigned int into a hexadecimal string
in lowercase. It add "0x" at the beggining of the string. 
Prints the string and return its length. 

ft_get_size for pointers takes into account the "0x" when returning the len. 
*/

static int	ft_get_size(size_t nb)
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
	return (len + 2);
}

int	ft_print_p(size_t ptr)
{
	char	*str;
	int		size;

	size = ft_get_size(ptr);
	str = (char *) malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
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
	size = ft_print_s(str);
	free(str);
	return (size);
}
