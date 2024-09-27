/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print88.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:41:48 by asaulnie          #+#    #+#             */
/*   Updated: 2024/06/14 18:11:30 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print88(unsigned int n)
{
	char	*hexa;
	int		count;

	hexa = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
	{
		count = count + ft_print88(n / 16);
		count = count + ft_print88(n % 16);
	}
	else
	{
		write(1, &hexa[n], 1);
		count++;
	}
	return (count);
}
