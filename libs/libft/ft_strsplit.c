/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:05:02 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/05 19:05:02 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_words_count(char const *s, char c)
{
	char			in_word;
	unsigned int	words;

	in_word = 1;
	words = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (in_word)
			{
				in_word = 0;
				words++;
			}
		}
		else
			in_word = 1;
		s++;
	}
	if (in_word)
		words++;
	return (words);
}

static int	ft_allocate_words_memory(char const *s, char c, char **words)
{
	unsigned int i;
	unsigned int word_len;
	unsigned int word_idx;

	i = 0;
	word_idx = 0;
	word_len = 0;
	if (s[i])
	{
		while (i == 0 || s[i - 1] != '\0')
		{
			if ((s[i] == c || s[i] == '\0') && word_len)
			{
				words[word_idx] = ft_strnew(word_len);
				if (!words[word_idx])
					return (0);
				word_len = 0;
				word_idx++;
			}
			else if (s[i] != c && s[i] != '\0')
				word_len++;
			i++;
		}
	}
	return (1);
}

static void	ft_split_words(char const *s, char c, char **words)
{
	unsigned int	i;
	unsigned int	char_idx;
	unsigned int	word_idx;

	i = 0;
	word_idx = 0;
	char_idx = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (char_idx)
			{
				word_idx++;
				char_idx = 0;
			}
		}
		else
			words[word_idx][char_idx++] = *s;
		s++;
	}
}

static char	**ft_free_words_memory(char **words, int words_count)
{
	int i;

	if (words)
	{
		i = 0;
		while (i < words_count)
		{
			if (words[i])
				free(words[i]);
			i++;
		}
		free(words);
	}
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char			**res;
	int				words;

	res = NULL;
	if (s)
	{
		words = ft_get_words_count(s, c);
		if (words)
		{
			res = ft_memalloc((words + 1) * sizeof(char*));
			if (res)
			{
				if (!ft_allocate_words_memory(s, c, res))
					res = ft_free_words_memory(res, words);
				else
					ft_split_words(s, c, res);
			}
		}
	}
	return (res);
}
