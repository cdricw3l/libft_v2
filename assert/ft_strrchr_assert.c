#include "assertion.h"

void ft_strrchr_test(int test_nb, char *s, int c)
{
    char *p1;
    char *p2;
    printf("Test %d:", test_nb);
    p1 = strchr(s,c);
    p2 = ft_strchr(s,c);
    printf(" original -> %p ft -> %p -> " C_GREEN "Ok!"C_RESET "\n", p1, p2);
    assert(p1 == p2);

}


void ft_strrchr_assert(void)
{

    TEST_STAR("ft_strrchr");

    char *str;
    int test_nb;

    test_nb = 1;
    str = ft_strdup("hello_berlin");
    assert(str);
    // Test 1
    ft_strrchr_test(test_nb++, str, 'x');
    // Test 2
    ft_strrchr_test(test_nb++, str, 'h');
    // Test 3
    ft_strrchr_test(test_nb++, str, 'l');
    // Test 4
    ft_strrchr_test(test_nb++, str, 'b');
    // Test 5
    ft_strrchr_test(test_nb++, str, '\0');
    // Test 6
    free(str);
    str = ft_strdup("");
    assert(str);
    // Test 7
    ft_strrchr_test(test_nb++, str, '\0');
    // Test 8
    ft_strrchr_test(test_nb++, str, 'A');
    free(str);
    char s0[] = {-10, -12, -127, 32, 97, 98, -127, '\0'};
    // Test 9
    ft_strrchr_test(test_nb++, s0, -127);
    char s1[] = {-10, -12, -127, 32, 97, 98,'\0'};
    // Test 10
    ft_strrchr_test(test_nb++, s1, INT_MAX);

    TEST_OK("ft_strrchr");

}