/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binarysearch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 12:12:42 by vlvereta          #+#    #+#             */
/*   Updated: 2017/11/03 12:12:44 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_binarysearch(int tab[], int len, int number)
{
	int		start;
	int		half;
	int		end;

	start = 0;
	end = len - 1;
	while (start <= end)
	{
		half = start + (end - start) / 2;
		if (number == tab[half])
			return (1);
		else if (number < tab[half])
			end = half - 1;
		else
			start = half + 1;
	}
	return (0);
}
