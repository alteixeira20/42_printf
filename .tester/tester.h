/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:57:34 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/28 15:57:40 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
#define TESTER_H

#include "../ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>

// Utility Functions
void redirect_stdout_to_file(const char *filename);
void restore_stdout(void);
int handle_numbers(const char *format, va_list args);
int handle_char(const char *format, va_list args);
int handle_string(const char *format, va_list args);
int handle_hex(const char *format, va_list args);

// Test Functions
void test_mandatory_diu(void);
void test_bonus_diu(void);
void test_hex(void);

#endif // TESTER_H

