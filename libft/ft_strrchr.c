/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:40:19 by yolee             #+#    #+#             */
/*   Updated: 2022/01/03 20:26:32 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	idx;
	size_t	len;
	char	conv_c;

	len = ft_strlen(s);
	s += len;
	idx = 0;
	conv_c = (char)c;
	while (idx <= len)
	{
		if (*s == conv_c)
			return ((char *)(s));
		s--;
		idx++;
	}
	return (NULL);
}
