/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:21:19 by yolee             #+#    #+#             */
/*   Updated: 2022/03/15 17:36:51 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	parse_with_flag(va_list *ap,
			const char **iter,
			size_t *print_len,
			t_pflag print_flags)
{
	char	format_char;

	format_char = (**iter);
	if (format_char == 'c')
		parse_char(ap, print_len, print_flags);
	else if (format_char == 's')
		parse_str(ap, print_len, print_flags);
	else if (format_char == 'p')
		parse_ptr(ap, print_len, print_flags);
	else if (format_char == 'd')
		parse_decimal(ap, print_len, print_flags);
	else if (format_char == 'i')
		parse_decimal(ap, print_len, print_flags);
	else if (format_char == 'u')
		parse_unsigned_decimal(ap, print_len, print_flags);
	else if (format_char == 'x')
		parse_lower_hexadecimal(ap, print_len, print_flags);
	else if (format_char == 'X')
		parse_upper_hexadecimal(ap, print_len, print_flags);
	else if (format_char == '%')
		parse_percent(print_len, print_flags);
	else
		parse_none(print_len, print_flags);
	(*iter)++;
}

static void	read_flags(const char **iter, t_pflag *print_flags)
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
		print_flags->width = ft_dtoi_iter(iter);
	else if ((**iter) == '.')
	{
		(*iter)++;
		print_flags->precision = ft_dtoi_iter(iter);
	}
}

static void	print_format_str(va_list *ap, const char **iter, size_t *print_len)
{
	t_pflag	print_flags;

	init_flags(&print_flags);
	while (1)
	{
		if ((**iter) == '#'
			|| (**iter) == ' '
			|| (**iter) == '+'
			|| (**iter) == '-'
			|| (**iter) == '.'
			|| ft_isdigit(**iter))
			read_flags(iter, &print_flags);
		else
		{
			parse_with_flag(ap, iter, print_len, print_flags);
			break ;
		}
	}
}

static void	print_parsed_str(va_list *ap, const char *str, size_t *print_len)
{
	const char	*iter;
	const char	*temp_iter;

	iter = str;
	while (1)
	{
		temp_iter = iter;
		iter = ft_strchr(temp_iter, '%');
		if (!iter)
		{
			iter = ft_strchr(temp_iter, '\0');
			(*print_len) += iter - temp_iter;
			if (iter - temp_iter)
				write(1, temp_iter, iter - temp_iter);
			break ;
		}
		(*print_len) += iter - temp_iter;
		if (iter - temp_iter)
			write(1, temp_iter, iter - temp_iter);
		iter++;
		print_format_str(ap, &iter, print_len);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	print_len;

	print_len = 0;
	va_start(ap, str);
	print_parsed_str(&ap, str, &print_len);
	va_end(ap);
	return (print_len);
}
