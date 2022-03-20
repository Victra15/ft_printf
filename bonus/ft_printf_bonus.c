/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:21:19 by yolee             #+#    #+#             */
/*   Updated: 2022/03/19 00:27:33 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	print_format_str(va_list *ap,
			const char **iter,
			int *print_len,
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
	else
		parse_etc((*iter), print_len, print_flags);
	(*iter)++;
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
			print_flags->precision = ft_atoui_precision_iter(iter);
		else
			break ;
		(*iter)++;
	}
	return (print_flags);
}

static void	print_substr(const char *start, const char *end, int *print_len)
{
	(*print_len) += end - start;
	if (end - start)
		write(1, start, end - start);
}

static void	print_parsed_str(va_list *ap, const char *str, int *print_len)
{
	const char	*iter;
	const char	*temp_iter_1;
	const char	*temp_iter_2;
	t_pflag		print_flags;

	init_flags(&print_flags);
	iter = str;
	while (1)
	{
		temp_iter_1 = iter;
		temp_iter_2 = ft_strchr(temp_iter_1, '%');
		if (!temp_iter_2)
		{
			temp_iter_2 = ft_strchr(temp_iter_1, '\0');
			print_substr(temp_iter_1, temp_iter_2, print_len);
			break ;
		}
		iter = temp_iter_2 + 1;
		read_flags(&iter, &print_flags);
		if (is_invalid_flag(*iter, print_flags, print_len))
			return ;
		print_substr(temp_iter_1, temp_iter_2, print_len);
		print_format_str(ap, &iter, print_len, print_flags);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		print_len;

	print_len = 0;
	va_start(ap, str);
	print_parsed_str(&ap, str, &print_len);
	va_end(ap);
	return (print_len);
}
