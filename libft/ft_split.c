/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:38:27 by yegkim            #+#    #+#             */
/*   Updated: 2023/10/18 16:38:20 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words_cnt(char const *str, char c)
{
	size_t	i;
	size_t	cnt;

	if (*str == 0)
		return (0);
	i = 0;
	cnt = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			cnt++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (cnt);
}

static size_t	get_word(char **arr, size_t *arr_i, char const *str, char c)
{
	char	*word;
	size_t	i;
	size_t	word_len;

	word_len = 0;
	while (str[word_len] && str[word_len] != c)
		word_len++;
	if (word_len == 0)
		return (0);
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (word == 0)
		return (0);
	i = 0;
	while (i < word_len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	arr[*arr_i] = word;
	(*arr_i)++;
	return (word_len);
}

static void	free_malloc(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		arr[i] = 0;
		i++;
	}
	free(arr);
	arr = 0;
}

static int	set_arr(char const *s, char c, char **arr, size_t arr_len)
{
	size_t	i;
	size_t	arr_i;
	size_t	word_len;

	i = 0;
	arr_i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		word_len = get_word(arr, &arr_i, s + i, c);
		if (word_len == 0)
			break ;
		i += word_len;
	}
	if (arr_i < arr_len)
	{
		free_malloc(arr, arr_i);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	arr_len;

	if (!s)
		return (0);
	arr_len = words_cnt(s, c);
	arr = (char **)ft_calloc(arr_len + 1, sizeof(char *));
	if (!arr)
		return (0);
	if (!set_arr(s, c, arr, arr_len))
		return (0);
	return (arr);
}
