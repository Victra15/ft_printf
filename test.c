/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:19:46 by yolee             #+#    #+#             */
/*   Updated: 2022/03/25 03:31:57 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "ft_printf_bonus.h"

int	main(void)
{
	int		ft_ret;
	int		ret;
	int		a;
	int		b;
	
	a = 10;
	b = 10;
	printf("[ft_printf] ");
	printf("\n");
	ft_ret = ft_printf(" %#x ", LONG_MIN);
	printf("\n");
	printf("return : %d", ft_ret);
	printf("\n");
	printf("[printf] ");
	printf("\n");
	ret = printf(" %#x ", LONG_MIN);
	printf("\n");
	printf("return : %d", ret);
	printf("\n");
	printf("\n");
	return (0);
}
