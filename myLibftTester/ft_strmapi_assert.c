/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 11:20:23 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/05 06:32:19 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

char iter3(unsigned int i, char s)
{
    if (s == 'h')
        s = 'a';
    if (i % 2 == 0)
    {
        if (s >= 65 && s <= 90)
            return(ft_tolower(s));
        else if (s >= 97 && s <= 122)
            return(ft_toupper(s)); 
    }
    return (s);
}

char iter4(unsigned int i, char s)
{
    if (i == 0)
        return ('\0');
    return (s);
}

static void ft_strmapi_test(int test_nb, char *str, char *expected, char (*f)(unsigned int, char))
{
    char *s;
    printf("Test %d: ", test_nb);
   
    s = ft_strmapi(str, f);
    if(expected && s)
        assert(!strcmp(s, expected));
    else
        assert(s == expected);
    printf("expected: %s output: %s -> "C_GREEN"Ok!"C_RESET"\n", expected, s);
    free(s);
}

void ft_strmapi_assert(void)
{
    TEST_STAR("ft_strmapi");
    int test_nb;

    test_nb = 1;
    //Test 1
    ft_strmapi_test(test_nb++, "", "", iter3);
    //Test 2
    ft_strmapi_test(test_nb++, "hello_berlin", "AeLlO_BeRlIn", iter3);
    //Test 3

    /* Question: what is returned if f == NULL */
    
    ft_strmapi_test(test_nb++, "hello_berlin", "hello_berlin", NULL);
    //Test 4
    ft_strmapi_test(test_nb++, "hello_berlin", "", iter4);
    //Test 5
    ft_strmapi_test(test_nb++, NULL, NULL, NULL);
    //Test 6
    ft_strmapi_test(test_nb++, NULL, NULL, iter3);

    TEST_END("ft_strmapi");
    SEP;
    NL;
    
}