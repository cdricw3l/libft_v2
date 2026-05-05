/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:21:02 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/05 17:12:12 by cebouhad         ###   ########.fr       */
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
#ifdef _unix_
    #include <bsd/string.h>
#endif
#include <string.h>


#define C_RED "\e[0;31;1m"
#define C_GREEN "\e[0;32;1m"
#define C_CYAN "\e[0;36;1m"
#define C_YBG "\e[0;43;1m" //yellow bg
#define C_BBG "\e[0;44;1m" // blue bg
#define C_GBG "\e[2;42;1m" //green bg
#define C_PBG "\e[0;45;1m" //purple bg
#define C_RESET "\e[0m"

#define TEST_STAR(f)        printf(C_CYAN"Start test %s\n"C_RESET, f);
#define TEST_END(f)         printf(C_GREEN"Test %s: Ok!\n"C_RESET, f);
#define EMPTY_STR           "\e[4;35;1m""empty string""\e[0m"
#define NULL_STR           "\e[4;31;1m""NULL or nil""\e[0m"
#define TEST_OK             C_GREEN" Ok! "C_RESET
#define TEST_NOK            C_RED" NOk! "C_RESET
#define NOK                 0
#define OK                  1
#define SEP                 printf(C_RED"///////////////////////////////////////////////////////////////////////////"C_RESET);
#define NL                  printf("\n");

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
void ft_substr_assert(void);

//memory
void ft_calloc_assert(void);

//other
void ft_atoi_assert(void);
void ft_itoa_assert(void);

void ft_tolower_assert(void);
void ft_toupper_assert(void);
void ft_putchar_assert(void);

#endif