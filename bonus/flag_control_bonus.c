/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_control_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:03:43 by yolee             #+#    #+#             */
/*   Updated: 2022/03/23 19:47:23 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	is_invalid_flag(t_pflag print_flags)
{
	int	max_precision;

	max_precision = 2147483647 - 1;
	if (print_flags.width == -1)
		return (1);
	if ((print_flags.add_blank == 1 || print_flags.sign_display == 1))
		max_precision -= 1;
	if (print_flags.alter_form == 1)
		max_precision -= 2;
	if (print_flags.precision >= max_precision)
		return (1);
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
		(*str)++;
	}
	if (conv_num > 2147483645)
		conv_num = 2147483646;
	return ((int)(conv_num));
}
