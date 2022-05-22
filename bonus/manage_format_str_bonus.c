/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_format_str_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:08:06 by yolee             #+#    #+#             */
/*   Updated: 2022/05/16 20:00:02 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	format_to_print_iter(char **print_str,
		char **format_str,
		size_t len,
		size_t *f_str_len)
{
	ft_memmove((*print_str), (*format_str), len);
	(*print_str) += len;
	(*format_str) += len;
	(*f_str_len) -= len;
}

void	fill_padding(char **print_str, char fill_chr, size_t len)
{
	ft_memset((*print_str), fill_chr, len);
	(*print_str) += len;
}

static char	*parsing(va_list *ap,
			const char **iter,
			t_pflag *print_flags)
{
	char	format_char;

	format_char = (**iter);
	if (format_char == 'c')
		return (parse_char(ap, print_flags));
	else if (format_char == 's')
		return (parse_str(ap, print_flags));
	else if (format_char == 'p')
		return (parse_ptr(ap, print_flags));
	else if (format_char == 'd')
		return (parse_decimal(ap, print_flags));
	else if (format_char == 'i')
		return (parse_decimal(ap, print_flags));
	else if (format_char == 'u')
		return (parse_unsigned_decimal(ap, print_flags));
	else if (format_char == 'x')
		return (parse_lower_hexadecimal(ap, print_flags));
	else if (format_char == 'X')
		return (parse_upper_hexadecimal(ap, print_flags));
	else
		return (parse_etc(format_char, print_flags));
}

static void	read_flags(const char **iter, t_pflag *print_flags)
{
	while (1)
	{
		if ((**iter) == '#')
			print_flags->alter_form = 1;
		else if ((**iter) == ' ')
			print_flags->add_blank = 1;
		else if ((**iter) == '+')
			print_flags->sign_display = 1;
		else if ((**iter) == '-')
			print_flags->left_adjust = 1;
		else if ((**iter) == '0')
			print_flags->zero_pad = 1;
		else if (ft_isdigit_except_0(**iter))
			print_flags->width = ft_atoi_width_iter(iter);
		else if ((**iter) == '.')
		{
			print_flags->zero_pad = 0;
			print_flags->precision = ft_atoui_precision_iter(iter);
		}
		else
			break ;
		(*iter)++;
	}
}

int	read_format_str(va_list *ap,
			const char **iter,
			t_pflag *print_flags,
			char **format_str)
{
	read_flags(iter, print_flags);
	(*format_str) = parsing(ap, iter, print_flags);
	if ((*format_str) == NULL)
	{
		print_flags->error_flag = 1;
		return (print_flags->error_flag);
	}
	if (!print_flags->error_flag)
	{
		if (is_invalid_flag(print_flags))
		{
			free(*format_str);
			(*format_str) = NULL;
			return (print_flags->error_flag);
		}
	}
	return (0);
}
