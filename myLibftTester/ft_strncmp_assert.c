/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:33:33 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/05 06:32:40 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

static void ft_strncmp_test(int test_nb, char *s1, char *s2, size_t n)
{
    int r1;
    int r2;

    printf("Test %d: ", test_nb);
    r1 = ft_strncmp(s1, s2, n);
    r2 = strncmp(s1, s2, n);
    if(r1 == r2)
        printf("original output: %d ft output: %d -> "C_GREEN "Ok!"C_RESET"\n",r1,r2);
    else
        printf("original output: %d ft output: %d -> "C_RED "NOk!"C_RESET"\n",r1,r2);
    free(s1);
    free(s2);
}

void ft_strncmp_assert(void)
{
    char *test_name = "ft_strncmp";
    TEST_STAR(test_name);
    int test_nb;

    test_nb = 1;
    
    ft_strncmp_test(test_nb++ ,strdup("hello_berlin"), strdup("hello_berlin"), strlen("hello_berlin"));
    ft_strncmp_test(test_nb++ ,strdup("hello_berlin"), strdup("hello_berlin"), 0);
    ft_strncmp_test(test_nb++ ,strdup("hello_berlin"), strdup("hello_berlin"), 1000);
    ft_strncmp_test(test_nb++ ,strdup("hello_berlin42"), strdup("hello_berlin"), 1000);
    ft_strncmp_test(test_nb++ ,strdup("hello_berlin"), strdup("hello_berlin42"), strlen("hello_berlin"));
    ft_strncmp_test(test_nb++ ,strdup("hello_berlin"), strdup("hello_b"), strlen("hello_berlin"));
    ft_strncmp_test(test_nb++ ,strdup("hello_berlin"), strdup("hello_b"), strlen("hello_b"));
    char str[] = {-10,-55,-128,-32, 55, 127, 255, '\0'};
    ft_strncmp_test(test_nb++ ,strdup(str), strdup(str), strlen(str));
    ft_strncmp_test(test_nb++ , strdup(str), strdup(&str[2]), -1);


    
    ft_strncmp_test(test_nb++ ,strdup(str), strdup("hello_berlin"), 10);
    ft_strncmp_test(test_nb++ ,strdup("hello_berlin"), strdup(str), 10);
    ft_strncmp_test(test_nb++ ,strdup("          "), strdup("          42"), strlen("          "));


    TEST_END(test_name);
    SEP;
    NL;
}