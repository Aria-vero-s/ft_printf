/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:49:42 by asaulnie          #+#    #+#             */
/*   Updated: 2024/06/15 15:42:35 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flags(va_list arg, char s)
{
	int	count;

	count = 0;
	if (s == 'c')
		count = count + ft_printc(va_arg(arg, int));
	else if (s == 's')
		count = count + ft_prints(va_arg(arg, char *));
	else if (s == 'p')
		count = count + ft_printp(va_arg(arg, void *));
	else if (s == 'd')
		count = count + ft_printd(va_arg(arg, int));
	else if (s == 'i')
		count = count + ft_printi(va_arg(arg, int));
	else if (s == 'u')
		count = count + ft_printu(va_arg(arg, unsigned int));
	else if (s == 'x')
		count = count + ft_printx(va_arg(arg, unsigned int));
	else if (s == 'X')
		count = count + ft_print88(va_arg(arg, unsigned int));
	else if (s == '%')
		count = count + ft_printc('%');
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	count;

	va_list(arg);
	va_start(arg, str);
	i = 0;
	count = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			count = count + flags(arg, str[i]);
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	va_end(arg);
	return (count);
}
