/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:07:45 by yolee             #+#    #+#             */
/*   Updated: 2022/03/02 01:10:01 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	ft_intlen(unsigned long long n)
{
	size_t	len;

	len = 2;
	if (n == 0)
		return (3);
	while (n)
	{
		n = n / 16;
		len++;
	}
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
	i_str[0] = '0';
	i_str[1] = 'x';
	if (n == 0)
		i_str[2] = '0';
	while (n)
	{
		i_str[len] = to_hex_str(n);
		n = n / 16;
		len--;
	}
}

char	*ft_ptoa(unsigned long long n)
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
