/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:31:09 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/08/08 17:37:57 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
This function formats the string as "(null)" in the case we get a NULL arg.
Prints the string and returns its length. 
*/

int	ft_print_s(char *s)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (ft_strlen("(null)"));
	}
	else
	{
		write(1, s, ft_strlen(s));
	}
	return (ft_strlen(s));
}
