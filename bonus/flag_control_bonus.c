/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_control_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:03:43 by yolee             #+#    #+#             */
/*   Updated: 2022/03/20 15:43:27 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	is_invalid_flag(const char parse_char, t_pflag print_flags, int *print_len)
{
	if (print_flags.alter_form == 1 && (parse_char == 'x' || parse_char == 'X'))
		print_flags.precision += 2;
	if (print_flags.width == -1)
	{
		print_len = -1;
		return (1);
	}
	else if ((print_flags.precision >= 2147483647 - 1)
		&& (parse_char == 'd'
			|| parse_char == 'i'
			|| parse_char == 'u'
			|| parse_char == 'x'
			|| parse_char == 'X'
			|| parse_char == 'p'
		))
	{
		print_len = -1;
		return (1);
	}
	else
		return (0);
}

int	ft_isdigit_except_0(int c)
{
	if (('1' <= c && '9' >= c))
		return (1);
	else
		return (0);
}

void	init_flags(t_pflag *print_flags)
{
	print_flags->alter_form = 0;
	print_flags->zero_pad = 0;
	print_flags->left_adjust = 0;
	print_flags->add_blank = 0;
	print_flags->sign_display = 0;
	print_flags->width = 0;
	print_flags->precision = 0;
}

unsigned int	ft_atoui_precision_iter(const char **str)
{
	unsigned int	conv_num;

	(*str)++;
	conv_num = 0;
	while (ft_isdigit(**str))
	{
		conv_num = (conv_num * 10) + ((**str) - '0');
		(*str)++;
	}
	return (conv_num);
}

int	ft_atoi_width_iter(const char **str)
{
	long long	conv_num;

	conv_num = 0;
	while (ft_isdigit(**str))
	{
		conv_num = (conv_num * 10) + ((**str) - '0');
		if (conv_num > 2147483645)
		{
			conv_num = -1;
			break ;
		}
		(*str)++;
	}
	return ((int)(conv_num));
}
