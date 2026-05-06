// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_putchar_assert.c                                :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2026/05/05 16:24:20 by cebouhad          #+#    #+#             */
// /*   Updated: 2026/05/05 23:23:12 by cdric.b          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "assertion.h"

// void * read_output(void *arg)
// {
//     int b_read;
//     char buffer[1];
//     int fd;

//     fd = *((int *)arg);

//     b_read = 0;
//     while ((b_read = read(fd, buffer, 1)) > 0)
//     {
//         assert(buffer[0] == 'A');
//         printf("char : %c\n", buffer[0]);
//     }
//     return (NULL);
// }


// void ft_putchar_assert(void)
// {
//     char b[1];
//     char c;
//     int i;

//     c = 'A';
//     pthread_t t;
//     i = 0;
//     int fd = dup(STDOUT_FILENO);
//     pthread_create(&t, NULL, read_output, &fd);
//     while (i < 10)
//     {
//         write(fd, "A", 1);
//         i++;
//     }
    
//     ft_putchar_fd(c, STDOUT_FILENO);
//     pthread_join(t, NULL);
    
//     assert(c == b[0]);
// }