/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_class_assert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 09:02:37 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/04 07:18:14 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

#define START -5000
#define END 5000

static void str_classification_test(int(*f)(int), char *f_name, int range_start, int range_end)
{

    int start;
    int r;

    start = START;
    while (start < END)
    {
        if((!strcmp(f_name, "ft_isalpha") && range_start == 97 && start == 65)
            || (!strcmp(f_name, "ft_isalpha") && range_start == 65 && start == 97))
        {
            start += 26;
            continue;
        }
        if((!strcmp(f_name, "ft_isalnum") && range_start == 97 && (start == 48 || start == 65))
            || (!strcmp(f_name, "ft_isalnum") && range_start == 65 && (start == 48 || start == 97))
            || (!strcmp(f_name, "ft_isalnum") && range_start == 48 && (start == 65 || start == 97))
        )
        {
            
            if((range_start == 65 && start == 48) || (range_start == 97 && start == 48))
                start += 10;
            else
                start += 26;
            continue;
        }
        if(start >= range_start && start <= range_end)
        {
            if((r = f(start)) != 1)
            {
                printf("Error fonction %s when value = %d\n expected return 1 but return is %d\n", f_name, start, r);
                assert(r == 1);
            }
        }
        else
        {
            if((r = f(start)) != 0)
            {
                printf("Error fonction %s when value = %d\n expected return 0 but return is %d\n", f_name, start, r);
                assert(r == 0);
            }
        }

        start++;
    }
    printf("Target range: %d to %d ->" C_GREEN " Test OK!\n" C_RESET, range_start, range_end);


}

void str_classification_assert(void)
{
    SEP;
    NL;
    TEST_STAR("ft_isalpha");
    str_classification_test(ft_isalpha, "ft_isalpha", 65, 90);
    str_classification_test(ft_isalpha, "ft_isalpha", 97, 122);
    TEST_OK("ft_isalpha");
    SEP;
    NL;
    TEST_STAR("ft_isdigit");
    str_classification_test(ft_isdigit, "ft_isdigit", 48, 57);
    TEST_OK("ft_isdigit");
    SEP;
    NL;
    TEST_STAR("ft_isalnum");
    str_classification_test(ft_isalnum, "ft_isalnum", 48, 57);
    str_classification_test(ft_isalnum, "ft_isalnum", 65, 90);
    str_classification_test(ft_isalnum, "ft_isalnum", 97, 122);
    TEST_OK("ft_isalnum");
    SEP;
    NL;
    TEST_STAR("ft_isascii");
    str_classification_test(ft_isascii, "ft_isascii", 0, 127);
    TEST_OK("ft_isascii");
    SEP;
    NL;
    TEST_STAR("ft_isprint");
    str_classification_test(ft_isprint, "ft_isprint", 32, 126);
    TEST_OK("ft_isprint");
}