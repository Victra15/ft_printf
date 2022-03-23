/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_etc_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:33:17 by yolee             #+#    #+#             */
/*   Updated: 2022/03/23 19:53:12 by yolee            ###   ########.fr       */
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

char	*parse_etc(char format_char, t_pflag *print_flags)
{
	char	*str;

	flag_ignore(print_flags);
	print_flags->precision = -1;
	str = (char *)malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);
	str[1] = '\0';
	str[0] = format_char;
	return (str);
}
