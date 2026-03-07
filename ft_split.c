/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 20:47:15 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/07 22:06:33 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	index_of(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	counter;

	if (!s)
		return (0);
	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (counter);
}

static void	*clean_split(char **split)
{
	char	**ptr;

	ptr = split;
	while (*ptr)
	{
		if (*ptr)
		{
			free(*ptr);
			*ptr = NULL;
		}
		ptr++;
	}
	free(split);
	split = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	size;
	char	**split;
	char	*ptr;

	size = count_word(s, c);
	split = malloc(sizeof(char *) * (size + 1));
	if (!split)
		return (NULL);
	i = 0;
	ptr = (char *)s;
	while (i < size)
	{
		while (*ptr && *ptr == c)
			ptr++;
		split[i] = ft_substr(&(*ptr), 0, index_of(&(*ptr), c) + 1);
		if (!split[i])
			return (clean_split(split));
		ptr += ft_strlen(split[i++]);
	}
	split[i] = NULL;
	return (split);
}

int main(void)
{
	char *str = "*****hello***world****comment ca va ***";
	assert(count_word(str, '*') == 3);
	char **split = ft_split(str, '*');
	char **ptr = split;

	if (split)
	{
		while (*ptr)
		{
			printf("%s\n", *ptr);
			ptr++;
		}
		clean_split(split);
	}
	char *str2 = "";

	split = ft_split(str2, '*');
	assert(split && *split);
	if (split)
	{
		ptr = split;
		while (*ptr)
		{
			printf("%s\n", *ptr);
			ptr++;
		}
		clean_split(split);
	}
}