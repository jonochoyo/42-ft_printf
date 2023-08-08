#include "ft_printf.h"

/*
cc test.c -L. -lftprintf
*/

int	main(void)
{
	int	count; 
	int	libcount;

	// char	str[] = "Hello";

	count = ft_printf("Hello World %s %c %% %s %u %X %p\n", (char *) NULL, 'a', "again", -450, 4509, (char *) NULL);
	libcount = printf("Hello World %s %c %% %s %u %X %p\n", (char *) NULL, 'a', "again", -450, 4509, (char *) NULL);

	printf("My print count is: %i\n", count);
	printf("Library print count is: %i\n", libcount);
}