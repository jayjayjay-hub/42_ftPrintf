/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:17:34 by jtakahas          #+#    #+#             */
/*   Updated: 2023/09/05 16:07:08 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_lenptr(uintptr_t nbr)
{
	int	len;

	len = 0;
	while (nbr)
	{
		len++;
		nbr /= 16;
	}
	return (len);
}

static void	ft_to_hex(uintptr_t nbr)
{
	if (nbr >= 16)
	{
		ft_to_hex(nbr / 16);
		ft_to_hex(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd((nbr + '0'), 1);
		else
			ft_putchar_fd((nbr - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	length;

	length = 0;
	length += write(1, "0x", 2);
	if (!ptr)
		length += write(1, "0", 1);
	else
	{
		ft_to_hex(ptr);
		length += ft_lenptr(ptr);
	}
	return (length);
}

//https://dlrecord.hatenablog.com/entry/2020/05/31/181817