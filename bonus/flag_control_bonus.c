/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_control_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:03:43 by yolee             #+#    #+#             */
/*   Updated: 2022/05/22 12:21:20 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	is_invalid_flag(t_pflag *print_flags)
{
	int	max_precision;

	max_precision = MAX_INT - 1;
	if (print_flags->width >= MAX_INT - 1)
	{
		print_flags->error_flag = 1;
		if (print_flags->width < MAX_LONG_LONG)
			return (print_flags->error_flag);
	}
	if ((print_flags->add_blank == 1 || print_flags->sign_display == 1))
		max_precision -= 1;
	if (print_flags->alter_form == 1)
		max_precision -= 2;
	if ((int)(print_flags->precision) >= max_precision)
	{
		print_flags->error_flag = 1;
		return (print_flags->error_flag);
	}
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
	print_flags->precision = -1;
}

unsigned long long	ft_atoui_precision_iter(const char **str)
{
	unsigned long long	conv_num;

	(*str)++;
	conv_num = 0;
	while (ft_isdigit(**str))
	{
		conv_num = (conv_num * 10) + ((**str) - '0');
		(*str)++;
	}
	(*str)--;
	return (conv_num);
}

long long	ft_atoi_width_iter(const char **str)
{
	long long	conv_num;

	conv_num = 0;
	while (ft_isdigit(**str))
	{
		conv_num = (conv_num * 10) + ((**str) - '0');
		(*str)++;
	}
	(*str)--;
	return (conv_num);
}
