/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:22:42 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/05 06:32:11 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_strlcat_test(int test_nb, char *s1, char *s2, size_t buffer_size)
{
    char *buffer1;
    char *buffer2;
    size_t len1;
    size_t len2;

    buffer1 = malloc(sizeof(char) * (buffer_size));
    buffer2 = malloc(sizeof(char) * (buffer_size));
    assert(buffer1 && buffer2);
    if(s1)
    {
        strlcpy(buffer1, s1, buffer_size);
        strlcpy(buffer2, s1, buffer_size);


    }
    printf("Test %d: \n", test_nb);
    len1 = strlcat(buffer1, s2, buffer_size);
    len2 = strlcat(buffer2, s2, buffer_size);
    assert(len1 == len2);
    assert(!strcmp(buffer1, buffer2));
    printf("expected buffer/size:" C_PBG"%s"C_RESET "/%ld ft buffer/size: "C_PBG"%s"C_RESET "%ld -> "C_GREEN"Ok!"C_RESET"\n", buffer1, len1, buffer2, len2);
    free(buffer1);
    free(buffer2);

}


void ft_strlcat_assert(void)
{
    char *test_name = "ft_strlcat";
    int r1;
    int r2;
    TEST_STAR(test_name);

    char b1[10] = "hello";
    char b2[10] = "hello";

    r1 = ft_strlcat(b1, "_berlin", 10);
    r2 = strlcat(b2, "_berlin", 10);
    assert(r1 == r2);
     printf("b1: %s and b2: %s\n", b1, b2);
    assert(!strcmp(b1, b2));

    char b3[2] = "";
    char b4[2] = "";
    r1 = ft_strlcat(b3, "_berlin", 2);
    r2 = strlcat(b4, "_berlin", 2);
    assert(r1 == r2);
    printf("b3: %s and b4: %s\n", b3, b4);
    assert(!strcmp(b3, b4));

    char b5[2] = "";
    char b6[2] = "";

    r1 = ft_strlcat(b5, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", 2);
    r2 = strlcat(b6, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", 2);
    assert(r1 == r2 );
    printf("b5: %s and b6: %s\n", b5, b6);
    assert(!strcmp(b5, b6));
    
    
    char b7[30] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    char b8[30] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    assert(ft_strlcat(b7, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", 30) == strlcat(b8, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", 30));
    printf("b7: %s and b8: %s\n", b7, b8);
    assert(!strcmp(b7, b8));

    char b9[30] = "xxx";
    char b10[30] = "xxx";

    r1 = ft_strlcat(b9, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", 0);
    r2 = strlcat(b10, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", 0);
    assert( r1 == r2);
    printf("b9: %s and b10: %s\n", b9, b10);
    assert(!strcmp(b9, b10));

    char b11[30] = "xxx";
    char b12[30] = "xxx";

    r1 = ft_strlcat(b9, "", 3);
    r2 = strlcat(b10, "", 3);
    assert( r1 == r2);
    printf("b9: %s and b10: %s\n", b11, b12);
    assert(!strcmp(b11, b12));

    
    TEST_END(test_name);
    SEP;
    NL;
}