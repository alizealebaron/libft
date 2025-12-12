/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:07:43 by alebaron          #+#    #+#             */
/*   Updated: 2025/10/18 13:18:58 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ret_p;
	size_t			i;

	i = 0;
	ret_p = malloc (size * nmemb);
	if (ret_p == 0)
		return (0);
	ft_bzero (ret_p, nmemb * size);
	return (ret_p);
}
