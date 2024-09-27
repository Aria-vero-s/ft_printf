/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:12:49 by asaulnie          #+#    #+#             */
/*   Updated: 2024/06/17 15:33:17 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <ctype.h>
# include <stdio.h>
# include <stdint.h>
# include <stddef.h>

int		ft_printf(const char *s, ...);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
char	*ft_itoa_base(long unsigned int value, int base);
int		ft_printc(int c);
int		ft_prints(char	*s);
int		ft_printp(void *p);
int		ft_printd(int a);
int		ft_printi(int a);
int		ft_printu(unsigned int n);
int		ft_printx(unsigned int n);
int		ft_print88(unsigned int n);

#endif
