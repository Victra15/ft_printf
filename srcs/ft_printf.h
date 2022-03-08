/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:22:06 by yolee             #+#    #+#             */
/*   Updated: 2022/03/01 23:42:06 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
char	*ft_uitoa_hex(unsigned int n);
char	*ft_uitoa(unsigned int n);
char	*ft_ptoa(unsigned long long n);
void	parse_char(va_list *ap, size_t *print_len);
void	parse_str(va_list *ap, size_t *print_len);
void	parse_ptr(va_list *ap, size_t *print_len);
void	parse_decimal(va_list *ap, size_t *print_len);
void	parse_unsigned_decimal(va_list *ap, size_t *print_len);
void	parse_lower_hexadecimal(va_list *ap, size_t *print_len);
void	parse_upper_hexadecimal(va_list *ap, size_t *print_len);
void	parse_percent(size_t *print_len);

#endif