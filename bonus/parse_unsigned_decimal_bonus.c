/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_unsigned_decimal_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:41:06 by yolee             #+#    #+#             */
/*   Updated: 2022/03/22 19:57:09 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	ft_intlen(unsigned int n, t_pflag *print_flags)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	if (print_flags->precision - len > 0)
		len += (print_flags->precision - len);
	return (len);
}

static void	ft_str_input(char *i_str, unsigned int n, size_t len)
{
	i_str[len] = '\0';
	len--;
	if (n == 0)
		i_str[len] = '0';
	while (n)
	{
		i_str[len] = '0' + n % 10;
		n = n / 10;
		len--;
	}
	ft_memset(i_str, '0', len + 1);
}

static char	*ft_flag_uitoa(unsigned int n, t_pflag *print_flags)
{
	char	*i_str;
	size_t	i_len;

	i_len = ft_intlen(n, print_flags);
	i_str = (char *)malloc(i_len + 1);
	if (i_str == 0)
		return (0);
	ft_str_input(i_str, n, i_len);
	return (i_str);
}

char	*parse_unsigned_decimal(va_list *ap, t_pflag *print_flags)
{
	unsigned int	nbr;
	char			*str;

	nbr = va_arg((*ap), int);
	str = ft_flag_uitoa(nbr, print_flags);
	return (str);
}
