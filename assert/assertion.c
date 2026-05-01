/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:20:37 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/01 14:38:26 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void clean_str(char *s1, char *s2)
{
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

void ft_strdup_assert()
{
    TEST_START;
    char *s1;
    char *s2;

    s1 = ft_strdup("");
    s2 = strdup("");
    assert(!strcmp(s1,s2));
    clean_str(s1, s2);
    
    s1 = ft_strdup("hello_world");
    s2 = strdup("hello_world");
    assert(!strcmp(s1,s2));
    clean_str(s1, s2);
    TEST_END;
}   


int main(void)
{
    ft_strdup_assert();
    return (0);
}