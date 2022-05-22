/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lower_hexadecimal_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:05:33 by yolee             #+#    #+#             */
/*   Updated: 2022/05/21 06:09:17 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	ft_intlen(unsigned int n, t_pflag *print_flags)
{
	size_t	len;

	len = 0;
	if (n == 0)
	{
		print_flags->alter_form = 0;
		if (print_flags->precision != 0)
			len++;
	}
	while (n)
	{
		n = n / 16;
		len++;
	}
	if ((int)(print_flags->precision - len) > 0)
		len += (int)(print_flags->precision - len);
	if (print_flags->alter_form == 1)
		len += 2;
	return (len);
}

static void	ft_str_input(char *i_str,
		unsigned int n,
		size_t len,
		t_pflag *print_flags)
{
	i_str[len] = '\0';
	if (len == 0)
		return ;
	len--;
	if (n == 0)
		i_str[len] = '0';
	while (n)
	{
		if ((n % 16) < 10)
			i_str[len] = ('0' + (n % 16));
		else
			i_str[len] = ('a' - 10 + (n % 16));
		n = n / 16;
		len--;
	}
	ft_memset(i_str, '0', len + 1);
	if (print_flags->alter_form == 1)
	{
		i_str[0] = '0';
		i_str[1] = 'x';
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

static void	flag_ignore(t_pflag *print_flags)
{
	print_flags->add_blank = 0;
	print_flags->sign_display = 0;
}

char	*parse_lower_hexadecimal(va_list *ap, t_pflag *print_flags)
{
	int		nbr;
	char	*str;

	flag_ignore(print_flags);
	nbr = va_arg((*ap), int);
	str = ft_flag_uitoa_hex(nbr, print_flags);
	return (str);
}
