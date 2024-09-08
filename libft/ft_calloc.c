/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctharawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:24:20 by ctharawi          #+#    #+#             */
/*   Updated: 2024/09/07 14:44:04 by ctharawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if ((SIZE_MAX <= size && SIZE_MAX <= nmemb)
		|| ((ssize_t)nmemb && (ssize_t)size < 0)
		|| (ssize_t)nmemb * (ssize_t)size < 0)
		return (NULL);
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (ptr);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
