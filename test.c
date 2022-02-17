/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:19:46 by yolee             #+#    #+#             */
/*   Updated: 2022/02/09 17:10:54 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int	main(void)
{
	printf("empty str test");
	printf("(ft_printf) return : %d		output :", ft_printf(""));
	printf("\n");
	printf("(printf) return : %d		output :", printf(""));
	printf("\n");

	printf("%%c test");
	printf("empty str test");
	printf("(ft_printf) return : %d		output :", ft_printf("%c", 'a'));
	printf("\n");
	printf("(printf) return : %d		output :", printf("%c", 'a'));
	printf("\n");

	printf("%%s test");
	printf("empty str test");
	printf("(ft_printf) return : %d		output :", ft_printf("%s", "abc"));
	printf("\n");
	printf("(printf) return : %d		output :", printf("%s", "abc"));
	printf("\n");

	printf("%%p test");
	void	*ptr;

	ptr = malloc(1);
	printf("empty str test");
	printf("(ft_printf) return : %d		output :", ft_printf("%p", ptr));
	printf("\n");
	printf("(printf) return : %d		output :", printf("%p", ptr));
	printf("\n");
	free(ptr);

	printf("%%c test");
	printf("empty str test");
	printf("(ft_printf) return : %d		output :", ft_printf("%c", 'a'));
	printf("\n");
	printf("(printf) return : %d		output :", printf("%c", 'a'));
	printf("\n");

	printf("%%c test");
	printf("empty str test");
	printf("(ft_printf) return : %d		output :", ft_printf("%c", 'a'));
	printf("\n");
	printf("(printf) return : %d		output :", printf("%c", 'a'));
	printf("\n");

	printf("%%c test");
	printf("empty str test");
	printf("(ft_printf) return : %d		output :", ft_printf("%c", 'a'));
	printf("\n");
	printf("(printf) return : %d		output :", printf("%c", 'a'));
	printf("\n");

	printf("%%c test");
	printf("empty str test");
	printf("(ft_printf) return : %d		output :", ft_printf("%c", 'a'));
	printf("\n");
	printf("(printf) return : %d		output :", printf("%c", 'a'));
	printf("\n");

	printf("%%c test");
	printf("empty str test");
	printf("(ft_printf) return : %d		output :", ft_printf("%c", 'a'));
	printf("\n");
	printf("(printf) return : %d		output :", printf("%c", 'a'));
	printf("\n");

	return (0);
}
