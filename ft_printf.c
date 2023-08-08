/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:41:44 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/08/08 17:40:19 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 
ft_choose_print will take the placeholder and current arg from ft_printf.
It checks what type of variable is (cspdiuxX%) and use the corresponding print 
function to display on stdout. It also counts how many chars it printed and
return that to ft_printf to keep the count.
*/

static int	ft_choose_print(char c, va_list *args)
{
	int		print_count;

	if (c == 'c')
		print_count = ft_print_c(va_arg(*args, int));
	else if (c == 's')
		print_count = ft_print_s(va_arg(*args, char *));
	else if (c == 'd' || c == 'i')
		print_count = ft_print_di(va_arg(*args, int));
	else if (c == 'u')
		print_count = ft_print_u(va_arg(*args, unsigned int));
	else if (c == 'x')
		print_count = ft_print_x(va_arg(*args, unsigned int));
	else if (c == 'X')
		print_count = ft_print_upperx(va_arg(*args, unsigned int));
	else if (c == 'p')
		print_count = ft_print_p(va_arg(*args, size_t));
	else if (c == '%')
		print_count = ft_print_percent();
	else
		print_count = 0;
	return (print_count);
}

/*
The ft_printf function iterates through the "format" string and prints each 
character. When it finds a placeholder '%' it will move to the next
character and use it for ft_choose_print with the args pointer. 
*/

int	ft_printf(const char *format, ...)
{
	int		print_len;
	int		i;
	va_list	args;

	i = 0;
	print_len = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			print_len += ft_choose_print(format[i], &args);
		}
		else
		{
			ft_putchar(format[i]);
			print_len++;
		}
		i++;
	}
	va_end(args);
	return (print_len);
}
