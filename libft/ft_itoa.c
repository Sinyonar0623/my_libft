/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctharawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:14:55 by ctharawi          #+#    #+#             */
/*   Updated: 2024/09/01 17:46:01 by ctharawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_getsize(int n)
{
	long int	nbr;

	if (n == 0)
		return (1);
	if (n < 0)
	{
		nbr = -n;
		n = 1;
	}
	else
	{
		nbr = n;
		n = 0;
	}
	while (nbr != 0)
	{
		nbr = nbr / 10;
		n++;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	long int	nbr;
	size_t		i;
	size_t		j;

	nbr = n;
	j = ft_getsize(n);
	ptr = (char *)malloc((j + 1) * sizeof(char));
	if (!ptr)
		return (ptr);
	if (nbr < 0)
		nbr *= -1;
	else
		nbr = n;
	i = 0;
	while (i < j)
	{
		ptr[j - 1 - i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i++;
	}
	if (ptr[0] == 48 && j != 1)
		ptr[0] = '-';
	ptr[j] = 0;
	return (ptr);
}
/*
int	main(void)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = ft_itoa(0);
	while (tmp[i] != '\0')
	{
		printf("--[%ld] == %c\n", i, tmp[i]);
		i++;
	}
}
*/
