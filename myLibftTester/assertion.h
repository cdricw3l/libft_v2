/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:21:02 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/04 17:38:05 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSERTION_H
#define ASSERTION_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <limits.h>
#include <stdarg.h>
#include "../libft.h"
#include <bsd/string.h>
 #include <string.h>


#define C_RED "\e[0;31;1m"
#define C_GREEN "\e[0;32;1m"
#define C_YBG "\e[0;43;1m"
#define C_BBG "\e[0;44;1m"
#define C_GBG "\e[2;42;1m"
#define C_PBG "\e[0;45;1m"
#define C_CYAN "\e[0;36;1m"
#define C_RESET "\e[0m"

#define TEST_STAR(f)    printf(C_CYAN"Start test %s\n"C_RESET, f);
#define TEST_OK(f)      printf(C_GREEN"Test %s: Ok!\n"C_RESET, f);
#define SEP printf(C_RED"///////////////////////////////////////////////////////////////////////////"C_RESET);
#define NL printf("\n");

//classification
void str_classification_assert(void);

//str
void ft_split_assert(void);
void ft_strchr_assert(void);
void ft_strrchr_assert(void);
void ft_striteri_assert(void);
void ft_strmapi_assert(void);
void ft_strjoin_assert(void);
void ft_strlen_assert(void);
void ft_strlcat_assert(void);
void ft_strnstr_assert(void);
void ft_strdup_assert(void);
void ft_strtrim_assert(void);
void ft_strncmp_assert(void);

//memory
void ft_calloc_assert(void);

//other
void ft_atoi_assert(void);
void ft_itoa_assert(void);



#endif