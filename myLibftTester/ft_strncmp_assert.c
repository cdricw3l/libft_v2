/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:33:33 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/04 18:36:30 by cebouhad         ###   ########.fr       */
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
    printf("voici r1: %d et r2: %d\n",r1, r2);
    assert(r1 == r2);
    printf("original output: %d ft output: %d -> "C_GREEN "Ok!"C_RESET"\n",r1,r2);
    free(s1);
    free(s2);
}

void ft_strncmp_assert(void)
{
    char *test_name = "ft_strncmp";
    TEST_STAR(test_name);
    int test_nb;

    test_nb = 1;
    
    ft_strncmp_test(test_nb++ ,strdup("hello_berlin"), ft_strdup("hello_berlin"), strlen("hello_berlin"));
    // ft_strncmp_test(test_nb++ ,"hello_berlin", "hello_berlin", 0);
    // ft_strncmp_test(test_nb++ ,"hello_berlin", "hello_berlin", 1000);
    // ft_strncmp_test(test_nb++ ,"hello_berlin42", "hello_berlin", 1000);
    // ft_strncmp_test(test_nb++ ,"hello_berlin", "hello_berlin42", strlen("hello_berlin"));
    // ft_strncmp_test(test_nb++ ,"hello_berlin", "hello_b", strlen("hello_berlin"));
    // ft_strncmp_test(test_nb++ ,"hello_berlin", "hello_b", strlen("hello_b"));
    // char str[] = {-10,-55,-128,-32, 55, 127, 255, '\0'};
    // ft_strncmp_test(test_nb++ ,str, str, strlen(str));
    // ft_strncmp_test(test_nb++ , str, &str[2], -1);

    // printf("%d\n", 10 - (-5));
    // printf("%d\n", strcmp(str,"h"));
    
    // ft_strncmp_test(test_nb++ ,str, "hello_berlin", 10);
    // ft_strncmp_test(test_nb++ ,"hello_berlin", str, 10);
    // ft_strncmp_test(test_nb++ ,"          ", "          42", strlen("          "));


    TEST_OK(test_name);
    SEP;
    NL;
}