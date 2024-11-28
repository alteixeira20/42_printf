/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:59:22 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/28 16:31:09 by paalexan         ###   ########.fr       */
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

int	handle_char(const char *format, va_list args)
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

int	handle_string(const char *format, va_list args)
{
	int ret_ft = 0;

	if (strchr(format, 's')) // Handle %s
	{
		// Build argument list for multiple %s specifiers
		const char *s_args[10]; // Supports up to 10 strings for simplicity
        	int count = 0;

        	const char *p = format;
		while (*p)
        	{
            		if (*p == '%' && *(p + 1) == 's') // Find %s
            		{
                		s_args[count++] = va_arg(args, const char *);
                		p++; // Skip 's'
            		}
            		p++;
        	}

        	// Call ft_printf dynamically based on number of arguments
        	switch (count)
        	{
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
			default:
				ret_ft = ft_printf(format); // Fallback
				break;
       		}
	}
	return ret_ft;
}

int	handle_hex(const char *format, va_list args) {
	int ret = 0;

	if (strcmp(format, "%p") == 0) {
		void *ptr = va_arg(args, void *);
        	ret = ft_printf("%p", ptr); // Call ft_printf directly with the correct format
    	} else if (strcmp(format, "%x") == 0) {
        	unsigned int hex = va_arg(args, unsigned int);
        	ret = ft_printf("%x", hex); // Call ft_printf directly
    	} else if (strcmp(format, "%X") == 0) {
        	unsigned int hex = va_arg(args, unsigned int);
        	ret = ft_printf("%X", hex); // Call ft_printf directly
    	} else {
        	ret = ft_printf(format); // Default case
    	}

	fflush(stdout); // Ensure all output is flushed immediately
	return ret;
}
