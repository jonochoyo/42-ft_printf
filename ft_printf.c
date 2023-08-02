/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:41:44 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/08/02 16:46:21 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

/* 
Trying printf with one string placeholder. 
Will need to have a function to check what type of argument we have. 
When we encounter a placeholder '%' will need to check what type of argument
it is and print accordingly. 
*/

int ft_printf(const char *format, char *str);

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

int ft_printf(const char *format, char *str)
{
	int	i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			// Print placeholder
			// ft_putchar_fd(c, 1);
			ft_putstr_fd(str, 1);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	printf("Hello World %s\n", "42");
	ft_printf("Hello World %s\n", "42");
}