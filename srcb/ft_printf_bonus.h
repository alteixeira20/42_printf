/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 22:33:35 by paalexan          #+#    #+#             */
/*   Updated: 2024/12/17 16:34:39 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_parser
{
	int		flag_minus;
	int		flag_zero;
	int		flag_plus;
	int		flag_space;
	int		flag_hash;
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
int		ft_printf_strings(const char *str, t_parser *info, t_padding *pad);
int		ft_printf_char(char c, t_parser *info, t_padding *pad);
int		ft_printf_p(void *ptr, t_parser *info, t_padding *pad);
int		ft_printf_x(unsigned int num, t_parser *info, t_padding *pad);
int		ft_printf(const char *format, ...);
int		ft_parser(const char **format, t_parser *info);
int		ft_putchar_pf(const char c);
int		ft_putstr_pf(const char *str);
int		ft_putnstr_pf(const char *str, int n);
int		ft_strlen_pf(const char *str);
char	*ft_strjoin_pf(char const *s1, char const *s2);
char	*ft_strdup_pf(const char *s);
char	*ft_itoa_pf(int n);
char	*ft_utoa_pf(unsigned long n);
char	*ft_itoa_base_pf(unsigned long num, int base, int uppercase);
char	*ft_ptr_to_hex(void *ptr);
int		ft_handle_hash(unsigned int num, t_parser *info);
int		ft_print_pad(int len, char c);
int		ft_handle_nb(t_parser *info, char *num_str, int len, t_padding *pad);
int		ft_handle_sign_and_pad(t_parser *info, int num, t_padding *pad);
int		ft_handle_str(t_parser *info, char *num_str, int len, t_padding *pad);
int		ft_handle_pad(t_parser *info, int num, t_padding *pad);
int		ft_handle_sign(t_parser *info, int num);
void	ft_calc_string_pad(t_parser *info, int len, t_padding *pad);
void	ft_calc_numeric_pad(t_parser *info, int len, int num, t_padding *pad);

#endif
