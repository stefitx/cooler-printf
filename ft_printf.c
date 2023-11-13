/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:59:31 by atudor            #+#    #+#             */
/*   Updated: 2023/10/14 22:58:01 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	if (*count != -1)
	{
		if (write(1, &c, 1) == -1)
			*count = -1;
		else
			*count += 1;
	}
}

void	ft_putstr(char *s, int *count)
{
	if (!s)
		ft_putstr("(null)", count);
	else
	{
		while (*s && *count != -1)
		{
			ft_putchar(*s, count);
			s++;
		}
	}
}

void	ft_numbers(unsigned long n, unsigned long base, char check, int *count)
{
	if ((long int)n < 0 && check == 'd')
	{
		n *= -1;
		ft_putchar('-', count);
	}
	if (n >= base)
		ft_numberss(n / base, base, check, count);
	if (check == 'X')
		ft_putchar("0123456789ABCDEF"[(unsigned int)n % base], count);
	else
		ft_putchar("0123456789abcdef"[(unsigned int)n % base], count);
}

void	check(va_list args, char s, int *count)
{
	if (s == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (s == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (s == '%')
		ft_putchar('%', count);
	if (s == 'd' || s == 'i')
		ft_numberss(va_arg(args, int), 10, 'd', count);
	if (s == 'u')
		ft_numberss(va_arg(args, unsigned int), 10, 'u', count);
	if (s == 'x')
		ft_numberss(va_arg(args, unsigned int), 16, 'x', count);
	if (s == 'X')
		ft_numberss(va_arg(args, unsigned int), 16, 'X', count);
	if (s == 'p')
	{
		ft_putstr("0x", count);
		ft_numberss(va_arg(args, unsigned long), 16, 'x', count);
	}
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	if (!str)
		return (0);
	count = 0;
	va_start(args, str);
	while (*str && count != -1)
	{
		if (*str == '%')
		{
			str++;
			check(args, *str, &count);
		}
		else
			ft_putchar(*str, &count);
		if (str)
			str++;
	}
	va_end(args);
	return (count);
}
/*
#include <stdio.h>
 int main()
 {
 	int a, b;
 	char *str;

 	str = "hi.";
 	 //char c = 'A';
 	 //char *s = "hiii";
 	//a = printf("rl printf: %p\n", (void *)-ULONG_MAX);
 	//b = ft_printf("my printf: %p\n", (void *)-ULONG_MAX);
 	a = printf("Printf: 'Helloaa'\n");
 	b = ft_printf("Yours: 'Helloaa'\n");
 	printf( "\n%d\n", a);
 	printf( "%d\n", b);
 	//printf( "%d\n", printf("%s\n", s));

 	return 0;
 }
*/