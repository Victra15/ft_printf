/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:29:04 by yolee             #+#    #+#             */
/*   Updated: 2022/03/25 03:27:31 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	flag_ignore(t_pflag *print_flags)
{
	print_flags->add_blank = 0;
	print_flags->alter_form = 0;
	print_flags->sign_display = 0;
}

char	*parse_str(va_list *ap, t_pflag *print_flags)
{
	size_t	str_len;
	char	*str;
	char	*param_str;

	flag_ignore(print_flags);
	param_str = va_arg((*ap), char *);
	if (param_str == NULL)
	{
		str_len = 6;
		if (print_flags->precision < str_len)
			str_len = print_flags->precision;
		str = ft_substr("(null)", 0, str_len);
	}
	else
	{
		str_len = ft_strlen(param_str);
		if (print_flags->precision < str_len)
			str_len = print_flags->precision;
		str = ft_substr(param_str, 0, str_len);
	}
	return (str);
}
