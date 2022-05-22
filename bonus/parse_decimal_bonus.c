/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_decimal_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:49:54 by yolee             #+#    #+#             */
/*   Updated: 2022/05/22 11:09:15 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	ft_intlen(int n, t_pflag *print_flags)
{
	size_t	len;

	len = 0;
	if (n == 0)
		if (print_flags->precision != 0)
			len++;
	if (n < 0)
		print_flags->sign_display = 1;
	while (n)
	{
		n = n / 10;
		len++;
	}
	if ((int)(print_flags->precision - len) > 0)
		len += (int)(print_flags->precision - len);
	if (print_flags->sign_display == 1 || print_flags->add_blank == 1)
		len++;
	return (len);
}

static void	ft_str_input(char *i_str, int n, size_t len, t_pflag *print_flags)
{
	int	sign;

	sign = 1;
	len--;
	if (n == 0)
	{
		i_str[len] = '0';
		len--;
	}
	if (n < 0)
		sign = -1;
	while (n)
	{
		i_str[len] = '0' + (sign) * (n % 10);
		n = n / 10;
		len--;
	}
	ft_memset(i_str, '0', len + 1);
	if (print_flags->add_blank == 1)
		i_str[0] = ' ';
	if (print_flags->sign_display == 1)
		i_str[0] = '+';
	if (sign == -1)
		i_str[0] = '-';
}

static char	*ft_flag_itoa(int n, t_pflag *print_flags)
{
	char	*i_str;
	size_t	i_len;

	i_len = ft_intlen(n, print_flags);
	i_str = (char *)malloc(sizeof(char) * (i_len + 1));
	i_str[i_len] = '\0';
	if (i_str == NULL)
		return (NULL);
	if (i_len != 0)
		ft_str_input(i_str, n, i_len, print_flags);
	return (i_str);
}

static void	flag_ignore(t_pflag *print_flags)
{
	print_flags->alter_form = 0;
}

char	*parse_decimal(va_list *ap, t_pflag *print_flags)
{
	char	*str;
	int		nbr;

	flag_ignore(print_flags);
	nbr = va_arg((*ap), int);
	str = ft_flag_itoa(nbr, print_flags);
	return (str);
}
