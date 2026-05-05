/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 22:23:51 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/05 11:37:58 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;
	size_t		len;

	ptr = s;
	len = ft_strlen(s);
	if (ptr[len] == (unsigned char)c)
		return (&((char *)ptr)[len]);
	while (len > 0)
	{
		if ((unsigned char)ptr[len - 1] == (unsigned char)c)
			return (&((char *)ptr)[len - 1]);
		len--;
	}
	return (NULL);
}
