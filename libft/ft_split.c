/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dashvydk <dashvydk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-13 13:23:33 by dashvydk          #+#    #+#             */
/*   Updated: 2025-03-13 13:23:33 by dashvydk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*allocate_word(char const *s, int len)
{
	char	*word;

	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

static void	free_splits(char **splits, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(splits[i]);
		i++;
	}
	free(splits);
}

static char const	*get_next_word(char const *s, char c, int *len)
{
	*len = 0;
	while (*s && *s == c)
		s++;
	while (s[*len] && s[*len] != c)
		(*len)++;
	if (*len > 0)
		return (s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		split_index;
	int		len;
	char	**splits;

	split_index = 0;
	splits = malloc(sizeof(char *) * (count_words(s, c) + 1));
	s = get_next_word(s, c, &len);
	if (!splits)
		return (NULL);
	while (s != NULL)
	{
		splits[split_index] = allocate_word(s, len);
		if (!splits[split_index])
		{
			free_splits(splits, split_index);
			return (NULL);
		}
		split_index++;
		s += len;
		s = get_next_word(s, c, &len);
	}
	splits[split_index] = NULL;
	return (splits);
}
