/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_prototypes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:11:46 by paalexan          #+#    #+#             */
/*   Updated: 2024/12/05 17:01:39 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	run_test_numbers(const char *test_name, const char *format, ...)
{
	va_list	args;
	int	ret_ori, ret_ft;

	printf("- %s:\n", test_name);

	// Test with printf
	printf("-- printf: ");
	fflush(stdout);
	va_start(args, format);
	ret_ori = vprintf(format, args); // Use vprintf for printf
	va_end(args);
	printf(" | Return Value: %d\n", ret_ori);

	// Test with ft_printf
	printf("-- ft_printf: ");
	fflush(stdout);
	va_start(args, format);

	if (strchr(format, '%') != NULL)
	{
		// Handle integer-related specifiers (%d, %i, %u)
		if (strchr(format, 'd') || strchr(format, 'i') || strchr(format, 'u'))
			ret_ft = handle_numbers(format, args);

		// Handle character-related specifiers (%c)
		else if (strchr(format, 'c'))
			ret_ft = handle_char(format, args);

		// Handle strings (%s)
		else if (strchr(format, 's'))
			ret_ft = handle_string(format, args);
        
		// Handle literal percent (%%)
		else if (strchr(format, '%'))
			ret_ft = ft_printf(format);

		// Handle hex-related specifiers (%x, %X, %p)
		else if (strchr(format, 'x') || strchr(format, 'X') || strchr(format, 'p'))
			ret_ft = handle_hex(format, args);
		// Default fallback
		else
			ret_ft = ft_printf(format);
	}
	else
		ret_ft = ft_printf(format); // No specifiers

	va_end(args);
	printf(" | Return Value: %d\n\n", ret_ft);

	fflush(stdout); // Ensure all output is flushed
}

void run_test_hex(const char *test_name, const char *format, ...) {
	va_list args;
	int ret_ori, ret_ft;

	printf("- %s:\n", test_name);

	// Test with printf
	printf("-- printf: ");
	fflush(stdout);
	va_start(args, format);
	ret_ori = vprintf(format, args);
	va_end(args);
	printf(" | Return Value: %d\n", ret_ori);

	// Test with ft_printf
	printf("-- ft_printf: ");
	fflush(stdout);
	va_start(args, format);
	ret_ft = ft_printf(format, va_arg(args, unsigned int)); // Forward the argument
	va_end(args);
	printf(" | Return Value: %d\n\n", ret_ft);
}

void	run_test_pointer(const char *test_name, const char *format, ...) {
	va_list args;
	int ret_ori, ret_ft;

	printf("- %s:\n", test_name);

	// Test with printf
	printf("-- printf: ");
	fflush(stdout);
	va_start(args, format);
	ret_ori = vprintf(format, args);
	va_end(args);
	printf(" | Return Value: %d\n", ret_ori);

	// Test with ft_printf
	printf("-- ft_printf: ");
	fflush(stdout);
	va_start(args, format);
	ret_ft = ft_printf(format, va_arg(args, void *)); // Forward the pointer argument
	va_end(args);
	printf(" | Return Value: %d\n\n", ret_ft);
}

void	run_test_string(const char *test_name, const char *format, ...) {
	va_list	args;
    	int	ret_printf, ret_ft_printf;

	printf("- %s:\n", test_name);

	// Test with printf
	printf("-- printf: ");
	fflush(stdout);
	va_start(args, format);
	ret_printf = printf(format, args); // Directly pass the string argument
    	printf(" | Return Value: %d\n", ret_printf);

	// Test with ft_printf
	printf("-- ft_printf: ");
	fflush(stdout);
	va_start(args, format);
	ret_ft_printf = ft_printf(format, args); // Directly pass the string argument
	va_end(args);
	printf(" | Return Value: %d\n\n", ret_ft_printf);
}
