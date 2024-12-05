/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:57:34 by paalexan          #+#    #+#             */
/*   Updated: 2024/12/05 16:08:39 by paalexan         ###   ########.fr       */
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

// Output to results.txt
void	redirect_stdout_to_file(const char *filename);
void	restore_stdout(void);

// Run Test Prototypes
void	run_test_numbers(const char *test_name, const char *format, ...);
void    run_test_string(const char *test_name, const char *format, ...);
void	run_test_hex(const char *test_name, const char *format, ...);
void    run_test_pointer(const char *test_name, const char *format, ...);

// Handling Utils
int	handle_numbers(const char *format, va_list args);
int	handle_char(const char *format, va_list args);
int	handle_string(const char *format, va_list args);
int	handle_hex(const char *format, va_list args);
int	handle_pointer(const char *format, va_list args);

// Test Functions
void	test_mandatory(void);
void	test_bonus(void);
void	test_diu(void);
void	test_hex(void);
void	test_strings(void);
void	test_pointer(void);

#endif // TESTER_H

