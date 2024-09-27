/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:48:31 by asaulnie          #+#    #+#             */
/*   Updated: 2024/06/14 19:53:50 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(long unsigned int value, int base)
{
	char				*str;
	char				*base_str;
	int					len;
	long unsigned int	temp;

	base_str = "0123456789abcdef";
	len = 0;
	temp = value;
	while (temp != 0)
	{
		temp = temp / base;
		len++;
	}
	if (value == 0)
		len = 1;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = base_str[value % base];
		value = value / base;
	}
	return (str);
}
