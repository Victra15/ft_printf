/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_decimal_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:49:54 by yolee             #+#    #+#             */
/*   Updated: 2022/03/21 18:59:51 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
		n = n / 10;
		len++;
	}
	return (len);
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
		i_str[len] = '0' + (sign) * (n % 10);
		n = n / 10;
		len--;
	}
	if (sign == -1)
		i_str[len] = '-';
}

static char	*ft_itoa(int n, t_pflag *print_flags)
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

char	*parse_decimal(va_list *ap, t_pflag *print_flags)
{
	int		nbr;
	char	*str;
	size_t	len;

	nbr = va_arg((*ap), int);
	str = ft_itoa(nbr, print_flags);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
}
