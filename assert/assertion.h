/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:21:02 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/01 14:45:20 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSERTION_H
#define ASSERTION_H

#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include "../libft.h"

#define C_RED "\e[0;31;1m"
#define C_GREEN "\e[0;32;1m"
#define C_CYAN "\e[0;36;1m"
#define C_RESET "\e[0m"

#define TEST_START printf(C_CYAN"Start test %s\n"C_RESET, __func__)
#define TEST_END printf(C_GREEN"End test %s: OK!\n"C_RESET, __func__)


#endif