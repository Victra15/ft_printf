/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:26:05 by yolee             #+#    #+#             */
/*   Updated: 2022/03/20 16:26:55 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	parse_str(va_list *ap, size_t *print_len, t_pflag print_flags)
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