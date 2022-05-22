/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:30:14 by yolee             #+#    #+#             */
/*   Updated: 2022/05/22 13:58:39 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "ft_printf_bonus.h"

int	main(void)
{
	int ret;
	int a;

	a = 10;
	write(1, "output [", 8);
	ret = ft_printf("this is a %s", "");
	write(1, "]\n", 2);
	printf("return: %d\n", ret);
	
	printf("output [");
	ret = printf("this is a %s", "");
	printf("]\n");
	printf("return: %d\n", ret);

	return (0);
}
