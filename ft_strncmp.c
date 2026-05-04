/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:02:35 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/04 18:35:46 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		/*
			Why unsigned char ? because the original cast as unsigned char.

			if s1[i] = -10 and s2[i] = 10 strnmcmp return 246 - 10 -> 236

			-10: 1111111111110110
			246: 0000000011110110
		
		*/
		/*
			2nd point: 
			when the fonction strncmp compare read only string, she return -1 or 1 else she return the difference between s1[i] and s2[i]

		*/
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
