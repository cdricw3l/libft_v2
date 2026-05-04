/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:07:54 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/04 12:48:04 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_strjoin_test(int test_nb, char *s1, char *s2, char *expected)
{

    char *str;

    printf("Test %d: ", test_nb);
    str = ft_strjoin(s1, s2);
    if (!expected)
    {
        printf("exepected: %p output: %p -> " C_GREEN"Ok!"C_RESET"\n", expected, str);
        assert(str == expected);
        assert(malloc_usable_size(str) == 0);
    }
    else if (expected && str)
    {
        printf("exepected: %s output: %s -> " C_GREEN"Ok! "C_RESET"memory check -> "C_GREEN"Ok!"C_RESET"\n", expected, str);    
        assert(!strcmp(str, expected));
        assert(malloc_usable_size(str) == malloc_usable_size(expected));
        free(str);
        free(expected);
    }
}

void ft_strjoin_assert(void)
{
    char *test_name = "ft_strjoin";
    int test_nb;
    TEST_STAR(test_name);
    test_nb = 1;
    
    ft_strjoin_test(test_nb++,"Hello", "Berlin", strdup("HelloBerlin"));
    ft_strjoin_test(test_nb++,"Hello", "", strdup("Hello"));
    ft_strjoin_test(test_nb++,"", "Hello", strdup("Hello"));
    ft_strjoin_test(test_nb++,"", "", strdup(""));
    ft_strjoin_test(test_nb++, NULL, "helloBerlin", strdup("helloBerlin"));
    ft_strjoin_test(test_nb++, "helloBerlin", NULL, strdup("helloBerlin"));
    ft_strjoin_test(test_nb++, "         424242    ", "     424242", strdup("         424242         424242"));
    ft_strjoin_test(test_nb++, NULL, NULL, strdup(""));

    TEST_OK(test_name);
    SEP;
    NL;
}