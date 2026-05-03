/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_assert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:12:59 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/03 21:08:59 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "assertion.h"

// void ft_calloc_test(size_t nmemb, size_t size, int test_nb)
// {
//     char *s1;
//     char *s2;

//     s1 = calloc(nmemb, size);
//     s2 = ft_calloc(nmemb, size);
//     if(malloc_usable_size(s1) != malloc_usable_size(s2))
//         printf("Test %d: nmemb: %zu size %zu"C_RED"NOK!"C_RESET"\n", test_nb, nmemb, size);
//     assert(malloc_usable_size(s1) == malloc_usable_size(s2));
//     printf("Test %d -> Memory check -> " C_GREEN "OK!"C_RESET"\n", test_nb);
//     if(s1)
//         free(s1);
//     if(s2)
//         free(s2);
// }

// void ft_calloc_assert(void)
// {
//     TEST_STAR("ft_calloc");
//     int test_nb;

//     test_nb = 1;
//     char *ptr;
//     char *ptr2;

//     ptr = calloc(0,0);
//     ptr2 = ft_calloc(0,0);
//     printf("voici %p : %ld and %p: %ld\n", ptr, malloc_usable_size(ptr), ptr2,malloc_usable_size(ptr2));
//     if(ptr)
//         free(ptr);
//     if(ptr2)
//         free(ptr2);

//     ptr = calloc(10,-10);
//     ptr2 = ft_calloc(10,-10);
//     printf("voici %p : %ld and %p: %ld\n", ptr, malloc_usable_size(ptr), ptr2,malloc_usable_size(ptr2));
//     if(ptr)
//         free(ptr);
//     if(ptr2)
//         free(ptr2);

//     ptr =  calloc(-10,-10);
//      ptr2 = ft_calloc(-10,-10);
//     printf("voici %p : %ld and %p: %ld\n", ptr, malloc_usable_size(ptr), ptr2,malloc_usable_size(ptr2));
//     if(ptr)
//         free(ptr);
//     if(ptr2)
//         free(ptr2);

//     ptr = calloc(-10,10);
//     ptr2 = ft_calloc(-10,10);
//     printf("voici %p : %ld and %p: %ld\n", ptr, malloc_usable_size(ptr), ptr2,malloc_usable_size(ptr2));
//     if(ptr)
//         free(ptr);
//     if(ptr2)
//         free(ptr2);
//     //assert(1 == 2);
//     ft_calloc_test(0, 0, test_nb++);
//     ft_calloc_test(-10, -10, test_nb++);
//     ft_calloc_test(-10, 10, test_nb++);
//     ft_calloc_test(10, -10, test_nb++);
//     ft_calloc_test(100, 100, test_nb++);
//     ft_calloc_test(INT_MAX, INT_MAX, test_nb++);
//     ft_calloc_test(INT_MIN, INT_MIN, test_nb++);
//     TEST_OK("ft_calloc");
//     SEP;
//     NL;
// }