/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:49:13 by alebaron          #+#    #+#             */
/*   Updated: 2025/10/23 17:16:53 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str_ret;

	str_ret = malloc (sizeof(char) * (ft_strlen(s) + 1));
	if (!str_ret)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		str_ret[i] = (*f)(i, s[i]);
		i++;
	}
	str_ret[i] = '\0';
	return (str_ret);
}
