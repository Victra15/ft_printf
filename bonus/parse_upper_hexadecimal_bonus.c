/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_upper_hexadecimal_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:47:02 by yolee             #+#    #+#             */
/*   Updated: 2022/03/22 20:06:34 by yolee            ###   ########.fr       */
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
		n = n / 16;
		len++;
	}
	if (print_flags->precision - len > 0)
		len += (print_flags->precision - len);
	if (print_flags->alter_form == 1)
		len += 2;
	return (len);
}

static char	to_hex_str(unsigned int nbr)
{
	unsigned int	abs_digit_nbr;

	abs_digit_nbr = nbr % 16;
	if (abs_digit_nbr < 10)
		return ('0' + abs_digit_nbr);
	else
		return ('A' - 10 + abs_digit_nbr);
}

static void	ft_str_input(char *i_str,
		unsigned int n,
		size_t len,
		t_pflag *print_flags)
{
	i_str[len] = '\0';
	len--;
	if (n == 0)
		i_str[len] = '0';
	while (n)
	{
		i_str[len] = to_hex_str(n);
		n = n / 16;
		len--;
	}
	ft_memset(i_str, '0', len + 1);
	if (print_flags->alter_form == 1)
	{
		i_str[0] = '0';
		i_str[1] = 'X';
	}
}

static char	*ft_flag_uitoa_hex(unsigned int n, t_pflag *print_flags)
{
	char	*i_str;
	size_t	i_len;

	i_len = ft_intlen(n, print_flags);
	i_str = (char *)malloc(i_len + 1);
	if (i_str == 0)
		return (0);
	ft_str_input(i_str, n, i_len, print_flags);
	return (i_str);
}

char	*parse_upper_hexadecimal(va_list *ap, t_pflag *print_flags)
{
	int		nbr;
	char	*str;

	nbr = va_arg((*ap), int);
	str = ft_flag_uitoa_hex(nbr, print_flags);
	return (str);
}
