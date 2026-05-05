/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri_assert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 11:20:23 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/05 06:32:04 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void iter1(unsigned int i, char *s)
{
    if (i % 2 == 0)
    {
        if (*s >= 65 && *s <= 90)
            *s = ft_tolower(*s);
        else if (*s >= 97 && *s <= 122)
            *s = ft_toupper(*s); 
    }
}

void iter2(unsigned int i, char *s)
{
    if (i == 0)
        *s = '\0';
}

static void ft_striteri_test(int test_nb, char *str, char *expected, void (*f)(unsigned int, char *))
{
    char *s;
    printf("Test %d: ", test_nb);
    if(str)
    {
        s = ft_strdup(str);
        assert(s);
    }
    else
        s = NULL;
    ft_striteri(s, f);
    if(expected)
        assert(!strcmp(s, expected));
    else
        assert(s == expected);
    printf("expected: %s output: %s -> "C_GREEN"Ok!"C_RESET"\n", expected, s);
    free(s);
}

void ft_striteri_assert(void)
{
    TEST_STAR("ft_striteri");
    int test_nb;

    test_nb = 1;
    //Test 1
    ft_striteri_test(test_nb++, "", "", iter1);
    //Test 2
    ft_striteri_test(test_nb++, "hello_berlin", "HeLlO_BeRlIn", iter1);
    //Test 3
    ft_striteri_test(test_nb++, "hello_berlin", "hello_berlin", NULL);
    //Test 4
    ft_striteri_test(test_nb++, "hello_berlin", "", iter2);
    //Test 5
    ft_striteri_test(test_nb++, NULL, NULL, NULL);
    //Test 6
    ft_striteri_test(test_nb++, NULL, NULL, iter1);

    TEST_END("ft_striteri");
    SEP;
    NL;
    
}