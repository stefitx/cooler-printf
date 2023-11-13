/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 05:41:19 by atudor            #+#    #+#             */
/*   Updated: 2023/10/14 22:51:58 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

void	ft_putchar(char s, int *count);
int		ft_printf(char const *str, ...);
void	ft_putstr(char *s, int *count);
void	ft_numbers(unsigned long n, unsigned long base, char check, int *count);

#endif
