/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctharawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:58:41 by ctharawi          #+#    #+#             */
/*   Updated: 2024/09/07 17:05:32 by ctharawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static char	**ft_freealloc(char **alloc)
{
	size_t	i;

	i = 0;
	while (*(alloc + i) != NULL)
	{
		free(*(alloc + i));
		i++;
	}
	free(alloc);
	return (NULL);
}

static char	**alloc(char **str, char *s, char c, size_t count)
{
	size_t	i;
	size_t	start;
	size_t	len;

	i = 0;
	start = 0;
	while (i < count)
	{
		len = 0;
		while (*(s + start) == c)
			start++;
		while (*(s + (start + len)) && *(s + (start + len)) != c)
			len++;
		*(str + i) = (char *)malloc(sizeof(char) * (len + 1));
		if (*(str + i) == NULL)
			return (ft_freealloc(str));
		ft_strlcpy(*(str + i), s + start, len + 1);
		start += len;
		i++;
	}
	*(str + i) = NULL;
	return (str);
}

char	**ft_split(const char *s, char c)
{
	size_t	count;
	char	**str;

	if (!s)
		return (NULL);
	count = count_word((char *)s, c);
	str = (char **)malloc(sizeof(char *) * (count + 1));
	if (str == NULL)
		return (NULL);
	str = alloc(str, (char *)s, c, count);
	return (str);
}
