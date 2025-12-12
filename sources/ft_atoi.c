/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:57:17 by alebaron          #+#    #+#             */
/*   Updated: 2025/10/18 13:02:13 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c);

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		ret_int;
	int		modif;

	i = 0;
	ret_int = 0;
	modif = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			modif = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
		ret_int = ret_int * 10 + (nptr[i++] - '0');
	return (ret_int * modif);
}

static int	ft_isspace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}
