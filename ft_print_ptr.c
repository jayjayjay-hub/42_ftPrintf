/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:17:34 by jtakahas          #+#    #+#             */
/*   Updated: 2023/09/28 20:32:06 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_lenptr(uintptr_t address_nbr)
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
		if (address_nbr <= 9)
			ft_putchar_fd((address_nbr + '0'), 1);
		else
			ft_putchar_fd((address_nbr - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	length;

	length = 0;
	length += (int)write(1, "0x", 2);
	if (!ptr)
		length += (int)write(1, "0", 1);
	else
	{
		ft_to_hex(ptr);
		length += ft_lenptr(ptr);
	}
	return (length);
}

//https://dlrecord.hatenablog.com/entry/2020/05/31/181817
