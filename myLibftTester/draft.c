/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 10:22:51 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/04 18:29:01 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"


int main(void)
{
    char str1[] = {-10, -10, -50, 97, -10, -50, -10, 0};
    char set[] = {10, -50, 0};
    int r = strncmp(str1, set, 1);

    printf("r1u %d\n", (unsigned char)-10 - 10);
    printf("r2u %d\n", (unsigned char)10);
    printf("voici r: %d\n", strncmp("hello_berlin42", "hello_berlin", 1000));
    printf("voici r: %d\n", ft_strncmp("hello_berlin42", "hello_berlin", 1000));
    return (0);

}