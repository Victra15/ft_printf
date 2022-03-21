/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:22:06 by yolee             #+#    #+#             */
/*   Updated: 2022/03/21 18:56:54 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_pflag
{
	int	alter_form;
	int	zero_pad;
	int	left_adjust;
	int	add_blank;
	int	sign_display;
	int	width;
	int	precision;
}t_pflag;

int				ft_printf(const char *str, ...);
char			*ft_uitoa_hex(unsigned int n);
char			*ft_uitoa(unsigned int n);
char			*ft_ptoa(unsigned long long n);
char			*parse_char(va_list *ap, t_pflag *print_flags);
char			*parse_str(va_list *ap, t_pflag *print_flags);
char			*parse_ptr(va_list *ap, t_pflag *print_flags);
char			*parse_none(char *iter, t_pflag *print_flags);
char			*parse_decimal(va_list *ap,
					t_pflag *print_flags);
char			*parse_unsigned_decimal(va_list *ap,
					t_pflag *print_flags);
char			*parse_lower_hexadecimal(va_list *ap,
					t_pflag *print_flags);
char			*parse_upper_hexadecimal(va_list *ap,
					t_pflag *print_flags);
char			*parse_etc(char *iter, t_pflag *print_flags);
int				is_invalid_flag(const char parse_char,
					t_pflag *print_flags,
					int *print_len);
int				ft_isdigit_except_0(int c);
void			init_flags(t_pflag *print_flags);
unsigned int	ft_atoui_precision_iter(const char **str);
int				ft_atoi_width_iter(const char **str);
void			fill_with_blank(unsigned int idx, char *str);
void			fill_with_zero(unsigned int idx, char *str);
#endif