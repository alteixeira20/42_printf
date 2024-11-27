/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:37:12 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/26 20:58:56 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_pad(int len, char c)
{
	while (len > 0)
	{
		ft_putchar_pf(c);
		len--;
	}
}

static int	ft_handle_nb(t_parser *info, char *num_str, int len, t_padding *pad)
{
	int	printed_chars;

	printed_chars = 0;
	if (!(info->precision == 0 && num_str[0] == '0'))
	{
		ft_putstr_pf(num_str);
		printed_chars += len;
	}
	if (info->flag_minus && pad->padding > 0)
	{
		ft_print_pad(pad->padding, ' ');
		printed_chars += pad->padding;
	}
	return (printed_chars);
}

static int	ft_handle_sign_and_pad(t_parser *info, int num, t_padding *pad)
{
	int	printed_chars;

	printed_chars = 0;
	if (info->flag_minus == 0 && pad->padding > 0)
	{
		if (info->flag_zero == 1 && info->precision == -1)
		{
			ft_print_pad(pad->padding, '0');
			printed_chars += pad->padding;
		}
		else
		{
			ft_print_pad(pad->padding, ' ');
			printed_chars += pad->padding;
		}
	}
	if (info->specifier != 'u')
	{
		if (num >= 0 && info->flag_plus == 1)
			printed_chars += ft_putchar_pf('+');
		else if (num >= 0 && info->flag_space == 1)
			printed_chars += ft_putchar_pf(' ');
	}
	return (printed_chars);
}

static void	ft_calc_pad(t_parser *info, int len, int num, t_padding *pad)
{
	pad->zeros = 0;
	if (info->precision > len)
		pad->zeros = info->precision - len;
	if (info->precision == 0 && num == 0)
		len = 0;
	pad->padding = info->width - (len + pad->zeros);
	if ((info->flag_plus || info->flag_space) && num >= 0)
		(pad->padding)--;
}

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
