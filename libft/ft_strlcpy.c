/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 22:45:44 by yolee             #+#    #+#             */
/*   Updated: 2022/01/04 02:16:00 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	srcsize;

	idx = 0;
	srcsize = ft_strlen(src);
	while (idx < dstsize && idx <= srcsize)
	{
		if (idx == dstsize - 1 || idx == srcsize)
			dst[idx] = '\0';
		else
			dst[idx] = src[idx];
		idx++;
	}
	return (srcsize);
}
