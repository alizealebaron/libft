/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:49:15 by alebaron          #+#    #+#             */
/*   Updated: 2025/10/20 14:17:37 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "limits.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp_s;
	char	to_find;
	char	*ret_value;

	tmp_s = (char *)s;
	ret_value = 0;
	to_find = (char) c;
	while (*tmp_s != '\0')
	{
		if (*tmp_s == to_find)
			ret_value = tmp_s;
		tmp_s++;
	}
	if (to_find == '\0' && *tmp_s == to_find)
		return (tmp_s);
	return (ret_value);
}
