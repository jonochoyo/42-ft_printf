/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:02:13 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/08/07 17:50:26 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
This function turns a string to Upper case. 
*/

char	*ft_strtoupper(char *s)
{
	int	i;
	
	i = 0;
	while (s[i] != '\0')
	{
		if ('a' <= s[i] && s[i] <= 'z')
			s[i] = (s[i] - 32);
		i++;
	}
	return (s);
}