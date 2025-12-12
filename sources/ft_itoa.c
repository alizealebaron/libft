/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:58:49 by alebaron          #+#    #+#             */
/*   Updated: 2025/10/23 16:52:44 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

int		calc_mem(int n);
void	make_itoa(char *itoa, long int nb, int len);

char	*ft_itoa(int n)
{
	char		*itoa;
	long int	nb;
	int			len;

	len = calc_mem(n) + 1;
	itoa = malloc(sizeof(char) * (len));
	if (!itoa)
		return (NULL);
	nb = n;
	make_itoa(itoa, nb, len);
	return (itoa);
}

void	make_itoa(char *itoa, long int nb, int len)
{
	itoa[--len] = '\0';
	if (nb < 0)
	{
		nb = -nb;
		itoa[0] = '-';
	}
	while (nb % 10 != nb)
	{
		itoa[--len] = (char)('0' + nb % 10);
		nb = nb / 10;
	}
	itoa[--len] = (char)('0' + nb);
}

int	calc_mem(int n)
{
	long int	j;
	int			nbchar;

	j = 10;
	nbchar = 0;
	if (n < 0)
	{
		nbchar++;
	}
	while (n % j != n)
	{
		nbchar++;
		j = j * 10;
	}
	return (nbchar + 1);
}
