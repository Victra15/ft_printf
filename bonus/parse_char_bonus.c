/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:22:23 by yolee             #+#    #+#             */
/*   Updated: 2022/03/25 04:19:49 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	null_chr_add(char *format_str, size_t *f_str_len, char parse_char)
{
	if (parse_char == 'c' && format_str[0] == '\0')
		(*f_str_len)++;
}

static void	flag_ignore(t_pflag *print_flags)
{
	print_flags->add_blank = 0;
	print_flags->alter_form = 0;
	print_flags->precision = -1;
	print_flags->sign_display = 0;
}

char	*parse_char(va_list *ap, t_pflag *print_flags)
{
	char	ch;
	char	*str;

	flag_ignore(print_flags);
	ch = va_arg((*ap), int);
	str = (char *)malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);
	str[1] = '\0';
	str[0] = ch;
	return (str);
}
