/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 09:21:49 by vlvereta          #+#    #+#             */
/*   Updated: 2017/11/03 09:21:51 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_countwords(char const *s, int c)
{
	int		is_in;
	size_t	i;
	size_t	words;

	i = 0;
	is_in = 0;
	words = 0;
	if (s)
	{
		while (s[i])
		{
			if (!is_in && ((unsigned char *)s)[i] != c)
			{
				words++;
				is_in = 1;
			}
			if (s[i] == c)
				is_in = 0;
			i++;
		}
	}
	return (words);
}
