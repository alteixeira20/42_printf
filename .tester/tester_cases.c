/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:17:34 by paalexan          #+#    #+#             */
/*   Updated: 2024/12/05 17:00:14 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	test_mandatory(void)
{
	printf("=== Mandatory Tests ===\n");

	// Test %d (Double)
	run_test_numbers("Double: Zero (%d)", "Double: %d", 0);
	run_test_numbers("Double: Positive", "Double: %d", 12345);
	run_test_numbers("Double: Negative", "Double: %d", -12345);
	run_test_numbers("Double: INT_MAX", "Double: %d", INT_MAX);
	run_test_numbers("Double: INT_MIN", "Double: %d", INT_MIN);

	// Test %i (Integer)
	run_test_numbers("Integer: Zero (%i)", "Integer: %i", 0);
	run_test_numbers("Integer: Positive (%i)", "Integer: %i", 12345);
	run_test_numbers("Integer: Negative (%i)", "Integer: %i", -12345);
	run_test_numbers("Integer: INT_MAX (%i)", "Integer: %i", INT_MAX);
	run_test_numbers("Integer: INT_MIN (%i)", "Integer: %i", INT_MIN);

	// Test %u
	run_test_numbers("Unsigned: Zero (%u)", "Unsigned: %u", 0);
	run_test_numbers("Unsigned: Positive (%u)", "Unsigned: %u", 12345);
	run_test_numbers("Unsigned: UINT_MAX (%u)", "Unsigned: %u", UINT_MAX);

	// Test %%
	run_test_string("Flag: %: (%%u)", "Double: %%u");
	run_test_string("Flag %: (u%%)", "Double: u%%");
	run_test_string("Flag %: (%%10)", "Double: %%10");
	run_test_string("Flag %: (100%%)", "Double: 100%%");

	// Test %c
	run_test_numbers("Char: (%c)", "Char: %c", 'A');
	run_test_numbers("Char: (%c%c%c)", "Char: %c%c%c", 'H', 'i', '!');
	run_test_numbers("Char print %: (%c)", "Char: %c", '%');
	run_test_numbers("Char print %%: (%c%c)", "Char: %c%c", '%', '%');
	run_test_numbers("Char with NULL: (%c)", "Char: %c", NULL);
		
	run_test_numbers("Char: (%c)", "Two Chars: %c%c", '%', '%');

	// Test %s
	run_test_string("String Single: %s", "String: %s", "World");
	//run_test_string("String Two: %s %s", "String: %s %s!", "Hello", "World");
	//run_test_string("String Three (%s %s %s)", "String: %s %s %s", "This", "is", "great!");
	run_test_string("String: Null (%s)", "String: %s", NULL);

	// Test %x
	run_test_hex("Hex Lowercase: %x", "Hex: %x", 255);
	run_test_hex("Hex Lowercase Zero: %x", "Hex: %x", 0);
	run_test_hex("Hex Lowercase UINT_MAX: %x", "Hex: %x", UINT_MAX);

	// Test %X
	run_test_hex("Hex Uppercase: %X", "Hex: %X", 255);
	run_test_hex("Hex Uppercase Zero: %X", "Hex: %X", 0);
	run_test_hex("Hex Uppercase UINT_MAX: %X", "Hex: %X", UINT_MAX);
}

// Bonus Tests
void	test_bonus(void)
{
	test_diu();
	test_strings();
	test_hex();
	test_pointer();
}

// Bonus Tests
void	test_diu(void)
{
	printf("=== Bonus Tests with Flags ===\n");

	// Tests for %d (Double)
	run_test_numbers("Double Supressed Zero: %.0d", "Double: %.0d", 0);
	run_test_numbers("Double Padded Zero: %5d", "Double: %5d", 0);
	run_test_numbers("Double Width: %10d", "Double: %10d", 42);
	run_test_numbers("Double Left Align Width: %-10d", "Double: %-10d", 42);
	run_test_numbers("Double Zero + Width: %010d", "Double:  %010d", 42);
	run_test_numbers("Double Precision: %.5d", "Double: %.5d", 42);
	run_test_numbers("Double Width + Precision: %10.5d", "Double: %10.5d", 42);
	run_test_numbers("Double Left Align with Width + Precision: %-10.5d", "Double: %-10.5d", 42);
	run_test_numbers("Double Plus Flag: %+d", "Double:  %+d", 42);
	run_test_numbers("Double Space Flag: % d", "Double: % d", 42);

	// Tests for %i (Integer)
	run_test_numbers("Integer Width: %10i", "Width: %10i", 42);
	run_test_numbers("Integer Left Align Width: %-10i", "Width: %-10i", 42);
	run_test_numbers("Integer Zero + Width %010i", "Width: %010i", 42);
	run_test_numbers("Integer Precision: %.5i", "Precision: %.5i", 42);
	run_test_numbers("Integer Width + Precision: %10.5i", "Width + Precision: %10.5i", 42);
	run_test_numbers("Integer Left Align with Width + Precision: %-10.5i", "Width + Precision: %-10.5i", 42);
	run_test_numbers("Integer Plus Flag: %+i", "Plus Flag: %+i", 42);
	run_test_numbers("Integer Space Flag: % i", "Space Flag: % i", 42);
	run_test_numbers("Integer Width with Negative Value: %7i", "Width: %7i", -14);
	run_test_numbers("Integer Width with Zero Value: %3i", "Width: %3i", 0);
	run_test_numbers("Integer Precision with Negative Value: %.6i", "Width: %.6i", -3);
	run_test_numbers("Integer Zero + Width with Zero Value: %03i", "Width: %03i", 0);		

	// Tests for %u (Unsigned)
	run_test_numbers("Unsigned Width: %10u", "Unsigned:  %10u", 42);
	run_test_numbers("Unsigned Left Align Width: %-10u", "Unsigned:  %-10u", 42);
	run_test_numbers("Unsigned Zero + Width: %010u", "Unsigned: 010u", 42);
	run_test_numbers("Unsigned Precision: %.5u", "Unsigned:  %.5u", 42);
	run_test_numbers("Unsigned Width + Precision: %10.5u", "Unsigned: %10.5u", 42);
	run_test_numbers("Unsigned Left Align with Width + Precision: %-10.5u", "Unsigned: %-10.5u", 42);
	run_test_numbers("Unsigned Plus Flag: %+u", "Unsigned: %+u", 42);
	run_test_numbers("Unsigned Space Flag: % u", "Unsigned: % u", 42);	
}

void	test_hex(void)
{
	printf("=== Hexadecimal Test Cases ===\n");

	// Alternative form (#)
	run_test_hex("Hex Lowercase with #: %#x", "Hex: %#x", 255);
	run_test_hex("Hex Uppercase with #: %#X", "Hex: %#X", 255);
	run_test_hex("Hex Zero with #: %#x", "Hex: %#x", 0);

	// Mixed Width and Precision
	run_test_hex("Hex Width + Precision: %10.5x", "Hex: %10.5x", 1234);
	run_test_hex("Hex Width + Precision Zero: %10.5x", "Hex: %10.5x", 0);
	run_test_hex("Hex Left Align + Precision: %-10.5x", "Hex: %-10.5x", 1234);

// Edge Cases
	run_test_hex("Hex Negative: %x", "Hex: %x", -1); // Check implementation behavior
}

void	test_strings(void)
{
	// Width Tests
	run_test_string("String Width: %10s", "String: %10s", "Hello");
	run_test_string("String Left Align: %-10s", "String: %-10s", "Hello");
	run_test_string("String Width with NULL: %10s", "String: %10s", NULL);
	run_test_string("String Left Align with NULL: %-10s", "String: %-10s", NULL);

	// Precision Tests
	run_test_string("String Precision: %.5s", "String: %.5s", "Hello World");
	run_test_string("String Zero Precision: %.0s", "String: %.0s", "Hello World");
	run_test_string("String Zero Precision with NULL: %.0s", "String: %.0s", NULL);

	// Width + Precision Tests
	run_test_string("String Width + Precision: %10.5s", "String: %10.5s", "Hello World");
	run_test_string("String Left Align + Precision: %-10.5s", "String: %-10.5s", "Hello World");

	// Edge Cases
	run_test_string("String Empty: %s", "Empty String: %s", "");
	run_test_string("String Width with Empty String %10s", "String: %10s", "");
	run_test_string("String Precision with Empty String: %.5s", "String: %.5s", "");
	run_test_string("String Width + Precision with Empty String: %10.5s", "String: %10.5s", "");

	// Mixed Flags
	run_test_string("String Left Align + Precision: %-10.5s", "String: %-10.5s", "abcdefg");
	run_test_string("String Width + Precision: %10.5s", "String: %10.5s", "abcdefg");
	run_test_string("String Left Align: %-10s", "String: %-10s", "Hello World");
	run_test_string("String Width: %10s", "String: %10s", "Hello World");

	// Space Flag
	run_test_string("String Space: % s", "String: % s", "hello");
	run_test_string("String with Width: % 10s", "String: % 10s", "hello");
	run_test_string("String with Precision: % .5s", "String: % .5s", "hello world");
	run_test_string("String Space with Empty: % 5s", "String: % 5s", "");
	run_test_string("String Space with NULL: % s", "String: % s", NULL);
}

void	test_pointer(void)
{
	printf("=== Pointer Test Cases ===\n");

	int x = 42;
	int *ptr = &x;

	// Valid pointer address
	run_test_pointer("Valid Pointer Address: %p", "Pointer: %p", ptr);

	// NULL pointer
	run_test_pointer("NULL Pointer: %p", "Pointer: %p", NULL);

	// Left-aligned pointer
	run_test_pointer("Left-Aligned Pointer: %-16p", "Pointer: %-16p", ptr);

	// Edge case: Pointer to zero memory address
	run_test_pointer("Pointer to Zero Address: %p", "Pointer: %p", (void *)0);

	// Edge case: Large memory address (simulated with a high value)
	run_test_pointer("Large Memory Address: %p", "Pointer: %p", (void *)0x7FFFFFFF);
	// Edge case: Negative pointer address (check for implementation behavior)
	run_test_pointer("Negative Pointer Address: %p", "Pointer: %p", (void *)-1);
}

