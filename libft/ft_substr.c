/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctharawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:46:18 by ctharawi          #+#    #+#             */
/*   Updated: 2024/09/07 15:19:06 by ctharawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = ft_strlen(s);
	if (!s)
		return (0);
	if (i < start)
		len = 0;
	if ((i - start) < len)
		len = (i - start);
	ptr = (char *) malloc(sizeof(char ) * (len + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (len > i)
	{
		*(ptr + i) = *(s + (start + i));
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}
