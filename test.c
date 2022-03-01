/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:19:46 by yolee             #+#    #+#             */
/*   Updated: 2022/03/01 18:18:32 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

int	main(void)
{
	int		a;
	int		ft_ret;
	int		ret;

	a = 10;
	printf("[ft_printf] ");
	printf("\n");
	ft_ret = ft_printf("%p", &a);
	printf("\t");
	printf("return : %d", ft_ret);
	printf("\n");
	printf("[printf] ");
	printf("\n");
	ret = printf("%p", &a);
	printf("\t");
	printf("return : %d", ret);
	printf("\n");
	printf("\n");
	return (0);
}
