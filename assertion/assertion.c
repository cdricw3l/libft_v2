/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:20:38 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/07 17:37:35 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <limits.h>
#include <malloc/malloc.h>


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

void    ft_strlcpy_assert(void)
{
    printf( "\033[33m" "\nTEST: %s\n" "\033[0m", __FUNCTION__);
    
    char buffer_1[10] = {0};
    char buffer_2[10] = {0};
    char *str = "hello_berlin";

    size_t c1 = strlcpy(buffer_1, str, 10);
    size_t c2 = ft_strlcpy(buffer_2, str, 10);

    assert(c1 == c2);
    assert(!strncmp(buffer_1,buffer_2, 10));
    ft_bzero(buffer_1, 10);
    ft_bzero(buffer_2, 10);

    c1 = strlcpy(buffer_1, str, 5);
    c2 = ft_strlcpy(buffer_2, str, 5);
    assert(c1 == c2);
    assert(!strncmp(buffer_1,buffer_2, 5));

    char buffer_3[100];
    char buffer_4[100];

    ft_bzero(buffer_3, 100);
    ft_bzero(buffer_4, 100);

    c1 = strlcpy(buffer_3, str, 100);
    c2 = ft_strlcpy(buffer_4, str, 100);
    assert(c1 == c2);
    assert(!strncmp(buffer_3,buffer_4, 100));
    ft_bzero(buffer_3, 100);
    ft_bzero(buffer_4, 100);
    
    char *str_2 = "";
    c1 = strlcpy(buffer_3, str_2, 100);
    c2 = ft_strlcpy(buffer_4, str_2, 100);
    assert(c1 == c2);
    assert(buffer_3[0] == '\0' && buffer_4[0] == '\0');
    assert(!strncmp(buffer_3,buffer_4, 100));

    ft_bzero(buffer_3, 100);
    ft_bzero(buffer_4, 100);
    
    char *str_3 = "hello berlin commnet ca va?";
    c1 = strlcpy(buffer_3, str_3, 0);
    c2 = ft_strlcpy(buffer_4, str_3, 0);
    assert(c1 == c2);
    assert(!strncmp(buffer_3,buffer_4, 0));

    char buffer_5[10] = {0};
    char buffer_6[10] = {0};
    char *str_4 = "hello berlin commnet ca va?";
    int r1 = strlcpy(buffer_5, str_4, 0);
    assert(ft_strlen(buffer_5) == 0);
    int r2 = ft_strlcpy(buffer_6, str_4, 0);
    assert(ft_strlen(buffer_6) == 0 && r1 == r2);
    printf( "\033[32m" "TEST: %s OK!\n" "\033[0m", __FUNCTION__);

}

void    ft_strlcat_assert(void)
{
    printf( "\033[33m" "\nTEST: %s\n" "\033[0m", __FUNCTION__);
    
    char buffer[10] = "hello";
    char buffer2[10] = "hello";
    char *str = "_world de merde\n";


    int r = strlcat(buffer, str, 8);
    printf("voici r %d\n", r);
    printf("voici le buffer %s\n", buffer);
    r = ft_strlcat(buffer2, str, 8);
    printf("voici r %d\n", r);
    printf("voici le buffer %s\n", buffer2);

    printf( "\033[32m" "TEST: %s OK!\n" "\033[0m", __FUNCTION__);
}

void    ft_strncmp_assert(void)
{
    printf( "\033[33m" "\nTEST: %s\n" "\033[0m", __FUNCTION__);
    char *str_1 = "";
    char *str_2 = "hello_berlin";
    char *str_3 = "hello_berlin";
    char *str_4 = "hello_berlin";
    char *str_5 = "hello_berlin";
    char *str_6 = "                         hello_berlin";
    char str_7[] = "hello_berlin";
    char *str_8 = "hello_berlim";
    assert(ft_strncmp("hello", "hello", 100) == strncmp("hello", "hello", 100));
    assert(ft_strncmp(str_1, str_2, 100) == strncmp(str_1, str_2, 100));
    assert(ft_strncmp(str_1, str_2, 0) == strncmp(str_1, str_2, 0));
    assert(ft_strncmp(str_1, str_2, 1) == strncmp(str_1, str_2, 1));
    assert(ft_strncmp(str_3, str_4, ft_strlen(str_3)) == strncmp(str_3, str_4, ft_strlen(str_3)));
    assert(ft_strncmp(str_3, str_4, ft_strlen(str_3) + 100) == strncmp(str_3, str_4, ft_strlen(str_3) + 100));
    assert(ft_strncmp(str_5, str_6, ft_strlen(str_5)) == strncmp(str_5, str_6, ft_strlen(str_5)));
    assert(ft_strncmp(str_7, str_8, ft_strlen(str_7)) == strncmp(str_7, str_8, ft_strlen(str_7)));
    printf( "\033[32m" "TEST: %s OK!\n" "\033[0m", __FUNCTION__);
}

void    ft_strnstr_assert(void)
{
    printf( "\033[33m" "\nTEST: %s\n" "\033[0m", __FUNCTION__);
    
    char *str = "hello berlin";
    char *str2 = "berlin";

    char *ptr = strnstr(str, str2, 7);
    char *ptr2 = ft_strnstr(str, str2, 7);
    assert(ptr == ptr2);
    ptr = strnstr(str, str2, 2);
    ptr2 = ft_strnstr(str, str2, 2);
    assert(ptr == NULL);
    ptr = strnstr(str,&str2[ft_strlen(str2)] ,ft_strlen(str));
    ptr2 = ft_strnstr(str,&str2[ft_strlen(str2)] ,ft_strlen(str));
    assert(ptr == ptr2);
    ptr = strnstr(str, str2, 20);
    ptr2 = ft_strnstr(str, str2, 20);
    assert(ptr == ptr2);
    ptr = strnstr(str, str2, 0);
    ptr2 = ft_strnstr(str, str2, 0);
    assert(ptr == ptr2);
    ptr = strnstr(str, &str2[ft_strlen(str2)], 10);
    ptr2 = ft_strnstr(str, &str2[ft_strlen(str2)], 10);
    assert(ptr == ptr2);
    str = "berlin";
    str2 = "b";
    ptr = strnstr(str, str2, 3);
    assert(!ft_strncmp("berlin", ptr, ft_strlen("berlin")));
    ptr2 = ft_strnstr(str, str2, 3);
    assert(ptr == ptr2);
    printf( "\033[32m" "TEST: %s OK!\n" "\033[0m", __FUNCTION__);
}

void    ft_calloc_assert(void)
{
    printf( "\033[33m" "\nTEST: %s\n" "\033[0m", __FUNCTION__);
    
    char *ptr = ft_calloc(10, sizeof(int));
    char *ptr2 = calloc(10, sizeof(int));
    assert(malloc_size(ptr) == malloc_size(ptr2));
    free(ptr);
    free(ptr2);
    ptr = NULL;
    ptr2 = NULL;
    ptr = ft_calloc(INT_MIN, INT_MIN);
    ptr2 = calloc(INT_MIN, INT_MIN);
    assert(ptr == NULL);
    assert(ptr2 == NULL);
    void *ptr3 = ft_calloc(100, 4);
    void *ptr4 = calloc(100, 4);
    free(ptr3);
    free(ptr4);
    ptr3 = NULL;
    ptr4 = NULL;
    assert(malloc_size(ptr3) == malloc_size(ptr4));
    printf( "\033[32m" "TEST: %s OK!\n" "\033[0m", __FUNCTION__);
}

void    ft_strdup_assert(void)
{
    char *ptr = strdup(NULL);
    assert(ptr == NULL);
}

void    ft_substr_assert(void)
{
    printf( "\033[33m" "\nTEST: %s\n" "\033[0m", __FUNCTION__);
    char *str = "hello_world";
	char *new_str = ft_substr(str, 6, 100);
	if (!new_str)
		printf("Error substr\n");
	assert(!ft_strncmp(new_str, "world", ft_strlen(new_str)));
	free(new_str);
	new_str = ft_substr(str,100, 100);
	assert(!new_str);
	new_str = ft_substr(str, ft_strlen(str), 10);
	printf("voici la sub: %s\n", new_str);
	assert(!ft_strncmp(new_str, "", ft_strlen(new_str)));
	free(new_str);
	new_str = ft_substr(str, 0, 0);
	assert(!ft_strncmp(new_str, "", ft_strlen(new_str)));
	free(new_str);
	new_str = ft_substr(str, 0, ft_strlen(str));
	assert(!ft_strncmp(new_str, str, ft_strlen(new_str)));
    printf( "\033[32m" "TEST: %s OK!\n" "\033[0m", __FUNCTION__);
	free(new_str);
}

void    assertion(void)
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
    //ft_ft_memchr();
    //ft_memcmp();
    
    ft_strchr_assert();
    ft_strrchr_assert();
    ft_strlcpy_assert();
    ft_strncmp_assert();
    //ft_strlcat_assert();
    ft_strnstr_assert();
    ft_calloc_assert();
    ft_strdup_assert();
    ft_substr_assert();
}

void print_bit(size_t i)
{
    int b;

    b = 7;
    while (b >= 0)
    {
        printf("%zu", (i >> b) &1);
        b--;
    }
     printf("\n");
    
}

int main(void)
{
    
    size_t i = 10;
    print_bit(i >> 0);
    print_bit((i >> 2) | 1);
    printf("%zu\n", (i >> 1) | 1);
    
    //assertion();
    return (0);
}