/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:57:01 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/28 00:57:05 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_numbers(int num, t_parser *info, t_padding *pad)
{
	char	*num_str;
	int		len;
	int		printed_chars;

	if (info->specifier == 'u')
		num_str = ft_utoa_pf((unsigned int)num);
	else
		num_str = ft_itoa_pf(num);
	if (!num_str)
		return (-1);
	len = ft_strlen_pf(num_str);
	printed_chars = 0;
	ft_calc_pad(info, len, num, pad);
	printed_chars += ft_handle_sign_and_pad(info, num, pad);
	ft_print_pad(pad->zeros, '0');
	printed_chars += pad->zeros + ft_handle_nb(info, num_str, len, pad);
	free(num_str);
	return (printed_chars);
}
