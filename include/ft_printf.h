/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:54:48 by jtakahas          #+#    #+#             */
/*   Updated: 2023/09/29 12:34:08 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_printstr(char *str);
int		ft_printnbr(int nbr);
char	*ft_itoa(int n);
int		ft_printchar(int c);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_uint(unsigned int nbr);
int		ft_print_hex(const char format, unsigned int nbr);

#endif
