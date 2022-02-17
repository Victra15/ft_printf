/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 00:02:01 by yolee             #+#    #+#             */
/*   Updated: 2022/01/07 03:40:41 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static void	ft_str_input(char *buf, int n, size_t len)
{
	int	sign;

	buf[len] = '\0';
	len--;
	if (n == 0)
		buf[0] = '0';
	if (n < 0)
		sign = -1;
	else
		sign = 1;
	while (n)
	{
		buf[len] = '0' + (sign) * (n % 10);
		n = n / 10;
		len--;
	}
	if (sign == -1)
		buf[len] = '-';
}

static void	ft_itoa_static(char *buf, int n)
{
	size_t	i_len;

	i_len = ft_intlen(n);
	ft_str_input(buf, n, i_len);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	buf[12];

	ft_itoa_static(buf, n);
	ft_putstr_fd(buf, fd);
}
