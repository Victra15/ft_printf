/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ptr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:36:33 by yolee             #+#    #+#             */
/*   Updated: 2022/03/22 19:57:05 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	ft_intlen(unsigned long long n, t_pflag *print_flags)
{
	size_t	len;

	len = 2;
	if (n == 0)
		len++;
	while (n)
	{
		n = n / 16;
		len++;
	}
	if (print_flags->precision - len > 0)
		len += (print_flags->precision - len);
	return (len);
}

static char	to_hex_str(unsigned long long nbr)
{
	int	abs_digit_nbr;

	abs_digit_nbr = (nbr % 16);
	if (abs_digit_nbr < 10)
		return ('0' + abs_digit_nbr);
	else
		return ('a' - 10 + abs_digit_nbr);
}

static void	ft_str_input(char *i_str, unsigned long long n, size_t len)
{
	i_str[len] = '\0';
	len--;
	if (n == 0)
	{
		i_str[len] = '0';
		len--;
	}
	while (n)
	{
		i_str[len] = to_hex_str(n);
		n = n / 16;
		len--;
	}
	ft_memset(i_str, '0', len + 1);
	i_str[0] = '0';
	i_str[1] = 'x';
}

static char	*ft_flag_ptoa(unsigned long long n, t_pflag *print_flags)
{
	char	*i_str;
	size_t	i_len;

	i_len = ft_intlen(n, print_flags);
	i_str = (char *)malloc(i_len + 1);
	if (i_str == NULL)
		return (NULL);
	ft_str_input(i_str, n, i_len);
	return (i_str);
}

char	*parse_ptr(va_list *ap, t_pflag *print_flags)
{
	void	*ptr;
	char	*str;

	ptr = va_arg((*ap), void *);
	str = ft_flag_ptoa((unsigned long long) ptr, print_flags);
	return (str);
}
