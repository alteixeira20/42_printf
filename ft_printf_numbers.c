/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:57:01 by paalexan          #+#    #+#             */
/*   Updated: 2024/12/03 18:58:06 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_numbers(int num, t_parser *info, t_padding *pad)
{
    char *num_str;
    int len;
    int printed_chars;

	if (info->precision == 0 && num == 0)
	{
		// Only print padding spaces if precision is 0 and the value is 0
		ft_calc_numeric_pad(info, 0, num, pad);
		return ft_print_pad(pad->padding, ' ');
	}
    if (info->specifier == 'u')
        num_str = ft_utoa_pf((unsigned)num);
    else
        num_str = ft_itoa_pf(num);
    if (!num_str)
        return (-1);

    len = ft_strlen_pf(num_str);
    printed_chars = 0;

    // Calculate padding and zeros
    ft_calc_numeric_pad(info, len, num, pad);

    if (info->flag_minus) // Left-aligned case
    {
        printed_chars += ft_handle_sign(info, num);       // Handle sign first
        printed_chars += ft_print_pad(pad->zeros, '0');  // Add zero padding
        printed_chars += ft_putnstr_pf(num_str, len);    // Print the number
        printed_chars += ft_print_pad(pad->padding, ' '); // Add spaces after
    }
    else // Right-aligned case
    {
        printed_chars += ft_print_pad(pad->padding, ' '); // Add spaces before
        printed_chars += ft_handle_sign(info, num);       // Handle sign after padding
        printed_chars += ft_print_pad(pad->zeros, '0');  // Add zero padding
        printed_chars += ft_putnstr_pf(num_str, len);    // Print the number
    }

    free(num_str);
    return (printed_chars);
}
