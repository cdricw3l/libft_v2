/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_assert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:06:56 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/04 13:21:59 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_strlen_test(int test_nb, char *s)
{
    size_t len1;
    size_t len2;
    
    printf("Test %d:", test_nb);
    len1 = strlen(s);
    len2 = ft_strlen(s);
    printf(" expected measure: %ld measure: %ld -> "C_GREEN"Ok!"C_RESET "\n", len1, len2);
    assert(len1 == len2);
}

void ft_strlen_assert(void)
{
    char *test_name = "ft_strlen";
    int test_nb;
    TEST_STAR(test_name);
    
    test_nb = 1;
    ft_strlen_test(test_nb++, "hello_berlin");
    ft_strlen_test(test_nb++, "");
    ft_strlen_test(test_nb++, "             4242");
    ft_strlen_test(test_nb++, "4242             ");
    char str[] = {-10,-10,-10,-10,-10,-10, '\0'};
    ft_strlen_test(test_nb++, str);

    TEST_OK(test_name);
    SEP;
    NL;
}