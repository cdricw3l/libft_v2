/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_assert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:34:02 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/05 07:06:23 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

static void *clean_split(char **split)
{
    char	**ptr;

	ptr = split;
	while (*ptr)
	{
		if (*ptr)
		{
			free(*ptr);
			*ptr = NULL;
		}
		ptr++;
	}
	free(split);
	split = NULL;
	return (NULL);
}

static void ft_split_test(int test_nb, char **split, ...)
{
    va_list ap;
    char **ptr;
    char *arg;
    int memory;
    int cmp;

    
    #ifdef __APPLE__
        size_t (*f)(const void *ptr);
        f = malloc_size;
    #else
        size_t (*f)(void *ptr);
        f = malloc_usable_size;
    #endif
    if(test_nb == 1)
    {
        if (!split)
            printf("Test %d: comparaison -> " TEST_OK " memory -> " TEST_OK "\n",test_nb);
        else
            printf("Test %d: comparaison -> " TEST_NOK " memory -> " TEST_NOK "\n",test_nb);
        return ;
    }
    ptr = split;
    va_start(ap, split);
    if(test_nb == 4)
    {
        if ((*ptr))
            printf("Test %d: comparaison -> " TEST_NOK " memory -> " TEST_NOK "\n", test_nb);
        else
            printf("Test %d: comparaison -> " TEST_OK " memory -> " TEST_OK "\n", test_nb);
        clean_split(split);
        return;
    }

    printf("Test %d: ",test_nb);
    memory = 1;
    cmp = 1;
    while (*ptr)
    {
        arg = va_arg(ap, char *);
        assert(arg);
        if(strcmp(arg, *ptr))
        {
            cmp = 0;
            memory = 0;
            break;
        }
        if(f(*ptr) != f(arg))
        {
            memory = 1;
            break;
        }
            
        ptr++;
    }
    if(split)
        clean_split(split);
    if(cmp)
        printf("comparaison -> " TEST_OK );
    else
        printf("comparaison -> " TEST_OK);
    if(memory)
        printf(" memory -> " TEST_OK "\n");
    else
        printf(" memory -> " TEST_NOK "\n");
    
    va_end(ap);
}

void ft_split_assert(void)
{
    int test_nb;

    TEST_STAR("ft_split");
    test_nb = 1;
    ft_split_test(test_nb++, ft_split(NULL, '_'), NULL);
    ft_split_test(test_nb++, ft_split("hello_berlin_comment_ca_va", '_'), "hello","berlin", "comment", "ca", "va");
    ft_split_test(test_nb++, ft_split("hello_berlin_comment_ca_va", '@'), "hello_berlin_comment_ca_va");
    ft_split_test(test_nb++, ft_split("****************", '*'), NULL);
    ft_split_test(test_nb++, ft_split("            ****************", '*'), "            ");
    ft_split_test(test_nb++, ft_split("42*424242*********42", '*'), "42", "424242", "42");
    ft_split_test(test_nb++, ft_split("42*******424242*********42", '*'), "42", "424242", "42");
    ft_split_test(test_nb++, ft_split("*********42", '*'), "42");
    ft_split_test(test_nb++, ft_split("$42$42$42$42$42", '$'), "42", "42", "42", "42", "42");
    char str[6] = {'A','A', -100,'A','A','\0'};
    ft_split_test(test_nb++, ft_split(str, -100), "AA", "AA");

    TEST_END("ft_split");
    SEP;
    NL;
}