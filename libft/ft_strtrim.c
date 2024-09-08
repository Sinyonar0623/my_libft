/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctharawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:08:28 by ctharawi          #+#    #+#             */
/*   Updated: 2024/09/08 12:31:16 by ctharawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			j;
	size_t			i;
	char			*ptr;

	if (!s1)
		return (NULL);
	ptr = 0;
	if (s1 != 0 && set != 0)
	{
		i = 0;
		j = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
			j--;
		ptr = (char *)malloc(sizeof(char) * (j - i + 1));
		if (ptr)
			ft_strlcpy(ptr, &s1[i], j - i + 1);
	}
	return (ptr);
}
