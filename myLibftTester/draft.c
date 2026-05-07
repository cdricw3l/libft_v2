/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:06:26 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/07 21:49:29 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

#define BUFFER_SIZE 10

int main(void)
{
    
    char *str = "helllo\n";
    char buffer[BUFFER_SIZE];
    int tube[2];
    int b_read;
    int status;
    pid_t pid;


    int p = pipe(tube);
    if (p < 0)
    {
        printf("Error pipe creation in %s line:%d", __func__, __LINE__ - 3);
        return (1);
    }
    pid = fork();
    if (pid < 0)
    {
        printf("Error fork creation in %s line:%d", __func__, __LINE__ - 3);
        return (1);

    }
    if (pid == 0)
    {
        close(tube[0]);
        ft_putstr_fd(NULL, tube[1]);
        close(tube[1]);
    }
    else
    {
        close(tube[1]);
        waitpid(pid, &status, 0);
        printf("voici status %d\n", WIFEXITED(status));
        if(!WIFEXITED(status))
        {
            printf("\tCheck null protection -> "TEST_NOK"\n");
            printf("\tft_putchar ->"TEST_NOK"\n");
            return (1);
        }
        b_read = read(tube[0], buffer, BUFFER_SIZE - 1);
        close(tube[0]);
        buffer[b_read] = '\0';
        if(!strncmp(buffer, str, b_read))
            printf("\tft_putchar ->"TEST_OK"\n");
        else
            printf("\tft_putchar ->"TEST_NOK"\n");
    }

    
    return (0);
}


// int main(void)
// {
//     char *str1;
//     char *str2;
//     char *s1 = "hello";
//     char *s2 = "hellob";
//     int r1;
//     int r2;
    
//     str1 = ft_strdup(s1);
//     if(!str1)
//     {
//         printf("Error allocation in %s ligne: %d\n", __func__, __LINE__ - 3);
//         return(1) ;
//     }
//     str2 = ft_strdup(s2);
//     if(!str2)
//     {
//         free(str1);
//         printf("Error allocation in %s line: %d\n", __func__, __LINE__);
//         return(1);
//     }
//     r1 = ft_strncmp(str1, str2, 10);
//     r2 = strncmp(str1, str2, 10);
//     if(r1 == r2)
//         printf("\toriginal fonction return: %d\n\tft output: %d\n\t-> "TEST_OK"\n",r2,r1);
//     else
//         printf("\toriginal output: %d\n\tft fonction output: %d\n\t-> "TEST_NOK"\n",r2,r1);
    
//     return (0);
// }