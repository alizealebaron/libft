/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:07:15 by alebaron          #+#    #+#             */
/*   Updated: 2025/10/23 13:52:41 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c);
static char	**make_split(char **split, char const *s, char c);
static void	initialisation(int *start, int *word, int *i, int *reset);

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		nbwords;

	nbwords = count_words(s, c);
	split = malloc (sizeof(char *) * (nbwords + 1));
	if (!split)
		return (NULL);
	split = make_split(split, s, c);
	split[nbwords] = NULL;
	return (split);
}

static char	**make_split(char **split, char const *s, char c)
{
	int	start;
	int	word;
	int	i;
	int	reset;

	initialisation(&start, &word, &i, &reset);
	while (s[i])
	{
		if (s[i] != c && !reset)
		{
			start = i;
			reset = 1;
		}
		else if (s[i] == c && reset)
		{
			split[word++] = ft_substr(s, start, i - start);
			reset = 0;
		}
		i++;
	}
	if (reset)
		split[word] = ft_substr(s, start, (i - start));
	return (split);
}

static int	count_words(char const *s, char c)
{
	int	nb_words;
	int	reset;

	reset = 0;
	nb_words = 0;
	while (*s)
	{
		if (*s != c && !reset)
			reset = 1;
		else if (*s == c && reset)
		{
			nb_words++;
			reset = 0;
		}
		s++;
	}
	if (reset)
		nb_words++;
	return (nb_words);
}

static void	initialisation(int *start, int *word, int *i, int *reset)
{
	*start = 0;
	*word = 0;
	*i = 0;
	*reset = 0;
}
