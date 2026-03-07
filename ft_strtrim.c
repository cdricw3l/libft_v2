/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 00:06:05 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/07 00:27:00 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	is_on_set(char const *set, char c)
{
	char	*ptr;

	ptr = (char *)set;
	while (*ptr)
	{
		if (*ptr == c)
			return (1);
		ptr++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	bytes_cp;
	char	*new_str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	j = 0;
	while (s1[i] && is_on_set(set, s1[i]))
		i++;
	if (i > ft_strlen(s1))
		return (ft_strdup(""));
	while (s1[i] && !is_on_set(set, s1[i]))
	{
		j++;
		i++;
	}
	new_str = malloc(sizeof(char) * (j + 1));
	if (!new_str)
		return (NULL);
	bytes_cp = ft_strlcpy(new_str, &s1[i], ((j - i) + 1));
	if (bytes_cp != ((j - i) + 1))
	{
		free(new_str);
		return (NULL);
	}
	return (new_str);
}
