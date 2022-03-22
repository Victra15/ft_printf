/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lower_hexadecimal_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:40:32 by yolee             #+#    #+#             */
/*   Updated: 2022/03/22 18:44:32 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*parse_lower_hexadecimal(va_list *ap, t_pflag *print_flags)
{
	int		nbr;
	char	*str;
	size_t	len;

	nbr = va_arg((*ap), int);
	str = ft_uitoa_hex(nbr);
	return (str);
}
					