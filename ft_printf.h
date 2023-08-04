/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:18:46 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/08/04 17:05:43 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

// TESTING
# include <stdio.h>

int		ft_printchar(char c);
int		ft_printstr(char *s);
void	ft_printnbr(int n);
void	ft_printunbr(unsigned int n);
void	ft_printlhex(unsigned int n);
size_t	ft_strlen(const char *s);
long	ft_get_size(long nb);
int		ft_printf(const char *format, ...);

#endif
