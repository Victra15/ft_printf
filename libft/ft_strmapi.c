/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:09:26 by yolee             #+#    #+#             */
/*   Updated: 2022/01/07 04:48:36 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			s_len;
	unsigned int	loop;
	char			*s_map;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	s_map = (char *)malloc(s_len + 1);
	if (s_map == NULL)
		return (NULL);
	loop = 0;
	while (loop < s_len)
	{
		s_map[loop] = f(loop, s[loop]);
		loop++;
	}
	s_map[loop] = '\0';
	return (s_map);
}
