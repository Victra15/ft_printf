/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:29:04 by yolee             #+#    #+#             */
/*   Updated: 2022/03/23 19:53:18 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	flag_ignore(t_pflag *print_flags)
{
	print_flags->add_blank = 0;
	print_flags->alter_form = 0;
	print_flags->precision = -1;
	print_flags->sign_display = 0;
}

char	*parse_str(va_list *ap, t_pflag *print_flags)
{
	char	*str;
	char	*param_str;

	flag_ignore(print_flags);
	param_str = va_arg((*ap), char *);
	if (param_str == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(param_str);
	return (str);
}
