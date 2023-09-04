/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:54:48 by jtakahas          #+#    #+#             */
/*   Updated: 2023/09/04 20:04:37 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
// #include "./libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_printstr(char *str);
int	ft_printnbr(int	nbr);
char	*ft_itoa(int n);
int	ft_printchar(int c);

#endif