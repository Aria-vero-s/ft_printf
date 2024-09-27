/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:41:34 by asaulnie          #+#    #+#             */
/*   Updated: 2024/06/14 18:11:30 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printi(int a)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	str = ft_itoa(a);
	len = ft_strlen(str);
	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
		free(str);
	}
	return (len);
}
