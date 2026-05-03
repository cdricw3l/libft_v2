/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_assert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 15:02:53 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/03 15:24:06 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void test_and_clean_str(char *s1, char *s2, int test_nb)
{
    if(s1 && s2)
    {
        assert(!strcmp(s1,s2));
        assert(malloc_usable_size(s1) == malloc_usable_size(s2));
    }
    printf("test %d :" "string are the same comparaison ->" C_GREEN " OK!" C_RESET " memory allocation size are the same -> "C_GREEN "OK!\n" C_RESET, test_nb);
    
    if(s1)
    {
        free(s1);
        s1 = NULL;
    }
    if (s2)
    {
        free(s2);
        s2 = NULL;
    }
}

void ft_strdup_assert(void)
{
    TEST_STAR("ft_strdup")
    char *s1;
    char *s2;
    int test_nb;

    test_nb = 1;
    s1 = ft_strdup("");
    s2 = strdup("");
    test_and_clean_str(s1, s2, test_nb++);
    
    s1 = ft_strdup("hello_world");
    s2 = strdup("hello_world");
    test_and_clean_str(s1, s2,test_nb++);

    s1  = strdup("                                                  ");
    s2  = ft_strdup("                                                  ");
    test_and_clean_str(s1, s2, test_nb++);
    
    char b1[7] = {-10,-10, -10, -10, -10, -10, '\0'};
    s1 = strdup(b1);    
    s2 = ft_strdup(b1);
    assert(s1[0] == -10 && s2[0] == -10);    
    test_and_clean_str(s1, s2, test_nb++);

    s1 = strdup("\n\t\n\r dqdqwddqw     dwqdwq  dwq $$$$!^");
    s2 = ft_strdup("\n\t\n\r dqdqwddqw     dwqdwq  dwq $$$$!^");
    test_and_clean_str(s1,s2, test_nb++);
    
    char b2[7] = {255, 255, -10, -10, -10, -10, '\0'};
    s1 = strdup(b2);    
    s2 = ft_strdup(b2);
    test_and_clean_str(s1,s2, test_nb++);
    
    TEST_OK("ft_strdup");
    SEP;
    NL;
}