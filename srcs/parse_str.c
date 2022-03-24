/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:29:04 by yolee             #+#    #+#             */
/*   Updated: 2022/03/24 15:31:43 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_str(va_list *ap, int *print_len)
{
	char	*str;
	size_t	len;

	str = va_arg((*ap), char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		(*print_len) += 6;
	}
	else
	{
		len = ft_strlen(str);
		write(1, str, len);
		(*print_len) += len;
	}
}
