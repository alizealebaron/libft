/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:21:47 by alebaron          #+#    #+#             */
/*   Updated: 2025/10/16 13:11:04 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1024);
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char c1= '0';
// 	char c2= '@';
// 	char c3= 'o';

// 	printf("Caractere \"%c\" : %d\n", c1, ft_isdigit(c1));
// 	printf("Caractere \"%c\" : %d\n", c2, ft_isdigit(c2));
// 	printf("Caractere \"%c\" : %d\n", c3, ft_isdigit(c3));
// }