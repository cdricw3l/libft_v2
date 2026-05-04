/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:35:13 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/04 20:11:19 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_strtrim_test(int test_nb, char *s1, char *set, char *expected)
{
    char *str;

    #ifdef __APPLE__
        size_t (*f)(const void *ptr);
        f = malloc_size;
    #else
        size_t (*f)(void *ptr);
        f = malloc_usable_size;
    #endif

    printf("Test %d: ",test_nb);
    str = ft_strtrim(s1, set);
    if(!expected)
        printf("input: %p expected output: %p effective output: %p -> "C_GREEN"Ok! "C_RESET"memory check ->"C_GREEN "Ok! "C_RESET"\n", s1, expected, str);

    else
    {
        assert(!strcmp(str, expected));
        assert(f(str) == f(expected));
        printf("input: %s expected output: "C_PBG"%s"C_RESET " effective output: "C_PBG"%s"C_RESET"-> "C_GREEN"Ok! "C_RESET"memory check ->"C_GREEN "Ok! "C_RESET"\n", s1, expected, str);
        free(str);
        free(expected);
    }

}


void ft_strtrim_assert(void)
{
    char *test_name = "ft_strtrim";
    TEST_STAR(test_name);
    int test_nb;
    char *s1;
    char *s2;

    test_nb = 1;

    ft_strtrim_test(test_nb++,"   ***hello_berlin***   ", " *", strdup("hello_berlin"));
    ft_strtrim_test(test_nb++,"   ***hello_berlin***   ", "XxRr", strdup("   ***hello_berlin***   "));
    ft_strtrim_test(test_nb++,"AAAAAbcbcbcAAAA@bcAAbcAAAbc", "Abc", strdup("@"));
    ft_strtrim_test(test_nb++,"   ***hello_berlin***   ", "", strdup("   ***hello_berlin***   "));
    ft_strtrim_test(test_nb++,"", "   ***hello_berlin***   ", strdup(""));
    ft_strtrim_test(test_nb++,"   ******   ", " *", strdup(""));
    ft_strtrim_test(test_nb++,"**hello***berlin***", " *", strdup("hello***berlin"));
    ft_strtrim_test(test_nb++,"**hello***berlin***42", " *", strdup("hello***berlin***42"));
    ft_strtrim_test(test_nb++, NULL, " *", NULL);
    char str1[] = {-10, -10, -50, 97, -10, -50, -10, 0};
    char set[] = {-10, -50, 0};
    s1 = strdup(str1);
    s2 = strdup(set);
    ft_strtrim_test(test_nb++, s1, s2 ,strdup("a"));
    free(s1);
    free(s2);

    TEST_OK(test_name);
    SEP;
    NL;

}