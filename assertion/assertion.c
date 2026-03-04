/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:20:38 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/04 22:33:57 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"


void    ft_isalpha_assert(void)
{
    printf( "\033[33m" "\nTEST: %s\n" "\033[0m", __FUNCTION__);
    assert(ft_isalpha('a') == isalpha('a')); assert(ft_isalpha('z') == isalpha('z')); assert(ft_isalpha('g') == isalpha('g'));
    assert(ft_isalpha('A') == isalpha('A')); assert(ft_isalpha('Z') == isalpha('Z')); assert(ft_isalpha('K') == isalpha('K'));
    assert(ft_isalpha('0') == isalpha('0')); assert(ft_isalpha('9') == isalpha('9')); assert(ft_isalpha('3') == isalpha('3'));
    assert(ft_isalpha('\n') == isalpha('\n')); assert(ft_isalpha('\t') == isalpha('\t')); assert(ft_isalpha(' ') == isalpha(' '));
    assert(ft_isalpha(0) == isalpha(0)); assert(ft_isalpha(127) == isalpha(127)); assert(ft_isalpha('-') == isalpha('-'));
    printf( "\033[32m" "TEST: %s OK!\n" "\033[0m", __FUNCTION__);
}

void    ft_digit_assert(void)
{
    printf( "\033[33m" "\nTEST: %s\n" "\033[0m", __FUNCTION__);
    assert(ft_isdigit('0') == isdigit('0')); assert(ft_isdigit('5') == isdigit('5')); assert(ft_isdigit('9') == isdigit('9'));
    assert(ft_isdigit('a') == isdigit('a'));assert(ft_isdigit('A') == isdigit('A')); assert(ft_isdigit('Z') == isdigit('Z'));
    assert(ft_isdigit(0) == isdigit(0)); assert(ft_isdigit('\n') == isdigit('\n')); assert(ft_isdigit('\v') == isdigit('\v'));
    assert(ft_isdigit('-') == isdigit('-')); assert(ft_isdigit('+') == isdigit('+')); assert(ft_isdigit(127) == isdigit(127));
    printf( "\033[32m" "TEST: %s OK!\n" "\033[0m", __FUNCTION__);
}

void    ft_isalnum_assert(void)
{
    printf( "\033[33m" "\nTEST: %s\n" "\033[0m", __FUNCTION__);
    assert(ft_isalnum('0') == isalnum('0')); assert(ft_isalnum('5') == isalnum('5')); assert(ft_isalnum('9') == isalnum('9'));
    assert(ft_isalnum('a') == isalnum('a'));assert(ft_isalnum('A') == isalnum('A')); assert(ft_isalnum('Z') == isalnum('Z'));
    assert(ft_isalnum(0) == isalnum(0)); assert(ft_isalnum('\n') == isalnum('\n')); assert(ft_isalnum('\v') == isalnum('\v'));
    assert(ft_isalnum('-') == isalnum('-')); assert(ft_isalnum('+') == isalnum('+')); assert(ft_isalnum(127) == isalnum(127));
    assert(ft_isalnum(145) == isalnum(145)); assert(ft_isalnum(255) == isalnum(255)); assert(ft_isalnum(320) == isalnum(320));
    printf( "\033[32m" "TEST: %s OK!\n" "\033[0m", __FUNCTION__);
}

void    ft_isascii_assert(void)
{
    printf( "\033[33m" "\nTEST: %s\n" "\033[0m", __FUNCTION__);
    assert(ft_isascii('0') == isascii('0')); assert(ft_isascii('5') == isascii('5')); assert(ft_isascii('9') == isascii('9'));
    assert(ft_isascii('a') == isascii('a'));assert(ft_isascii('A') == isascii('A')); assert(ft_isascii('Z') == isascii('Z'));
    assert(ft_isascii(0) == isascii(0)); assert(ft_isascii('\n') == isascii('\n')); assert(ft_isascii('\v') == isascii('\v'));
    assert(ft_isascii('-') == isascii('-')); assert(ft_isascii('+') == isascii('+')); assert(ft_isascii(127) == isascii(127));
    assert(ft_isascii(145) == isascii(145)); assert(ft_isascii(255) == isascii(255)); assert(ft_isascii(320) == isascii(320));
    assert(ft_isascii(__INT_MAX__) == isascii(__INT_MAX__)); assert(ft_isascii(-1234) == isascii(-1234)); assert(ft_isascii(3200) == isascii(3200));
    printf( "\033[32m" "TEST: %s OK!\n" "\033[0m", __FUNCTION__);
}

void    ft_isprint_assert(void)
{
    printf( "\033[33m" "\nTEST: %s\n" "\033[0m", __FUNCTION__);
    assert(ft_isprint(12) == isprint(12)); assert(ft_isprint(48) == isprint(49)); assert(ft_isprint(54) == isprint(54));
    assert(ft_isprint('0') == isprint('0')); assert(ft_isprint('5') == isprint('5')); assert(ft_isprint('9') == isprint('9'));
    assert(ft_isprint('a') == isprint('a'));assert(ft_isprint('A') == isprint('A')); assert(ft_isprint('Z') == isprint('Z'));
    assert(ft_isprint(0) == isprint(0)); assert(ft_isprint('\n') == isprint('\n')); assert(ft_isprint('\v') == isprint('\v'));
    assert(ft_isprint('-') == isprint('-')); assert(ft_isprint('+') == isprint('+')); assert(ft_isprint(127) == isprint(127));
    assert(ft_isprint(145) == isprint(145)); assert(ft_isprint(255) == isprint(255)); assert(ft_isprint(320) == isprint(320));
    assert(ft_isprint(__INT_MAX__) == isprint(__INT_MAX__)); assert(ft_isprint(-1234) == isprint(-1234)); assert(ft_isprint(3200) == isprint(3200));
    assert(ft_isprint(-1) == isprint(-1));
    printf( "\033[32m" "TEST: %s OK!\n" "\033[0m", __FUNCTION__);
}

void    ft_strlen_assert(void)
{
    printf( "\033[33m" "\nTEST: %s\n" "\033[0m", __FUNCTION__);
    assert(ft_strlen("hello world") == strlen("hello world"));
    assert(ft_strlen(" world") == strlen(" world"));
    assert(ft_strlen("d") == strlen("d"));
    assert(ft_strlen("") == strlen(""));
    assert(ft_strlen("dqfqfefeqfeqfeqfeqfeqfqefeqfqefqfeqfqfqefeqfeqfq") == strlen("dqfqfefeqfeqfeqfeqfeqfqefeqfqefqfeqfqfqefeqfeqfq"));
    assert(ft_strlen("                                                ") == strlen("                                                "));
    assert(ft_strlen("                                                a") == strlen("                                                a"));
    printf( "\033[32m" "TEST: %s OK!\n" "\033[0m", __FUNCTION__);
}

void    ft_memset_assert(void)
{
    char buffer1[10];
    char buffer2[10];

    printf( "\033[33m" "\nTEST: %s\n" "\033[0m", __FUNCTION__);
    ft_memset(buffer1, 0, 10);
    memset(buffer2, 0, 10);
    assert(!memcmp(buffer1, buffer2, 10));
    ft_memset(buffer1, 97, 10);
    memset(buffer2, 97, 10);
    assert(!memcmp(buffer1, buffer2, 10));
    memset(buffer2, 0, 0);
    ft_memset(buffer1, 0, 0);
    assert(!memcmp(buffer1, buffer2, 0));
    assert(ft_memset(buffer1, 0, 10) == memset(buffer1, 0, 10));
    printf( "\033[32m" "TEST: %s OK!\n" "\033[0m", __FUNCTION__);
}

void    ft_bzero_assert(void)
{
    char buffer1[10];
    char buffer2[10];

    printf( "\033[33m" "\nTEST: %s\n" "\033[0m", __FUNCTION__);
    ft_bzero(buffer1, 10);
    bzero(buffer2, 10);
    assert(!memcmp(buffer1, buffer2, 10));
    ft_bzero(buffer1, 5);
    bzero(buffer2, 5);
    assert(!memcmp(buffer1, buffer2, 5));
    ft_bzero(buffer1, 1);
    bzero(buffer2, 1);
    assert(!memcmp(buffer1, buffer2, 1));
    printf( "\033[32m" "TEST: %s OK!\n" "\033[0m", __FUNCTION__);
}

void    ft_strchr_assert(void)
{
    printf( "\033[33m" "\nTEST: %s\n" "\033[0m", __FUNCTION__);
    char *str = "hello_world";

    assert(ft_strchr(str, 'l') == &str[2]);
    assert(ft_strchr(str, 'l') == strchr(str, 'l'));
    assert(ft_strchr(str, 'z') == strchr(str, 'z'));
    assert(ft_strchr(str, '\0') == strchr(str, '\0'));
    assert(ft_strchr(str, -1) == strchr(str, -1));
    str = "";
    assert(ft_strchr(str, 'l') == NULL);
    assert(ft_strchr(str, 'l') == strchr(str, 'l'));
    assert(ft_strchr(str, 'z') == strchr(str, 'z'));
    assert(ft_strchr(str, '\0') == strchr(str, '\0'));
    assert(ft_strchr(str, -1) == strchr(str, -1));
    printf( "\033[32m" "TEST: %s OK!\n" "\033[0m", __FUNCTION__);

}

void    ft_strrchr_assert(void)
{
    printf( "\033[33m" "\nTEST: %s\n" "\033[0m", __FUNCTION__);
    char *str = "hello_world";

    assert(ft_strrchr(str, 'l') == &str[9]);
    assert(ft_strrchr(str, 'l') == strrchr(str, 'l'));
    assert(ft_strrchr(str, 'z') == strrchr(str, 'z'));
    assert(ft_strrchr(str, '\0') == strrchr(str, '\0'));
    assert(ft_strrchr(str, -1) == strrchr(str, -1));
    str = "";
    assert(ft_strrchr(str, 'l') == NULL);
    assert(ft_strrchr(str, 'l') == strrchr(str, 'l'));
    assert(ft_strrchr(str, 'z') == strrchr(str, 'z'));
    assert(ft_strrchr(str, '\0') == strrchr(str, '\0'));
    assert(ft_strrchr(str, -1) == strrchr(str, -1));
    printf( "\033[32m" "TEST: %s OK!\n" "\033[0m", __FUNCTION__);

}

int main(void)
{
    ft_isalpha_assert();
    ft_digit_assert();
    ft_isalnum_assert();
    ft_isascii_assert();
    ft_isprint_assert();
    ft_strlen_assert();
    ft_memset_assert();
    ft_bzero_assert();

    //ft_memcpy_assert();
    //ft_memmove_assert();
    //ft_ft_toupper_assert();
    //ft_ft_tolower_assert();
    
    ft_strchr_assert();
    ft_strrchr_assert();
    return (0);
}