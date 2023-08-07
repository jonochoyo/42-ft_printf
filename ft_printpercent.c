/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpercent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:34:07 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/08/07 17:48:35 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
Format a string with only one char '%' and NUL terminator as return value. 
*/

char	*ft_printpercent(void)
{
	char	*str;

	str = (char *) malloc(2);
	if (str == NULL)
		return (NULL);
	str[0] = '%';
	str[1] = '\0';
	return (str);
}