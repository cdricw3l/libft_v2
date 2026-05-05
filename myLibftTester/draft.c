/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 10:22:51 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/05 17:58:03 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void print_memory_addr(char *s1, char *s2)
{
    printf("addr 1: %p\n", s1);
    printf("addr 2: %p\n", s2);

    printf("Voici %d\n", strncmp(s1,s2, strlen(s1)));
    printf("Voici %d\n", ft_strncmp(s1,s2, strlen(s1)));
}

void print_bit(size_t n, int bit)
{

    while (bit - 1 >= 0)
    {
        printf("%ld", (n >> bit) & 1);
        bit--;
    }
    printf("\n");
}




int main(void)
{
    // char str1[] = {-10, -10, -50, 97, -10, -50, -10, 0};
    // char set[] = {10, -50, 0};
    // int r = strncmp(str1, set, 1);

    // printf("r1u %d\n", (unsigned char)-10 - 10);
    // printf("r2u %d\n", (unsigned char)10);
    // printf("voici r: %d\n", strncmp("hello_berlin42", "hello_berlin", 1000));
    // printf("voici r: %d\n", ft_strncmp("hello_berlin42", "hello_berlin", 1000));

    // char *s1 = ft_strdup("hello");
    // char *s2 = ft_strdup("Wello");
    // print_memory_addr("hello", "Wllo");
    // print_memory_addr(s1, s2);

    // free(s1);
    // free(s2);

  

    int r0;
    size_t r1;

    r0 = -100;
    r1 = -100;

    print_bit(r0, 64);
    print_bit(r1, 64);
    return (0);

}