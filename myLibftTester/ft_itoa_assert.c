/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_assert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 15:30:23 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/04 10:00:45 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

static void ft_itoa_test(int nb, char *expected, int test_nb)
{
    char *ft;
    char *s;
    size_t (*f)(void *ptr);

    #ifdef __APPLE__
        f = malloc_size;
    #else
        f = malloc_usable_size;
    #endif
    s = strdup(expected);
    assert(s);
    ft = ft_itoa(nb);
    printf("Test %d input: " C_PBG "%d"C_RESET, test_nb,nb);
    printf(" output -> "C_GBG"%s"C_RESET,ft);
    assert(!strcmp(s,ft));
    printf(C_GREEN" OK! "C_RESET);
    assert(f(ft) == f(s));
    printf("Memory check: -> " C_GREEN "OK!\n"C_RESET);
    free(ft);
    free(s);
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