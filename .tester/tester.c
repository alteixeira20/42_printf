#include "../ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>

// Helper function to redirect stdout to a file
void	redirect_stdout_to_file(const char *filename)
{
	freopen(filename, "w", stdout);
}

// Helper function to restore stdout
void	restore_stdout()
{
    freopen("/dev/tty", "w", stdout); // Redirects stdout back to terminal
}

int handle_numbers(const char *format, va_list args)
{
    int ret_ft = 0;

    if (strchr(format, 'd') || strchr(format, 'i')) // Handle %d or %i
    {
        int value = va_arg(args, int);
        ret_ft = ft_printf(format, value);
    }
    else if (strchr(format, 'u')) // Handle %u
    {
        unsigned int value = va_arg(args, unsigned int);
        ret_ft = ft_printf(format, value);
    }

    return ret_ft;
}

int handle_char(const char *format, va_list args)
{
    int ret_ft = 0;

    if (strchr(format, 'c')) // Handle %c
    {
        // Build argument list for multiple %c specifiers
        char c_args[10]; // Supports up to 10 chars for simplicity
        int count = 0;

        const char *p = format;
        while (*p)
        {
            if (*p == '%' && *(p + 1) == 'c') // Find %c
            {
                c_args[count++] = (char)va_arg(args, int);
                p++; // Skip 'c'
            }
            p++;
        }

        // Call ft_printf dynamically based on number of arguments
        switch (count)
        {
        case 1:
            ret_ft = ft_printf(format, c_args[0]);
            break;
        case 2:
            ret_ft = ft_printf(format, c_args[0], c_args[1]);
            break;
        case 3:
            ret_ft = ft_printf(format, c_args[0], c_args[1], c_args[2]);
            break;
        default:
            ret_ft = ft_printf(format); // Fallback
            break;
        }
    }

    return ret_ft;
}

// Helper function to run tests
void run_test(const char *test_name, const char *format, ...)
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
        {
            char *value = va_arg(args, char *);
            ret_ft = ft_printf(format, value);
        }

        // Handle literal percent (%%)
        else if (strchr(format, '%'))
            ret_ft = ft_printf(format);

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

// Mandatory Tests
void test_mandatory_diu(void) {
	printf("=== Mandatory Tests: %%d, %%i, %%u ===\n");

	// Test %d (Decimal)
	run_test("Decimal: Zero (%d)", "Decimal: %d", 0);
	run_test("Decimal: Supressed Zero (%.0d)", "Decimal: %.0d", 0);
	run_test("Decimal: Padded Zero (%5d)", "Decimal: %5d", 0);
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
}

// Bonus Tests
void test_bonus_diu(void)
{
	printf("=== Bonus Tests: %%d (Decimal), %%i (Integer), %%u (Unsigned) with Flags ===\n");

	// Test width for %d (Decimal)
	run_test("Width: %10d", "Width: %10d", 42);
	run_test("Width: %-10d", "Width: %-10d", 42);
	run_test("Width: %010d", "Width: %010d", 42);

	// Test width for %i (Integer)
	run_test("Width: %10i", "Width: %10i", 42);
	run_test("Width: %-10i", "Width: %-10i", 42);
	run_test("Width: %010i", "Width: %010i", 42);

	// Test precision for %d (Decimal)
	run_test("Precision: %.5d", "Precision: %.5d", 42);

	// Test precision for %i (Integer)
	run_test("Precision: %.5i", "Precision: %.5i", 42);

	// Test width + precision for %d (Decimal)
	run_test("Width + Precision: %10.5d", "Width + Precision: %10.5d", 42);
	run_test("Width + Precision: %-10.5d", "Width + Precision: %-10.5d", 42);

	// Test width + precision for %i (Integer)
	run_test("Width + Precision: %10.5i", "Width + Precision: %10.5i", 42);
	run_test("Width + Precision: %-10.5i", "Width + Precision: %-10.5i", 42);

	// Test flags for %d (Decimal)
	run_test("Plus Flag: %+d", "Plus Flag: %+d", 42);
	run_test("Space Flag: % d", "Space Flag: % d", 42);

	// Test flags for %i (Integer)
	run_test("Plus Flag: %+i", "Plus Flag: %+i", 42);
	run_test("Space Flag: % i", "Space Flag: % i", 42);
}

// Main Function
int	main(void)
{
	// Redirect stdout to results.txt
	redirect_stdout_to_file("results.txt");

	// Run Mandatory Tests
	test_mandatory_diu();

	// Run Bonus Tests
	test_bonus_diu();

	// Restore stdout to terminal
	restore_stdout();

	return (0);
}

