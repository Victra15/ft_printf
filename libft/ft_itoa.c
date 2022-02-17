/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 20:39:03 by yolee             #+#    #+#             */
/*   Updated: 2022/01/03 00:39:07 by yolee            ###   ########.fr       */
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

char	*ft_itoa(int n)
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
