/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_unsigned_decimal_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:41:06 by yolee             #+#    #+#             */
/*   Updated: 2022/03/22 18:45:36 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*parse_unsigned_decimal(va_list *ap, t_pflag *print_flags)
{
	unsigned int	nbr;
	char			*str;
	size_t			len;

	nbr = va_arg((*ap), int);
	str = ft_uitoa(nbr);
	return (str);
}
