/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:41:37 by asaulnie          #+#    #+#             */
/*   Updated: 2024/06/15 12:45:10 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printp(void *p)
{
	long unsigned int	addr;
	char				*str;
	int					len;

	addr = (long unsigned int)p;
	if (!p)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	str = ft_itoa_base(addr, 16);
	len = 0;
	if (str != NULL)
	{
		write(1, "0x", 2);
		write(1, str, ft_strlen(str));
		len = ft_strlen(str) + 2;
		free(str);
	}
	return (len);
}
