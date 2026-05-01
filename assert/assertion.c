/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:20:37 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/01 15:03:05 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void test_and_clean_str(char *s1, char *s2)
{

    if(s1 && s2)
        assert(!strcmp(s1,s2));
    if(s1)
    {
        s1 = NULL;
        free(s1);
    }
    if (s2)
    {
        s2 = NULL;
        free(s2);
    }
}

void ft_strdup_assert(void)
{
    TEST_START;
    char *s1;
    char *s2;

    s1 = ft_strdup("");
    s2 = strdup("");
    
    
    s1 = ft_strdup("hello_world");
    s2 = strdup("hello_world");
    test_and_clean_str(s1, s2);

    s1  = strdup("                                                  ");
    s2  = ft_strdup("                                                  ");
    test_and_clean_str(s1, s2);
    
    char b1[7] = {-10,-10, -10, -10, -10, -10, '\0'};
    s1 = strdup(b1);    
    s2 = ft_strdup(b1);
    assert(s1[0] == -10 && s2[0] == -10);    
    test_and_clean_str(s1,s2);

    s1 = strdup("\n\t\n\r dqdqwddqw     dwqdwq  dwq $$$$!^");
    s2 = ft_strdup("\n\t\n\r dqdqwddqw     dwqdwq  dwq $$$$!^");
    test_and_clean_str(s1,s2);
    
    TEST_END;
}

void ft_atoi_assert(void)
{
    TEST_START;


    TEST_END;
}




int main(void)
{
    ft_strdup_assert();
    return (0);
}