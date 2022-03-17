/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_control_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:03:43 by yolee             #+#    #+#             */
/*   Updated: 2022/03/15 17:41:01 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

static int	ft_isoverflowed(long long *conv_num, const int sign)
{
	if (((*conv_num) * sign) < 0)
	{
		if (sign < 0)
			(*conv_num) = 0;
		else
			(*conv_num) = -1;
		return (1);
	}
	else
		return (0);
}

int	ft_dtoi_iter(const char **str)
{
	long long	conv_num;
	int			sign;

	sign = 1;
	conv_num = 0;
	while (ft_isdigit(**str))
	{
		conv_num = (conv_num * 10) + ((sign) * ((**str) - '0'));
		if (ft_isoverflowed(&conv_num, sign))
			break ;
		(*str)++;
	}
	return ((int)(conv_num));
}

long long	ft_dtol_iter(const char **str)
{
	long long	conv_num;
	int			sign;

	sign = 1;
	conv_num = 0;
	while (ft_isdigit(**str))
	{
		conv_num = (conv_num * 10) + ((sign) * ((**str) - '0'));
		if (ft_isoverflowed(&conv_num, sign))
			break ;
		(*str)++;
	}
	return (conv_num);
}
