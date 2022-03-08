/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:07:45 by yolee             #+#    #+#             */
/*   Updated: 2022/03/02 01:10:06 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	ft_intlen(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ft_str_input(char *i_str, unsigned int n, size_t len)
{
	i_str[len] = '\0';
	len--;
	if (n == 0)
		i_str[0] = '0';
	while (n)
	{
		i_str[len] = '0' + n % 10;
		n = n / 10;
		len--;
	}
}

char	*ft_uitoa(unsigned int n)
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
