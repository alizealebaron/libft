/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:05:36 by alebaron          #+#    #+#             */
/*   Updated: 2025/10/16 13:10:59 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1024);
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char c1= 'C';
// 	char c2= '@';
// 	char c3= 'o';

// 	printf("Caractere \"%c\" : %d\n", c1, ft_isalpha(c1));
// 	printf("Caractere \"%c\" : %d\n", c2, ft_isalpha(c2));
// 	printf("Caractere \"%c\" : %d\n", c3, ft_isalpha(c3));
// }