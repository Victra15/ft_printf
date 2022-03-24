/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_upper_hexadecimal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:47:02 by yolee             #+#    #+#             */
/*   Updated: 2022/03/24 15:46:10 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_intlen(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		len++;
	}
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

static void	ft_str_input(char *i_str, unsigned int n, size_t len)
{
	i_str[len] = '\0';
	len--;
	if (n == 0)
		i_str[0] = '0';
	while (n)
	{
		i_str[len] = to_hex_str(n);
		n = n / 16;
		len--;
	}
}

static char	*ft_uitoa_hex(unsigned int n)
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

void	parse_upper_hexadecimal(va_list *ap, int *print_len)
{
	int		nbr;
	char	*str;
	size_t	len;

	nbr = va_arg((*ap), int);
	str = ft_uitoa_hex(nbr);
	len = ft_strlen(str);
	write(1, str, len);
	(*print_len) += len;
	free(str);
}
