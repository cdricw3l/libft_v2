/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:24:20 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/05 19:08:22 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_putchar_assert(void)
{
    char b[1];
    char c;

    c = 'A';
    ft_putchar_fd(c, STDOUT_FILENO);
    dup2(STDOUT_FILENO, STDIN_FILENO);
    read(STDIN_FILENO, b, 1);
    assert(c == b[0]);
}