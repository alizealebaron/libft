/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ isalnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:26:59 by alebaron          #+#    #+#             */
/*   Updated: 2025/10/16 13:10:52 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1024);
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char c1= 'C';
// 	char c2= '@';
// 	char c3= '0';

// 	printf("Caractere \"%c\" : %d\n", c1, ft_isalnum(c1));
// 	printf("Caractere \"%c\" : %d\n", c2, ft_isalnum(c2));
// 	printf("Caractere \"%c\" : %d\n", c3, ft_isalnum(c3));
// }