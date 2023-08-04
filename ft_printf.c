/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:41:44 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/08/04 17:28:06 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 
The ft_printf function iterates through the 'format' string argument and
prints each character. When it finds a placeholder '%' it will move to the next
character and send that one to the ft_choose_print function. That will check
what type of variable is (cspdiuxX%) and use the corresponding print function
to print on the terminal. It will also count how many chars it printer and
return that to ft_printf to keep the count.

For int and uint, used putnbr and get size to print and get the count. 
For unsigned, we ensure to convert the given number to uint and then 
print/count. 

Tried ints with putnbr but may need to check on that as we need to return 
the total characters printed. 

Modified helper functions to return their print count which is then returned
by ft_choose_print to count the chars printed. 

Trying to print lowercase hex. Created function and getting outputs with error
so far. 
*/

static int	ft_choose_print(char c, va_list args)
{
	int				print_count;
	int				nbr;
	unsigned int	unbr;

	print_count = 0;
	if (c == 's')
		print_count = ft_printstr(va_arg(args, char *));
	else if (c == 'c')
		print_count = ft_printchar(va_arg(args, int));
	else if (c == 'i' || c == 'd')
	{
		nbr = va_arg(args, int);
		ft_printnbr(nbr);
		print_count = ft_get_size(nbr);
	}
	else if (c == 'u')
	{
		unbr = va_arg(args, int);
		ft_printunbr(((unsigned int) unbr));
		print_count = ft_get_size((unsigned int) unbr);
	}
	else if (c == 'x')
	{
		unbr = va_arg(args, int);
		ft_printlhex(((unsigned int) unbr));
	}
	else if (c == '%')
		print_count = ft_printchar('%');
	return (print_count);
}

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
			counter += ft_choose_print(format[i], args);
		}
		else
		{
			ft_printchar(format[i]);
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

// 	count = ft_printf("Hello World %s %c %% %s %c %u %i %i\n", NULL, 'a', "again", 'x', -450, 00, 5555);
// 	libcount = printf("Hello World %s %c %% %s %c %u %i %i\n", NULL, 'a', "again", 'x', -450, 00, 5555);

// 	printf("My print count is: %i\n", count);
// 	printf("Library print count is: %i\n", libcount);
// }
