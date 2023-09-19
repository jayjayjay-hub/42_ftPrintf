/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:18:20 by jtakahas          #+#    #+#             */
/*   Updated: 2023/09/05 15:53:21 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_print_uint(unsigned int nbr)
{
	int		length;
	char	*num_str;

	length = 0;
	if (nbr == 0)
		length += write(1, "0", 1);
	else
	{
		num_str = ft_uitoa(nbr);
		length += ft_printstr(num_str);
		free(num_str);
	}
	return (length);
}
