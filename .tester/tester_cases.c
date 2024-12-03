/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:17:34 by paalexan          #+#    #+#             */
/*   Updated: 2024/12/03 05:55:54 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

// Helper function to run tests
void	run_test(const char *test_name, const char *format, ...)
{
		va_list args;
		int ret_ori, ret_ft;

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

void run_test_string(const char *test_name, const char *format, const char *arg) {
    int ret_printf, ret_ft_printf;

    printf("- %s:\n", test_name);

    // Test with printf
    printf("-- printf: ");
    fflush(stdout);
    ret_printf = printf(format, arg); // Directly pass the string argument
    printf(" | Return Value: %d\n", ret_printf);

    // Test with ft_printf
    printf("-- ft_printf: ");
    fflush(stdout);
    ret_ft_printf = ft_printf(format, arg); // Directly pass the string argument
    printf(" | Return Value: %d\n\n", ret_ft_printf);
}

void	test_hex(void) {
		// Test %x (Lowercase Hex)
		printf("- Hexadecimal (lowercase): %%x:\n");
		printf("-- printf: ");
		int ret_printf = printf("Lowercase Hex: %x", 255);
		printf(" | Return Value: %d\n", ret_printf);

		printf("-- ft_printf: ");
		fflush(stdout); // Ensure output appears immediately
    	int ret_ft_printf = ft_printf("Lowercase Hex: %x", 255);
    	fflush(stdout); // Ensure ft_printf output aligns
    	printf(" | Return Value: %d\n\n", ret_ft_printf);

    	// Test %X (Uppercase Hex)
    	printf("- Hexadecimal (uppercase): %%X:\n");
    	printf("-- printf: ");
    	ret_printf = printf("Uppercase Hex: %X", 255);
    	printf(" | Return Value: %d\n", ret_printf);

    	printf("-- ft_printf: ");
    	fflush(stdout); // Ensure output appears immediately
    	ret_ft_printf = ft_printf("Uppercase Hex: %X", 255);
    	fflush(stdout); // Ensure ft_printf output aligns
    	printf(" | Return Value: %d\n\n", ret_ft_printf);

    	// Test %p (Pointer)
    	int x = 42;
		printf("- Pointer: Valid Address (%%p):\n");
		printf("-- printf: ");
		ret_printf = printf("Pointer: %p", &x);
		printf(" | Return Value: %d\n", ret_printf);
		printf("-- ft_printf: ");
    	fflush(stdout); // Ensure output appears immediately
    	ret_ft_printf = ft_printf("Pointer: %p", &x);
    	fflush(stdout); // Ensure ft_printf output aligns
    	printf(" | Return Value: %d\n", ret_ft_printf);

    	// Test %p (NULL Pointer)
    	printf("- Pointer: NULL (%%p):\n");
    	printf("-- printf: ");
    	ret_printf = printf("Pointer: %p", NULL);
    	printf(" | Return Value: %d\n", ret_printf);

    	printf("-- ft_printf: ");
    	fflush(stdout); // Ensure output appears immediately
    	ret_ft_printf = ft_printf("Pointer: %p", NULL);
    	fflush(stdout); // Ensure ft_printf output aligns
    	printf(" | Return Value: %d\n\n", ret_ft_printf);

    	// Test %x (Lowercase Hex, 0)
    	printf("- Hexadecimal (lowercase, 0): %%x:\n");
    	printf("-- printf: ");
    	ret_printf = printf("Lowercase Hex: %x", 0);
    	printf(" | Return Value: %d\n", ret_printf);

    	printf("-- ft_printf: ");
    	fflush(stdout); // Ensure output appears immediately
    	ret_ft_printf = ft_printf("Lowercase Hex: %x", 0);
    	fflush(stdout); // Ensure ft_printf output aligns
    	printf(" | Return Value: %d\n\n", ret_ft_printf);

    	// Test %X (Uppercase Hex, 0)
    	printf("- Hexadecimal (uppercase, 0): %%X:\n");
    	printf("-- printf: ");
    	ret_printf = printf("Uppercase Hex: %X", 0);
    	printf(" | Return Value: %d\n", ret_printf);

    	printf("-- ft_printf: ");
    	fflush(stdout); // Ensure output appears immediately
		ret_ft_printf = ft_printf("Uppercase Hex: %X", 0);
		fflush(stdout); // Ensure ft_printf output aligns
		printf(" | Return Value: %d\n\n", ret_ft_printf);
}

void test_strings_bonus(void)
{
    // Width Tests
    run_test_string("String: %10s", "Width: %10s", "Hello");
    run_test_string("String: %-10s", "Left Align: %-10s", "Hello");
    run_test_string("String: %10s", "Width with NULL: %10s", NULL);
    run_test_string("String: %-10s", "Left Align with NULL: %-10s", NULL);

    // Precision Tests
    run_test_string("String: %.5s", "Precision: %.5s", "Hello World");
    run_test_string("String: %.0s", "Zero Precision: %.0s", "Hello World");
    run_test_string("String: %.0s", "Zero Precision with NULL: %.0s", NULL);

    // Width + Precision Tests
    run_test_string("String: %10.5s", "Width + Precision: %10.5s", "Hello World");
    run_test_string("String: %-10.5s", "Left Align + Precision: %-10.5s", "Hello World");

    // Edge Cases
    run_test_string("String: %s", "Empty String: %s", "");
    run_test_string("String: %10s", "Width with Empty String: %10s", "");
    run_test_string("String: %.5s", "Precision with Empty String: %.5s", "");
    run_test_string("String: %10.5s", "Width + Precision with Empty String: %10.5s", "");

    // Mixed Flags
    run_test_string("String: %-10.5s", "Left Align + Precision: %-10.5s", "abcdefg");
    run_test_string("String: %10.5s", "Width + Precision: %10.5s", "abcdefg");
    run_test_string("String: %-10s", "Left Align: %-10s", "Hello World");
    run_test_string("String: %10s", "Width: %10s", "Hello World");

    // Space Flag
    run_test_string("String: % s", "Space: % s", "hello");
    run_test_string("String: % 10s", "Space with width: % 10s", "hello");
    run_test_string("String: % .5s", "Space with precision: % .5s", "hello world");
    run_test_string("String: % 5s", "Space with empty string: % 5s", "");
    run_test_string("String: % s", "Space with NULL: % s", NULL);
}
void	test_mandatory_diu(void) {
		printf("=== Mandatory Tests: %%d, %%i, %%u ===\n");

		// Test %d (Decimal)
		run_test("Decimal: Zero (%d)", "Decimal: %d", 0);
		run_test("Decimal: Positive", "Decimal: %d", 12345);
		run_test("Decimal: Negative", "Decimal: %d", -12345);
		run_test("Decimal: INT_MAX", "Decimal: %d", INT_MAX);
		run_test("Decimal: INT_MIN", "Decimal: %d", INT_MIN);

		// Test %i (Integer)
		run_test("Integer: Zero (%i)", "Integer: %i", 0);
		run_test("Integer: Positive (%i)", "Integer: %i", 12345);
		run_test("Integer: Negative (%i)", "Integer: %i", -12345);
		run_test("Integer: INT_MAX (%i)", "Integer: %i", INT_MAX);
		run_test("Integer: INT_MIN (%i)", "Integer: %i", INT_MIN);

		// Test %u
		run_test("Unsigned: Zero (%u)", "Unsigned: %u", 0);
		run_test("Unsigned: Positive (%u)", "Unsigned: %u", 12345);
		run_test("Unsigned: UINT_MAX (%u)", "Unsigned: %u", UINT_MAX);

		// Test %%
		run_test("Double %: (%%u)", "Double %%u");
		run_test("Double %: (u%%)", "Double u%%");
		run_test("Double %: (%%10)", "Double %%10");
		run_test("Double %: (100%%)", "Double 100%%");

		// Test %c
		run_test("Char: (%c)", "Single Char: %c", 'A');
		run_test("Char: (%c)", "Three Chars: %c%c%c", 'H', 'i', '!');
		run_test("Char: (%c)", "Char '%%': %c", '%');
		run_test("Char: (%c)", "Two Chars '%%': %c%c", '%', '%');

		// Test %s
		run_test("String: Single (%s)", "Hello %s!", "World");
		run_test("String: Two (%s %s)", "%s %s!", "Hello", "World");
		run_test("String: Three (%s %s %s)", "%s %s %s", "This", "is", "great!");
		run_test("String: Null (%s)", "This is %s", NULL);

		test_hex();
}

// Bonus Tests
void	test_bonus_diu(void)
{
		printf("=== Bonus Tests: %%d, %%i, %%u, %%x and %%X with Flags ===\n");

		// Tests for %d (Decimal)
		run_test("Decimal: Supressed Zero (%.0d)", "Decimal: %.0d", 0);
		run_test("Decimal: Padded Zero (%5d)", "Decimal: %5d", 0);
		run_test("Decimal: %10d", "Width: %10d", 42);
		run_test("Decimal: %-10d", "Width: %-10d", 42);
		run_test("Decimal: %010d", "Width: %010d", 42);
		run_test("Decimal: %.5d", "Precision: %.5d", 42);
		run_test("Decimal: %10.5d", "Width + Precision: %10.5d", 42);
		run_test("Decimal: %-10.5d", "Width + Precision: %-10.5d", 42);
		run_test("Decimal: %+d", "Plus Flag: %+d", 42);
		run_test("Decimal: % d", "Space Flag: % d", 42);

		// Tests for %i (Integer)
		run_test("Integer: %10i", "Width: %10i", 42);
		run_test("Integer: %-10i", "Width: %-10i", 42);
		run_test("Integer: %010i", "Width: %010i", 42);
		run_test("Integer: %.5i", "Precision: %.5i", 42);
		run_test("Integer: %10.5i", "Width + Precision: %10.5i", 42);
		run_test("Integer: %-10.5i", "Width + Precision: %-10.5i", 42);
		run_test("Integer: %+i", "Plus Flag: %+i", 42);
		run_test("Integer: % i", "Space Flag: % i", 42);
		run_test("Integer: %7i", "Width: %7i", 33);
		run_test("Integer: %7i", "Width: %7i", -14);
		run_test("Integer: %3i", "Width: %3i", 0);
		run_test("Integer: %.6i", "Width: %.6i", -3);
		run_test("Integer: %05i", "Width: %05i", 43);
		run_test("Integer: %03i", "Width: %03i", 0);		

		// Tests for %u (Unsigned)
		run_test("Unsigned: %10u", "Width: %10u", 42);
		run_test("Unsigned: %-10u", "Width: %-10u", 42);
		run_test("Unsigned: %010u", "Width: %010u", 42);
		run_test("Unsigned: %.5u", "Precision: %.5u", 42);
		run_test("Unsigned: %10.5u", "Width + Precision: %10.5u", 42);
		run_test("Unsigned: %-10.5u", "Width + Precision: %-10.5u", 42);
		run_test("Unsigned: %+u", "Plus Flag: %+u", 42);
		run_test("Unsigned: % u", "Space Flag: % u", 42);

		// Tests for %x
		run_test("Hex Lower: %10x", "Width: %10x", 42);
		run_test("Hex Lower: %.5x", "Precision: %.5x", 42);
		run_test("Hex Lower: %10.5x", "Width + Precision: %10.5x", 42);
		
		// Test for %X
		run_test("Hex Upper: %10X", "Width: %10X", 42);
		run_test("Hex Upper: %.5X", "Precision: %.5X", 42);
		run_test("Hex Upper: %10.5X", "Width + Precision: %10.5X", 42);

		// Test for %#X 
		run_test("Hex Upper: %#10X", "Width: %#10X", 42);
		run_test("Hex Upper: %#.5X", "Precision: %#.5X", 42);
		run_test("Hex Upper: %#10.5X", "Width + Precision: %#10.5X", 42);

		// Test for %#x 
		run_test("Hex Lower: %#10x", "Width: %#10x", 42);
		run_test("Hex Lower: %#.5x", "Precision: %#.5x", 42);
		run_test("Hex Lower: %#10.5x", "Width + Precision: %#10.5x", 42);

		test_strings_bonus();
}
