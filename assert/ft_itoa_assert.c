/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_assert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 15:30:23 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/03 16:30:29 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

static void ft_itoa_test(int nb, char *expected, int test_nb)
{
    char *ft;

    ft = ft_itoa(nb);
    printf("Test %d input: " C_PBG "%d"C_RESET, test_nb,nb);
    printf(" output -> "C_GBG"%s"C_RESET,ft);
    assert(!strcmp(expected,ft));
    printf(C_GREEN" OK! "C_RESET);
    assert(malloc_usable_size(ft) == ft_strlen(expected) + 1);
    printf("Memory check: -> " C_GREEN "OK!\n"C_RESET);
    free(ft);
}

void ft_itoa_assert(void)
{
    TEST_STAR("ft_itoa");
    int test_nb;

    test_nb = 0;
    ft_itoa_test(0,"0", test_nb++);
    ft_itoa_test(INT_MIN,"-2147483648", test_nb++);
    ft_itoa_test(INT_MAX,"2147483647", test_nb++);
    ft_itoa_test(42,"42", test_nb++);
    ft_itoa_test(-1,"-1", test_nb++);
    ft_itoa_test(001,"1", test_nb++);
    ft_itoa_test(002,"2", test_nb++);
    //https://www.geeksforgeeks.org/c/octal-literals-in-c/ -> "When we initialize a value by putting '0' before a number, the number is treated as octal"
    ft_itoa_test(012,"10", test_nb++);
    ft_itoa_test(0166,"118", test_nb++);
    ft_itoa_test(0xA,"10", test_nb++);
    TEST_OK("ft_itoa");
    SEP;
    NL;
}