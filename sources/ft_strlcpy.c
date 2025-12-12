/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:30:52 by alebaron          #+#    #+#             */
/*   Updated: 2025/10/17 11:24:15 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen((char *)src);
	if (size < 1)
		return (len_src);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// int main ()
// {
// 	char	*src  = "Aqua Leader explored Bell Tower in Johto.";
// 	//size_t	tail  = ft_strlen(src);

// 	char	*dst  = "Model journeyed along Route 13";
// 	char	*dst1 = "Model journeyed along Route 13";

// 	printf("------------ Fonction libc  ------------\n");

// 	printf("Chaine source : %s\n", src);
// 	strlcpy(dst1, src, 5);
// 	printf("Chaine desti  : %s\n", dst);

// 	printf("------------ Fonction a moi ------------\n");

// 	printf("Chaine source : %s\n", src);
// 	ft_strlcpy(dst, src, 5);
// 	printf("Chaine desti  : %s\n", dst);
// }
