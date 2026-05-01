/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:20:37 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/01 16:17:14 by cdric.b          ###   ########.fr       */
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

#define ONE_CHECK 0
#define TWO_CHECK 1

int check_alloc(void *b1, void *b2, int mode)
{
    if(!b1 && mode == ONE_CHECK)
    {
        printf("1\n");
        perror(C_RED"malloc 1 error:"C_RESET);
        return (0);
    }
    else if(b1 && !b2 && mode == TWO_CHECK)
    {
            printf("2\n");
            perror(C_RED"malloc 2 error:"C_RESET);
            free(b1);
            b1 = NULL;
            return (0);
    }
    return (1);
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
    assert(ft_atoi("      ++++---+++42") == atoi("      ++++---+++42"));
    assert(ft_atoi("      +42") == atoi("      +42"));
    assert(ft_atoi("      42") == atoi("      42"));
    assert(ft_atoi("+-0") == atoi("+-0"));
    assert(ft_atoi("+42") == atoi("+42"));
    assert(ft_atoi("42") == atoi("42"));
    assert(ft_atoi("42              ") == atoi("42               "));
    assert(ft_atoi("4 2              ") == atoi("4 2               "));
    assert(ft_atoi("0001") == atoi("0001"));
    assert(ft_atoi("2147483647") == atoi("2147483647"));
    assert(ft_atoi("21474836470000") == atoi("21474836470000"));
    assert(ft_atoi("-2147483648") == atoi("-2147483648"));
    assert(ft_atoi("-21474836480000") == atoi("-21474836480000"));
    assert(ft_atoi("-1") == atoi("-1"));
    assert(ft_atoi("-+1") == atoi("+-1"));
    assert(ft_atoi("          aaaaa1") == atoi("          aaaaa1"));
    assert(ft_atoi("") == atoi(""));
    assert(!ft_atoi("+-10") && !atoi("+-10"));
    assert(ft_atoi("\n") == atoi("\n"));
    TEST_END;
}

void ft_bzero_assert(void)
{
    TEST_START;

    int size;
    int n;
    void *b1;
    void *b2;

    n = 10;
    size = sizeof(int);
    b1 = malloc(n * size);
    

    if (!check_alloc(b1, NULL, ONE_CHECK))
        return ;
    b2 = malloc(n * size);
    if(!check_alloc(b1, b2, TWO_CHECK))
        return ;

    ft_bzero(b1, n * size);
    bzero(b2, n * size);
    assert(!memcmp(b1,b2,n * size));
    TEST_END;

}


int main(void)
{
    ft_strdup_assert();
    ft_atoi_assert();
    ft_bzero_assert();
    return (0);
}