/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:39:34 by yolee             #+#    #+#             */
/*   Updated: 2021/12/23 17:10:54 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	conv_c;
	unsigned char	*conv_b;

	conv_c = (unsigned char) c;
	conv_b = (unsigned char *) b;
	while (len--)
		*(conv_b++) = conv_c;
	return (b);
}
