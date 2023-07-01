/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emollebr <emollebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:06:16 by emollebr          #+#    #+#             */
/*   Updated: 2023/01/28 16:10:26 by emollebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"

int		ft_printf(const char *fmt, ...);

int		ft_putchar_int(int c);
int		ft_putstr_int(char *s);
int		ft_putunsigned(unsigned int nbr);
int		ft_puthex(unsigned int num, char fmt);
int		ft_printnum(long long int n);
int		ft_putptr(void *ptr);
char	*ft_itoa_printf(long long int n);

#endif
