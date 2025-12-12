/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:52:24 by alebaron          #+#    #+#             */
/*   Updated: 2025/10/23 11:51:14 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set_char(char const *set, char c);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (is_set_char(set, s1[start]))
		start++;
	while (is_set_char(set, s1[end]))
		end--;
	return (ft_substr(s1, start, (end - start + 1)));
}

static int	is_set_char(char const *set, char c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}
