/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:22:06 by yolee             #+#    #+#             */
/*   Updated: 2022/05/22 12:19:00 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# define MAX_INT 2147483647
# define MAX_LONG_LONG 9223372036854775807
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_pflag
{
	int					alter_form;
	int					add_blank;
	int					sign_display;
	unsigned long long	precision;
	int					zero_pad;
	int					left_adjust;
	long long			width;
	int					error_flag;
}t_pflag;

int					ft_printf(const char *str, ...);
int					read_format_str(va_list *ap,
						const char **iter,
						t_pflag *print_flags,
						char **format_str);
void				format_to_print_iter(char **print_str,
						char **format_str,
						size_t len,
						size_t *f_str_len);
void				fill_padding(char **print_str, char fill_chr, size_t len);
int					is_invalid_flag(t_pflag *print_flags);
int					ft_isdigit_except_0(int c);
void				init_flags(t_pflag *print_flags);
unsigned long long	ft_atoui_precision_iter(const char **str);
long long			ft_atoi_width_iter(const char **str);
char				*parse_char(va_list *ap, t_pflag *print_flags);
void				null_chr_add(char *format_str,
						size_t *f_str_len,
						char parse_char);
char				*parse_str(va_list *ap, t_pflag *print_flags);
char				*parse_ptr(va_list *ap, t_pflag *print_flags);
char				*parse_decimal(va_list *ap, t_pflag *print_flags);
char				*parse_unsigned_decimal(va_list *ap, t_pflag *print_flags);
char				*parse_lower_hexadecimal(va_list *ap, t_pflag *print_flags);
char				*parse_upper_hexadecimal(va_list *ap, t_pflag *print_flags);
char				*parse_etc(char format_char, t_pflag *print_flags);

#endif