/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:12:26 by yolee             #+#    #+#             */
/*   Updated: 2022/01/07 05:00:08 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_size;
	size_t	s2_size;
	char	*join_s;

	s1_size = 0;
	s2_size = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 != NULL)
		s1_size = ft_strlen(s1);
	if (s2 != NULL)
		s2_size = ft_strlen(s2);
	join_s = (char *)malloc(s1_size + s2_size + 1);
	if (join_s == NULL)
		return (NULL);
	join_s[0] = '\0';
	if (s1 != NULL)
		ft_strlcat(join_s, s1, s1_size + 1);
	if (s2 != NULL)
		ft_strlcat(join_s, s2, s1_size + s2_size + 1);
	return (join_s);
}
