/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:18:20 by jtakahas          #+#    #+#             */
/*   Updated: 2023/09/28 20:33:31 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_print_uint(unsigned int nbr)
{
	int		len_nbr;
	char	*str_nbr;

	len_nbr = 0;
	str_nbr = ft_uitoa(nbr);
	len_nbr += ft_printstr(str_nbr);
	free(str_nbr);
	return (len_nbr);
}
