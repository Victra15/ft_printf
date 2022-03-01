/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:38:07 by yolee             #+#    #+#             */
/*   Updated: 2022/03/02 00:21:58 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	conv_to_upper(unsigned int idx, char *str)
{
	if (idx >= 0)
		(*str) = ft_toupper((*str));
}

void	parse_unsigned_decimal(va_list *ap, size_t *print_len)
{
	unsigned int	nbr;
	char			*str;
	size_t			len;

	nbr = va_arg((*ap), int);
	str = ft_uitoa(nbr);
	len = ft_strlen(str);
	write(1, str, len);
	(*print_len) += len;
	free(str);
}

void	parse_lower_hexadecimal(va_list *ap, size_t *print_len)
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

void	parse_upper_hexadecimal(va_list *ap, size_t *print_len)
{
	int		nbr;
	char	*str;
	size_t	len;

	nbr = va_arg((*ap), int);
	str = ft_uitoa_hex(nbr);
	ft_striteri(str, &conv_to_upper);
	len = ft_strlen(str);
	write(1, str, len);
	(*print_len) += len;
	free(str);
}
