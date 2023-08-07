/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:31:09 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/08/07 17:49:54 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
This function formats the string as "(null)" in the case we get a NULL arg.
Otherwise, it returns the string without modification.
*/

char	*ft_printstr(char *s)
{
	if (s == NULL)
		s = "(null)";
	return (s);
}
