/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:39:23 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/08/04 15:50:43 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printunbr(unsigned int n)
{
	if (n > 9)
	{
		ft_printunbr(n / 10);
	}
	ft_printchar((n % 10) + '0');
}
