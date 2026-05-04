/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:20:37 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/04 08:41:40 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"



// #define ONE_CHECK 0
// #define TWO_CHECK 1

// int check_alloc(void *b1, void *b2, int mode)
// {
//     if(!b1 && mode == ONE_CHECK)
//     {
//         printf("1\n");
//         perror(C_RED"malloc 1 error:"C_RESET);
//         return (0);
//     }
//     else if(b1 && !b2 && mode == TWO_CHECK)
//     {
//             printf("2\n");
//             perror(C_RED"malloc 2 error:"C_RESET);
//             free(b1);
//             b1 = NULL;
//             return (0);
//     }
//     return (1);
// }



// void ft_bzero_assert(void)
// {
//     TEST_START;

//     int size;
//     int n;
//     void *b1;
//     void *b2;

//     n = 10;
//     size = sizeof(int);
//     b1 = malloc(n * size);
    

//     if (!check_alloc(b1, NULL, ONE_CHECK))
//         return ;
//     b2 = malloc(n * size);
//     if(!check_alloc(b1, b2, TWO_CHECK))
//         return ;

//     ft_bzero(b1, n * size);
//     bzero(b2, n * size);
//     assert(!memcmp(b1,b2,n * size));
    
//     TEST_END;

// }


int main(void)
{
    str_classification_assert();
    ft_atoi_assert();
    ft_itoa_assert();
    ft_strdup_assert();
    //ft_calloc_assert();
    ft_split_assert();
    ft_strchr_assert();
    ft_strrchr_assert();
    ft_striteri_assert();
    return (0);
}