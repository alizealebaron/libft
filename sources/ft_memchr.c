/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:06:10 by alebaron          #+#    #+#             */
/*   Updated: 2025/10/18 16:07:00 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s;
	unsigned char	tmp_c;
	size_t			cpt;

	tmp_s = (unsigned char *) s;
	tmp_c = (unsigned char ) c;
	cpt = 0;
	while (cpt < n)
	{
		if (tmp_s[cpt] == tmp_c)
			return ((void *) &tmp_s[cpt]);
		cpt++;
	}
	return (0);
}
