/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:17:34 by jtakahas          #+#    #+#             */
/*   Updated: 2023/09/29 12:30:59 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_len_ptr(uintptr_t address_nbr)
{
	int	len;

	len = 0;
	while (address_nbr)
	{
		len++;
		address_nbr /= 16;
	}
	return (len);
}

static void	ft_to_hex(uintptr_t address_nbr)
{
	if (address_nbr >= 16)
	{
		ft_to_hex(address_nbr / 16);
		ft_to_hex(address_nbr % 16);
	}
	else
	{
		if (address_nbr < 10)
			ft_printchar(address_nbr + '0');
		else
			ft_printchar(address_nbr - 10 + 'a');
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	length;

	length = 0;
	length += ft_printstr("0x");
	if (!ptr)
		length += ft_printchar('0');
	else
	{
		ft_to_hex((uintptr_t)ptr);
		length += ft_len_ptr((uintptr_t)ptr);
	}
	return (length);
}

//https://dlrecord.hatenablog.com/entry/2020/05/31/181817
