/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:18:46 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/08/07 17:30:01 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

// TESTING
# include <stdio.h>

char	*ft_printchar(char c);
char	*ft_printstr(char *s);
char	*ft_printnbr(int n);
char	*ft_printunbr(unsigned int n);
char	*ft_printlhex(unsigned int n);
char	*ft_strtoupper(char *s);
char	*ft_printptr(long long ptr);
char	*ft_printpercent(void);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s);
void	ft_putchar(char c);
int		ft_printf(const char *format, ...);

#endif
