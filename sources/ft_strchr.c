/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:00:24 by alebaron          #+#    #+#             */
/*   Updated: 2025/10/20 16:07:03 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp_s;
	char	to_find;

	tmp_s = (char *)s;
	to_find = (char) c;
	while (*tmp_s != '\0')
	{
		if (*tmp_s == to_find)
			return (tmp_s);
		tmp_s++;
	}
	if (to_find == '\0' && *tmp_s == to_find)
		return (tmp_s);
	return (NULL);
}
