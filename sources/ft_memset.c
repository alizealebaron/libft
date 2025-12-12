/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:00:08 by alebaron          #+#    #+#             */
/*   Updated: 2025/10/16 13:11:14 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*p++ = c;
	return (s);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main()
// {
//     char str[] = "Lorem ipsum The leader at Cyllage Gym in Rock Pokémon.";
// 	printf("------------ Fonction libc ------------\n");
//     printf("\nBefore memset(): %s\n\n", str);
//     memset(str + 23, '*', 33);
//     printf("After memset(): %s\n\n", str);
// 	printf("------------ Fonction a moi ------------\n");
// 	char str1[] = "Lorem ipsum The leader at Cyllage Gym in Rock Pokémon.";
// 	printf("\nBefore memset(): %s\n\n", str1);
//     ft_memset(str1 + 23, '*', 33);
//     printf("After memset(): %s\n\n", str1);

//     return 0;
// }
