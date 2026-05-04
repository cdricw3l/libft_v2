/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_assert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:34:02 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/04 06:57:51 by cdric.b          ###   ########.fr       */
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
    size_t (*f)(const void *ptr);

    #ifdef __APPLE__
        f = malloc_size;
    #else
        f = malloc_usable_size;
    #endif

    if(!split)
    {
        assert(test_nb == 1);
        printf("Test %d: comparaison -> " C_GREEN "Ok!"C_RESET " memory -> " C_GREEN "Ok!" C_RESET"\n",test_nb);
        return ;
    }
    ptr = split;
    va_start(ap, split);
    if(!(*ptr) && test_nb == 3)
        assert(va_arg(ap, char *) == NULL);
    while (*ptr)
    {
        arg = strdup(va_arg(ap, char *));
        assert(arg);
        assert(!strcmp(arg, *ptr) && f(*ptr) == f(arg));
        free(arg);
        ptr++;
    }
    if(split)
        clean_split(split);
    printf("Test %d: comparaison -> " C_GREEN "Ok!"C_RESET " memory -> " C_GREEN "Ok!" C_RESET"\n",test_nb);
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

    TEST_OK("ft_split");
    SEP;
    NL;
}