/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:41:43 by asaulnie          #+#    #+#             */
/*   Updated: 2024/06/15 13:35:07 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printu(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n > 9)
	{
		count = count + ft_printu(n / 10);
		count = count + ft_printu(n % 10);
	}
	else
		count = count + ft_printc(n + 48);
	return (count);
}
