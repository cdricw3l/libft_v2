/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 21:50:35 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/07 22:44:37 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_putendl_test(int test_number, char *str, int fd)
{
    char *buffer;
    int tube[2];
    int b_read;
    int status;
    pid_t pid;
    int len;

    if (str)
        len = strlen(str);
    else
        len = 0;
    int p = pipe(tube);
    if (p < 0)
    {
        printf("Error pipe creation in %s line:%d", __func__, __LINE__ - 3);
        return ;
    }
    if (dup2(fd, tube[1]) < 0)
    {
        printf("Error dup2  in %s line:%d", __func__, __LINE__ - 3);
        close(tube[0]);
        close(tube[1]);
    }
    printf("Test %d:\n", test_number);
    pid = fork();
    if (pid < 0)
    {
        printf("Error fork creation in %s line:%d", __func__, __LINE__ - 3);
        close(tube[0]);
        close(tube[1]);
        return ;

    }
    if (pid == 0)
    {
        close(tube[0]);
        ft_putendl_fd(str, tube[1]);
        close(tube[1]);
        exit(0);   

    }
    else
    {
        close(tube[1]);
        waitpid(pid, &status, 0);
        if(!WIFEXITED(status))
        {
            close(tube[0]);
            printf("\tCheck null protection -> "TEST_NOK"\n");
            printf("\tft_putstr ->"TEST_NOK"\n");
            return ;
        }
        buffer = malloc(sizeof(char) * (len + 2));
        if (!buffer)
        {
            printf("Error allocation buffer in %s line:%d", __func__, __LINE__ - 3);
            close(tube[0]);
            return ;
        }
        b_read = read(tube[0], buffer, len + 2);
        close(tube[0]);
        buffer[b_read] = '\0';
        printf("voici %d\n", b_read);
        if (!str)
            printf("\tCheck null protection -> "TEST_OK"\n");
        else if(!strncmp(buffer, str, b_read - 2) && buffer[b_read - 1] == '\n')
            printf("\tft_putstr ->"TEST_OK"\n");
        else
            printf("\tft_putstr ->"TEST_NOK"\n");
        free(buffer);
    }
}


void ft_putendl_assert(void)
{
    char *test_name = "ft_putstr";
    int test_number;
    int fd;
    TEST_STAR(test_name);
    test_number = 1;

    //TEST 1
    ft_putendl_test(test_number++,"\thello 42 berlin", STDOUT_FILENO);
    //TEST 2
    ft_putendl_test(test_number++,NULL, STDOUT_FILENO);
    //TEST 3
    fd = dup(STDOUT_FILENO);
    ft_putendl_test(test_number++,"\thello 42 berlin", fd);
    close(fd);

    TEST_END(test_name);
}