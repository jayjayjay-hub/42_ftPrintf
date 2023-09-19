/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:59:07 by jtakahas          #+#    #+#             */
/*   Updated: 2023/09/05 16:32:25 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_lenhex(unsigned int nbr)
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

static void	ft_to_hex(const char format, unsigned int nbr)
{
	if (nbr >= 16)
	{
		ft_to_hex(format, nbr / 16);
		ft_to_hex(format, nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd((nbr + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((nbr - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((nbr - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(const char format, unsigned int nbr)
{
	if (nbr == 0)
		return (write(1, "0", 1));
	ft_to_hex(format, nbr);
	return (ft_lenhex(nbr));
}
