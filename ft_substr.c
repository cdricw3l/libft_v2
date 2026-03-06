/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 21:55:13 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/06 23:50:27 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	bytes_cpy;
	size_t	src_len;
	char	*new_str;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	if (start > src_len)
		return (ft_strdup(""));
	new_str = malloc(sizeof(char) * (src_len - start));
	if (!new_str)
		return (NULL);
	bytes_cpy = ft_strlcpy(new_str, &s[start], len);
	if (bytes_cpy != ft_strlen(s) - start)
	{
		free(new_str);
		return (NULL);
	}
	return (new_str);
}
