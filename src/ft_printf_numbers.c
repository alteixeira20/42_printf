/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:57:01 by paalexan          #+#    #+#             */
/*   Updated: 2024/12/05 17:42:08 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pc_number(t_parser *info, char *num_str, t_padding *pad, int num)
{
	int	printed_chars;
	int	len_num;

	len_num = ft_strlen_pf(num_str);
	printed_chars = 0;
	if (info->flag_minus)
	{
		printed_chars += ft_handle_sign(info, num);
		printed_chars += ft_print_pad(pad->zeros, '0');
		printed_chars += ft_putnstr_pf(num_str, len_num);
		printed_chars += ft_print_pad(pad->padding, ' ');
	}
	else
	{
		printed_chars += ft_print_pad(pad->padding, ' ');
		printed_chars += ft_handle_sign(info, num);
		printed_chars += ft_print_pad(pad->zeros, '0');
		printed_chars += ft_putnstr_pf(num_str, len_num);
	}
	return (printed_chars);
}

int	ft_printf_numbers(int num, t_parser *info, t_padding *pad)
{
	char	*num_str;
	int		len;
	int		printed_chars;

	if (info->precision == 0 && num == 0)
	{
		ft_calc_numeric_pad(info, 0, num, pad);
		return (ft_print_pad(pad->padding, ' '));
	}
	if (info->specifier == 'u')
		num_str = ft_utoa_pf((unsigned)num);
	else
		num_str = ft_itoa_pf(num);
	if (!num_str)
		return (-1);
	len = ft_strlen_pf(num_str);
	printed_chars = 0;
	ft_calc_numeric_pad(info, len, num, pad);
	printed_chars += ft_pc_number(info, num_str, pad, num);
	free(num_str);
	return (printed_chars);
}
