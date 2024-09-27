/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:15:45 by asaulnie          #+#    #+#             */
/*   Updated: 2024/06/14 18:11:30 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	temp_n(int n)
{
	int	num_digits;

	if (n == 0)
		return (1);
	num_digits = 0;
	while (n != 0)
	{
		n /= 10;
		num_digits++;
	}
	return (num_digits);
}

char	*ft_itoa(int n)
{
	int		num_digits;
	int		is_negative;
	int		i;
	char	*str;

	num_digits = temp_n(n);
	is_negative = (n < 0);
	i = num_digits + is_negative;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		return (str[0] = '0', str[1] = '\0', str);
	if (is_negative)
		str[0] = '-';
	str[i] = '\0';
	while (n != 0)
	{
		if (is_negative)
			str[--i] = -(n % 10) + '0';
		else
			str[--i] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
