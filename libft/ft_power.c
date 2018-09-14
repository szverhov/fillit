/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 10:39:04 by vlvereta          #+#    #+#             */
/*   Updated: 2017/11/03 10:39:05 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_power(int n)
{
	size_t	result;

	result = n * n;
	if (ft_sqrt(result) == n)
		return (result);
	else
		return (0);
}
