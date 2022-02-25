/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:38:07 by yolee             #+#    #+#             */
/*   Updated: 2022/02/25 19:56:27 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_to_upper(unsigned int idx, char *str)
{
	str[idx] = ft_toupper(str[idx]);
}

void	parse_unsigned_decimal(va_list ap)
{
	unsigned int	nbr;
	char			*str;

	nbr = va_arg(ap, int);
	str = ft_uitoa(nbr);
	write(1, str, ft_strlen(str));
	free(str);
}

void	parse_lower_hexadecimal(va_list ap)
{
	int		nbr;
	char	*str;

	nbr = va_arg(ap, int);
	str = ft_itoa_hex(nbr);
	write(1, str, ft_strlen(str));
	free(str);
}

void	parse_upper_hexadecimal(va_list ap)
{
	int		nbr;
	char	*str;

	nbr = va_arg(ap, int);
	str = ft_itoa_hex(nbr);
	ft_striteri(str, &conv_to_upper);
	write(1, str, ft_strlen(str));
	free(str);
}
