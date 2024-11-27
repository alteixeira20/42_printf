/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 22:33:35 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/27 19:09:55 by diogomordaça    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_parser
{
	int		flag_minus;
	int		flag_zero;
	int		flag_plus;
	int		flag_space;
	int		width;
	int		precision;
	char	specifier;
}	t_parser;

typedef struct s_padding
{
	int	zeros;
	int	padding;
}	t_padding;

int		ft_printf_numbers(int num, t_parser *info, t_padding *pad);
int		ft_printf(const char *format, ...);
int		ft_parser(const char **format, t_parser *info);
int		ft_putchar_pf(const char c);
int		ft_putstr_pf(const char *str);
int		ft_strlen_pf(const char *str);

char	*ft_itoa_pf(int n);
char	*ft_utoa_pf(unsigned int n);

#endif
