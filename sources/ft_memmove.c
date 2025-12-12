/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:29:31 by alebaron          #+#    #+#             */
/*   Updated: 2025/10/21 14:40:37 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pdest;
	const unsigned char	*psrc ;

	pdest = dest;
	psrc = src;
	if (!pdest && !psrc)
		return (0);
	if (pdest > psrc)
	{
		while (n--)
			pdest[n] = psrc[n];
	}
	else
	{
		while (n--)
			*(pdest++) = *(psrc++);
	}
	return (dest);
}
