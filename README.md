# 42-ft_printf

## Introduction

The goal of this project is to recode printf( ). We will discover variadic functions in C.

## Mandatory Part

| Program name       | libftprintf.a                                                                               |
|--------------------|---------------------------------------------------------------------------------------------|
|Turn in files:      |Makefile, *.h, */\*.h, *.c, */\*.c                                                           |
|Makefile:           |NAME, all, clean, fclean, re                                                                 |
|External functions: |malloc, free, write, va_start, va_arg, va_copy, va_end                                       |
|Libft authorized:   |Yes                                                                                          |
|Description:        |Write a library that contains ft_printf( ), a function that will mimic the original printf( )|

The prototype of ft_printf( ) is:  
`int ft_printf(const char *, ...);`

Here are the requirements:

- Don’t implement the buffer management of the original printf( ).
- The function has to handle the following conversions: cspdiuxX%
- The function will be compared against the original printf( ).
- We must use the command `ar` to create the library.
- Using the `libtool` command is forbidden.
- The libftprintf.a has to be created at the root of the repository.

We  have to implement the following conversions:

- %c Prints a single character.
- %s Prints a string (as defined by the common C convention).
- %p The void * pointer argument has to be printed in hexadecimal format.
- %d Prints a decimal (base 10) number.
- %i Prints an integer in base 10.
- %u Prints an unsigned decimal (base 10) number.
- %x Prints a number in hexadecimal (base 16) lowercase format.
- %X Prints a number in hexadecimal (base 16) uppercase format.
- %% Prints a percent sign.
