/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:53:09 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/05 16:01:40 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_strnstr_test(int test_nb, char *haystack, char *needle, size_t len)
{
    char *s1;
    char *s2;

    #ifdef __APPLE__
        size_t (*f)(const void *ptr);
        f = malloc_size;
    #else
        size_t (*f)(void *ptr);
        f = malloc_usable_size;
    #endif

    printf("Test %d:", test_nb);
    s1 = strnstr(haystack, needle, len);
    s2 = ft_strnstr(haystack, needle, len);
    if ((!s1 && s2) || (s1 && !s2))
    {
        printf("\n\tstring compare ->"TEST_NOK"\n");
        return ;
    }
    if (!s1 && !s2)
    {
        printf("\n\tstring compare ->"TEST_OK"\n");
        return ;
    }
    if (!strcmp(s1,s2))
        printf("\n\tstring compare ->"TEST_OK"\n");
    else   
        printf("\n\tstring compare ->"TEST_NOK"\n");
}
 

void ft_strnstr_assert(void)
{
    char *test_name = "ft_strnstr";
    int test_nb;
    TEST_STAR(test_name);

    test_nb = 1;
    
    //Test 1
    ft_strnstr_test(test_nb++, "hello_berlin", "berlin", strlen("hello_berlin"));
    //Test 2
    ft_strnstr_test(test_nb++, "hello_berlin", "Michel", strlen("hello_berlin"));
    //Test 3
    ft_strnstr_test(test_nb++, "hello_berlin", "_", strlen("hello_berlin"));
    //Test 4
    ft_strnstr_test(test_nb++, "hello_berlin", "berlin", 5);
    //Test 5
    ft_strnstr_test(test_nb++, "hello_berlin", "", 0);
    //Test 6
    ft_strnstr_test(test_nb++, "hello_berlin", "", -10);
    //Test 7
    ft_strnstr_test(test_nb++, "hello_berlin", "", 100);
    //Test 8
    ft_strnstr_test(test_nb++, "hello_berlin", "lin", 1000);
    //Test 9
    ft_strnstr_test(test_nb++, "hello_berlin**", "**", strlen("hello_berlin**"));
    //Test 10
    ft_strnstr_test(test_nb++, "hello_berlin**", "h", 1);
    //Test 11
    ft_strnstr_test(test_nb++, "hello_berlin**", "h", 0);

    NL;
    TEST_END(test_name);
    SEP;
    NL;
}