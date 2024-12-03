/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:48:35 by paalexan          #+#    #+#             */
/*   Updated: 2024/12/03 18:21:06 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Initialize Structs
static void	ft_init_struct(t_parser *info, t_padding *pad)
{
	info->flag_minus = 0;
	info->flag_zero = 0;
	info->flag_plus = 0;
	info->flag_space = 0;
	info->flag_hash = 0;
	info->width = 0;
	info->precision = -1;
	info->specifier = 0;
	pad->zeros = 0;
	pad->padding = 0;
}

// Process Format
static int	pft(const char **form, va_list args, t_parser *info, t_padding *pad)
{
	int		pc;

	pc = 0;
	ft_init_struct(info, pad);
	if (ft_parser(form, info))
	{
		if (info->specifier == 'd' || info->specifier == 'i')
			pc += ft_printf_numbers(va_arg(args, int), info, pad);
		else if (info->specifier == 'u')
			pc += ft_printf_numbers(va_arg(args, unsigned int), info, pad);
		else if (info->specifier == '%')
			pc += ft_putchar_pf('%');
		else if (info->specifier == 'c')
			pc += ft_printf_char((char)va_arg(args, int), info, pad);
		else if (info->specifier == 's')
			pc += ft_printf_strings(va_arg(args, const char *), info, pad);
		else if (info->specifier == 'p')
			pc += ft_printf_p(va_arg(args, void *));
		else if (info->specifier == 'x' || info->specifier == 'X')
			pc += ft_printf_x(va_arg(args, unsigned long), info, pad);
	}
	return (pc);
}

int	ft_printf(const char *format, ...)
{
	int			pc;
	va_list		args;
	t_parser	info;
	t_padding	pad;

	pc = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			pc += pft(&format, args, &info, &pad);
		else
		{
			pc += ft_putchar_pf(*format);
			format++;
		}
	}
	va_end(args);
	return (pc);
}
