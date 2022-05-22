/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:21:19 by yolee             #+#    #+#             */
/*   Updated: 2022/05/22 14:25:46 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	cat_padding(char *p_str,
		char *format_str,
		t_pflag *p_flags,
		size_t f_str_len)
{
	size_t	iter_len;

	iter_len = f_str_len;
	if (p_flags->left_adjust == 1)
	{
		format_to_print_iter(&p_str, &format_str, iter_len, &iter_len);
		if ((int)(p_flags->width - f_str_len) > 0)
			fill_padding(&p_str, ' ', (int)(p_flags->width - f_str_len));
	}
	else
	{
		if (p_flags->zero_pad == 1)
		{
			if (p_flags->add_blank == 1 || p_flags->sign_display == 1)
				format_to_print_iter(&p_str, &format_str, 1, &iter_len);
			if (p_flags->alter_form == 1)
				format_to_print_iter(&p_str, &format_str, 2, &iter_len);
			if ((int)(p_flags->width - f_str_len) > 0)
				fill_padding(&p_str, '0', (int)(p_flags->width - f_str_len));
		}
		else
			if ((int)(p_flags->width - f_str_len) > 0)
				fill_padding(&p_str, ' ', (int)(p_flags->width - f_str_len));
		format_to_print_iter(&p_str, &format_str, iter_len, &iter_len);
	}
}

static int	print_format_str(char **format_str,
		t_pflag *print_flags,
		int *print_len,
		char parse_char)
{
	size_t	f_str_len;
	size_t	p_str_len;
	char	*print_str;

	f_str_len = ft_strlen(*format_str);
	null_chr_add((*format_str), &f_str_len, parse_char);
	p_str_len = f_str_len;
	if ((int)(print_flags->width - f_str_len) > 0)
		p_str_len += (int)(print_flags->width - f_str_len);
	print_str = (char *)malloc(sizeof(char) * p_str_len + 1);
	if (print_str == NULL)
	{
		print_flags->error_flag = 1;
		return (print_flags->error_flag);
	}
	cat_padding(print_str, (*format_str), print_flags, f_str_len);
	write(1, print_str, p_str_len);
	if (print_flags->width > 0)
		(*print_len) += p_str_len;
	else
		(*print_len) += f_str_len;
	free(*format_str);
	free(print_str);
	(*format_str) = NULL;
	return (0);
}

static void	print_substr(const char *start, const char *end, int *print_len)
{
	(*print_len) += end - start;
	if (end - start)
		write(1, start, end - start);
}

static int	print_parsed_str(va_list *ap, const char *str, int *print_len)
{
	const char	*temp_iter_1;
	const char	*temp_iter_2;
	char		*format_str;
	t_pflag		print_flags;

	print_flags.error_flag = 0;
	while (1)
	{
		init_flags(&print_flags);
		temp_iter_1 = str;
		temp_iter_2 = ft_strchr(temp_iter_1, '%');
		if (!temp_iter_2)
		{
			temp_iter_2 = ft_strchr(temp_iter_1, '\0');
			print_substr(temp_iter_1, temp_iter_2, print_len);
			return (print_flags.error_flag);
		}
		str = temp_iter_2 + 1;
		if (read_format_str(ap, &str, &print_flags, &format_str))
			return (print_flags.error_flag);
		print_substr(temp_iter_1, temp_iter_2, print_len);
		if (print_format_str(&format_str, &print_flags, print_len, *str))
			return (print_flags.error_flag);
		str++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		print_len;

	print_len = 0;
	va_start(ap, str);
	if (print_parsed_str(&ap, str, &print_len))
		print_len = -1;
	va_end(ap);
	return (print_len);
}
