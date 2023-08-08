/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:18:46 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/08/08 17:34:27 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

// TESTING
# include <stdio.h>

int		ft_print_c(char c);
int		ft_print_s(char *s);
int		ft_print_di(int n);
int		ft_print_u(unsigned int n);
int		ft_print_x(unsigned int n);
int		ft_print_upperx(unsigned int n);
int		ft_print_p(size_t ptr);
int		ft_print_percent(void);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s);
void	ft_putchar(char c);
int		ft_printf(const char *format, ...);

#endif
