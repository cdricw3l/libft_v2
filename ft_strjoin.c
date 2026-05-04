/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 23:40:05 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/04 12:49:41 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	bytes_cp;
	char	*new_str;

	/*
		The assignement said return NULL if the allocation fail. 
		So if *s1 and *s2 == NULL i return ""

	*/
	if (!s1 && !s2)
		return (strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	bytes_cp = ft_strlcpy(new_str, s1, len + 1);
	bytes_cp += ft_strlcpy(&new_str[ft_strlen(s1)], s2, len + 1);
	if (bytes_cp != len)
	{
		free (new_str);
		return (NULL);
	}
	return (new_str);
}
