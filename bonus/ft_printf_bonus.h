/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:22:06 by yolee             #+#    #+#             */
/*   Updated: 2022/03/17 18:28:19 by yolee            ###   ########.fr       */
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
	int				alter_form;
	int				zero_pad;
	int				left_adjust;
	int				add_blank;
	int				sign_display;
	int				width;
	unsigned int	precision;
}t_pflag;

int				ft_printf(const char *str, ...);
char			*ft_uitoa_hex(unsigned int n);
char			*ft_uitoa(unsigned int n);
char			*ft_ptoa(unsigned long long n);
void			parse_char(va_list *ap, size_t *print_len, t_pflag print_flags);
void			parse_str(va_list *ap, size_t *print_len, t_pflag print_flags);
void			parse_ptr(va_list *ap, size_t *print_len, t_pflag print_flags);
void			parse_none(char *iter, size_t *print_len, t_pflag print_flags);
void			parse_decimal(va_list *ap,
					size_t *print_len,
					t_pflag print_flags);
void			parse_unsigned_decimal(va_list *ap,
					size_t *print_len,
					t_pflag print_flags);
void			parse_lower_hexadecimal(va_list *ap,
					size_t *print_len,
					t_pflag print_flags);
void			parse_upper_hexadecimal(va_list *ap,
					size_t *print_len,
					t_pflag print_flags);
void			parse_etc(char *iter, size_t *print_len, t_pflag print_flags);
int				ft_isdigit_except_0(int c);
void			init_flags(t_pflag *print_flags);
unsigned int	ft_atoui_precision_iter(const char **str);
int				ft_atoi_width_iter(const char **str);
#endif