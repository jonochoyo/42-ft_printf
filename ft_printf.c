/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:41:44 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/08/03 17:50:56 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/* 
Trying printf with variadic function and only string and char arguments. 
Added a helper function to check what type of placeholder argument we have. 
When we encounter a placeholder '%' will need to check what type of argument
it is and print accordingly. 

Tried ints with putnbr but may need to check on that as we need to return 
the total characters printed. 
*/

int	ft_printf(const char *format, ...);

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = n * (-1);
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + '0', fd);
}

void	ft_choose_print(char c, va_list args)
{
	if (c == 's')
	{
		ft_putstr_fd(va_arg(args, char *), 1);
	}
	else if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
	}
	else if (c == 'i')
	{
		ft_putnbr_fd(va_arg(args, int), 1);
	}
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			// Print placeholder
			ft_choose_print(format[i], args);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (0);
}

// int	main(void)
// {
// 	int x = printf("HelloWorld%s,%i\n", "42", 453);
// 	printf("%i\n", x);
// 	ft_printf("Hello World %s %c %s %c %i\n", "42", 'a', "again", 'x', 453);
// }