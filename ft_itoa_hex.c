/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:07:45 by yolee             #+#    #+#             */
/*   Updated: 2022/02/24 19:21:25 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_intlen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static char	to_hex_str(int sign, int nbr)
{
	int	abs_digit_nbr;

	abs_digit_nbr = (sign) * (nbr % 16);
	if (abs_digit_nbr < 10)
		return ('0' + abs_digit_nbr);
	else
		return ('a' - 10 + abs_digit_nbr);
}

static void	ft_str_input(char *i_str, int n, size_t len)
{
	int	sign;

	i_str[len] = '\0';
	len--;
	if (n == 0)
		i_str[0] = '0';
	if (n < 0)
		sign = -1;
	else
		sign = 1;
	while (n)
	{
		i_str[len] = to_hex_str(sign, n);
		n = n / 16;
		len--;
	}
	if (sign == -1)
		i_str[len] = '-';
}

char	*ft_itoa_hex(int n)
{
	char	*i_str;
	size_t	i_len;

	i_len = ft_intlen(n);
	i_str = (char *)malloc(i_len + 1);
	if (i_str == 0)
		return (0);
	ft_str_input(i_str, n, i_len);
	return (i_str);
}
