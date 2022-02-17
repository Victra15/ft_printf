/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:40:59 by yolee             #+#    #+#             */
/*   Updated: 2021/12/16 16:38:28 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char chr)
{
	if ((chr >= '\t' && chr <= '\r')
		|| chr == ' ')
		return (1);
	else
		return (0);
}

static int	ft_issign(const char chr)
{
	if (chr == '+' || chr == '-')
		return (1);
	else
		return (0);
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

int	ft_atoi(const char *str)
{
	long long	conv_num;
	int			sign;
	const char	*iter_ptr;

	sign = 1;
	conv_num = 0;
	iter_ptr = str;
	while (ft_isspace(*iter_ptr))
		iter_ptr++;
	if (ft_issign(*iter_ptr))
	{
		if ((*iter_ptr) == '-')
			sign = -1;
		iter_ptr++;
	}
	while (ft_isdigit(*iter_ptr))
	{
		conv_num = (conv_num * 10) + ((sign) * ((*iter_ptr) - '0'));
		if (ft_isoverflowed(&conv_num, sign))
			break ;
		iter_ptr++;
	}
	return ((int)(conv_num));
}
