/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:59:22 by paalexan          #+#    #+#             */
/*   Updated: 2024/12/05 17:08:27 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	redirect_stdout_to_file(const char *filename)
{
	freopen(filename, "w", stdout);
}

// Helper function to restore stdout
void	restore_stdout()
{
	freopen("/dev/tty", "w", stdout); // Redirects stdout back to terminal
}

int	handle_numbers(const char *format, va_list args)
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

const char *truncate_if_needed(const char *str, const char *format) {
	if (!str || !strchr(format, '.')) return str;

	// Extract precision
	const char *dot = strchr(format, '.');
	int precision = atoi(dot + 1);

	if (precision < 0 || precision >= (int)strlen(str)) return str;

	static char truncated[1024];
	strncpy(truncated, str, precision);
	truncated[precision] = '\0';
	return truncated;
}

int	handle_char(const char *format, va_list args)
{
	int ret_ft = 0;
	int count = 0; // Count of valid %c specifiers
	const char *ptr = format;

    	// Parse the format string to identify and count valid %c specifiers
	while (*ptr)
	{
		if (*ptr == '%' && *(ptr + 1) == '%') // Handle %%
		{
            		ret_ft += ft_printf("%%");
            		ptr += 2; // Skip both % characters
        	}
        	else if (*ptr == '%' && *(ptr + 1) == 'c') // Handle %c
       		{
            		count++;
            		ptr += 2; // Skip the % and the 'c'
        	}
        	else
        		ptr++;
	}

	// If there are %c specifiers, process them
	if (count > 0)
	{
		char args_array[count]; // Array to hold %c arguments
		for (int i = 0; i < count; i++)
        	{
            		args_array[i] = (char)va_arg(args, int);
        	}

        	// Use ft_printf dynamically for up to 5 %c specifiers
        	switch (count)
        	{
           		case 1:
                		ret_ft += ft_printf(format, args_array[0]);
                		break;
            		case 2:
                		ret_ft += ft_printf(format, args_array[0], args_array[1]);
                		break;
            		case 3:
                		ret_ft += ft_printf(format, args_array[0], args_array[1], args_array[2]);
                		break;
            		case 4:
                		ret_ft += ft_printf(format, args_array[0], args_array[1], args_array[2], args_array[3]);
                		break;
            		case 5:
                		ret_ft += ft_printf(format, args_array[0], args_array[1], args_array[2], args_array[3], args_array[4]);
                		break;
            		default:
                		ret_ft += ft_printf(format);
                		break;
		}
	}
	else
 	       ret_ft += ft_printf(format);

	return ret_ft;
}

int	handle_string(const char *format, va_list args) {
	int	ret_ft = 0;
	int	count = 0;
	const char *s_args[10];
	const char *p = format;

	// Scan for %s and % s specifiers
	while (*p) {
		if (*p == '%' && (*(p + 1) == 's' || (*(p + 1) == ' ' && *(p + 2) == 's'))) {
			const char *arg = va_arg(args, const char *);
            		if (count < 10) {
                		if (arg == NULL) {
                    			if (strchr(format, '.'))
                        			s_args[count] = "";
                    			else
                        			s_args[count] = "(null)";
                   		 }
                	}
			else
                    		s_args[count] = truncate_if_needed(arg, format);
                	count++;
            	}
		p += (*(p + 1) == ' ') ? 2 : 1;
	}
	p++;

	// Call ft_printf with the appropriate arguments
	switch (count) {
        	case 1:
            		ret_ft = ft_printf(format, s_args[0]);
            		break;
        	case 2:
        		ret_ft = ft_printf(format, s_args[0], s_args[1]);
            		break;
        	case 3:
            		ret_ft = ft_printf(format, s_args[0], s_args[1], s_args[2]);
            		break;
        	case 4:
            		ret_ft = ft_printf(format, s_args[0], s_args[1], s_args[2], s_args[3]);
            		break;
        	case 5:
            		ret_ft = ft_printf(format, s_args[0], s_args[1], s_args[2], s_args[3], s_args[4]);
            		break;
        	default:
            		ret_ft = ft_printf(format);
            		break;
	}
	return ret_ft;
}

int	handle_hex(const char *format, va_list args) {
	int ret = 0;
	unsigned int hex;
	int width = 0, precision = -1;
	char prefix[3] = "";

	// Parse the format for width and precision
	const char *dot = strchr(format, '.');
	if (dot) precision = atoi(dot + 1);
	const char *percent = strchr(format, '%');
	if (percent) width = atoi(percent + 1);

	hex = va_arg(args, unsigned int);

	// Handle the `#` flag
	if (strchr(format, '#') && hex != 0) {
        	if (strchr(format, 'x')) strcpy(prefix, "0x");
        	else if (strchr(format, 'X')) strcpy(prefix, "0X");
    	}

	// Build the format string dynamically
	char buffer[50];
	if (precision >= 0) {
        	sprintf(buffer, "%%%s%d.%dx", strchr(format, '-') ? "-" : "", width, precision);
    	} else {
        	sprintf(buffer, "%%%s%dx", strchr(format, '-') ? "-" : "", width);
    	}

    	// Use the correct format for uppercase hex
    	if (strchr(format, 'X')) buffer[strlen(buffer) - 1] = 'X';

    	// Print with the prefix
    	if (hex == 0 && strchr(format, '#')) {
		ret = ft_printf("%x", hex); // No prefix for zero
    	} else {
        	ret = ft_printf("%s", prefix); // Add prefix
        	ret += ft_printf(buffer, hex); // Add formatted hex
    	}

	return ret;
}

int	handle_pointer(const char *format, va_list args) {
	void *ptr = va_arg(args, void *);
	int ret = 0;

	if (ptr == NULL) {
        	// Handle NULL pointer case
        	ret = ft_printf("(nil)");
    	} else {
        	// Forward the format and pointer directly to ft_printf
        	ret = ft_printf(format, ptr);
    	}
    	return ret;
}
