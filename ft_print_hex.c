/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:59:07 by jtakahas          #+#    #+#             */
/*   Updated: 2023/09/29 18:39:09 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_len_hex(unsigned int nbr)
{
	int	len_nbr;

	len_nbr = 0;
	while (nbr)
	{
		len_nbr++;
		nbr /= 16;
	}
	return (len_nbr);
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
		if (nbr < 10)
			ft_printchar(nbr + '0');
		else
		{
			if (format == 'x')
				ft_printchar(nbr - 10 + 'a');
			if (format == 'X')
				ft_printchar(nbr - 10 + 'A');
		}
	}
}

int	ft_print_hex(const char format, unsigned int nbr)
{
	if (nbr == 0)
		return (ft_printchar('0'));
	ft_to_hex(format, nbr);
	return (ft_len_hex(nbr));
}
