/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:50:55 by yolee             #+#    #+#             */
/*   Updated: 2022/01/07 04:49:00 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static size_t	ft_split_cnt(char const *s, char c)
{
	const char	*word_start;
	const char	*word_end;
	size_t		split_cnt;

	word_start = s;
	word_end = s;
	split_cnt = 0;
	while (word_end != NULL)
	{
		word_end = ft_strchr(word_start, c);
		if (word_end != NULL && (*word_end) == '\0')
			word_end = NULL;
		if (word_start != word_end && (*word_start) != '\0')
			split_cnt++;
		if (word_end != NULL)
			word_start = word_end + 1;
	}
	return (split_cnt);
}

static int	ft_safe_strdup(char **split_strs, size_t split_cnt, char *word)
{
	size_t	loop;

	split_strs[split_cnt] = ft_strdup(word);
	if (split_strs[split_cnt] == NULL)
	{
		loop = 0;
		while (loop < split_cnt)
			free(split_strs[loop]);
		free(split_strs);
		return (0);
	}
	return (1);
}

static char	**ft_do_split(char *s_cpy, char c, char **split_strs)
{
	char	*word_start;
	char	*word_end;
	size_t	split_cnt;

	word_start = s_cpy;
	word_end = s_cpy;
	split_cnt = 0;
	while (word_end != NULL)
	{
		word_end = ft_strchr(word_start, c);
		if (word_end != NULL && (*word_end) == '\0')
			word_end = NULL;
		if (word_start != word_end && (*word_start) != '\0')
		{
			if (word_end != NULL)
				(*word_end) = '\0';
			if (!ft_safe_strdup(split_strs, split_cnt, word_start))
				return (NULL);
			split_cnt++;
		}
		if (word_end != NULL)
			word_start = word_end + 1;
	}
	split_strs[split_cnt] = 0;
	return (split_strs);
}

char	**ft_split(char const *s, char c)
{
	char	**split_strs;
	char	*s_cpy;
	size_t	split_cnt;

	if (s == NULL)
		return (NULL);
	split_cnt = ft_split_cnt(s, c);
	s_cpy = ft_strdup(s);
	if (s_cpy == NULL)
		return (NULL);
	split_strs = (char **)malloc(sizeof(char *) * (split_cnt + 1));
	if (split_strs == NULL)
		return (NULL);
	split_strs = ft_do_split(s_cpy, c, split_strs);
	if (split_strs == NULL)
		return (NULL);
	free(s_cpy);
	return (split_strs);
}
