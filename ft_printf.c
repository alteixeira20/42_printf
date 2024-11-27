/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:48:35 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/27 23:07:18 by diogomordaça    ###   ########.fr       */
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
	char	*str;

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
			pc += ft_putchar_pf(va_arg(args, int));
		else if (info->specifier == 's')
		{
			str = va_arg(args, char *);
			if (!str)
				str = "(null)";
			ft_putstr_pf(str);
			pc += ft_strlen_pf(str);
		}
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
