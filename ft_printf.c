/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:41:44 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/08/07 18:22:06 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 
ft_choose_print will take the placeholder and current arg. It will format the
string to print according to the type of placeholder. 
Once we have the string to print, we check if its NULL and print it. 
*/

static int	ft_choose_print(char c, va_list *args)
{
	char	*str;

	str = NULL;
	if (c == 's')
		str = ft_printstr(va_arg(*args, char *));
	else if (c == 'c')
		str = ft_printchar(va_arg(*args, int));
	else if (c == 'i' || c == 'd')
		str = ft_printnbr(va_arg(*args, int));
	else if (c == 'u')
		str = ft_printunbr((unsigned int) va_arg(*args, int));
	else if (c == 'x')
		str = ft_printlhex((unsigned int) va_arg(*args, int));
	else if (c == 'X')
		str = ft_strtoupper(ft_printlhex((unsigned int) va_arg(*args, int)));
	else if (c == 'p')
		str = ft_printptr((long long) va_arg(*args, long long));
	else if (c == '%')
		str = ft_printpercent();
	if (str != NULL)
		ft_putstr(str);
	return (ft_strlen(str));
}

/*
The ft_printf function iterates through the 'format' string argument and
prints each character. When it finds a placeholder '%' it will move to the next
character and send that one to the ft_choose_print function. That will check
what type of variable is (cspdiuxX%) and use the corresponding print function
to print on the terminal. It will also count how many chars it printed and
return that to ft_printf to keep the count.
*/

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		counter;

	i = 0;
	counter = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			counter += ft_choose_print(format[i], &args);
		}
		else
		{
			ft_putchar(format[i]);
			counter++;
		}
		i++;
	}
	va_end(args);
	return (counter);
}

// int	main(void)
// {
// 	int	count; 
// 	int	libcount;

// 	// char	str[] = "Hello";

// 	count = ft_printf("Hello World %s %c %% %s %u %X %p\n", (char *) NULL, 'a', "again", -450, 4509, (char *) NULL);
// 	libcount = printf("Hello World %s %c %% %s %u %X %p\n", (char *) NULL, 'a', "again", -450, 4509, (char *) NULL);

// 	printf("My print count is: %i\n", count);
// 	printf("Library print count is: %i\n", libcount);
// }
