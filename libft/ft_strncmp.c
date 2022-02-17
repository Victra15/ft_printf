/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:09:46 by yolee             #+#    #+#             */
/*   Updated: 2022/01/06 22:15:31 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*conv_s1;
	const unsigned char	*conv_s2;
	size_t				loop;

	if (n == 0)
		return (0);
	loop = 0;
	conv_s1 = (const unsigned char *)s1;
	conv_s2 = (const unsigned char *)s2;
	while (conv_s1[loop] == conv_s2[loop]
		&& (conv_s1[loop] != '\0' && conv_s2[loop] != '\0')
		&& loop < n - 1)
	{
		loop++;
	}
	if (conv_s1[loop] > conv_s2[loop])
		return (1);
	else if (conv_s1[loop] == conv_s2[loop])
		return (0);
	else
		return (-1);
}
