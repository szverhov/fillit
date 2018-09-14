/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:00:26 by vlvereta          #+#    #+#             */
/*   Updated: 2017/11/21 13:44:11 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		edge_finder(int fig_amount)
{
	int	edge;
	int	square;

	square = fig_amount * 4;
	while (!(edge = ft_sqrt(square)))
		square++;
	return (edge);
}

void	result_dot(char *result, int len)
{
	int i;

	i = 0;
	result[len] = '\0';
	while (i < len)
	{
		result[i] = '.';
		i++;
	}
}

void	add_wh(t_flist *a)
{
	int	i;
	int	temp_w;

	if (a)
	{
		if (!ft_strcmp("1100011", a->figure) || !ft_strcmp("11011", a->figure))
		{
			a->width = 3;
			a->height = 2;
			return ;
		}
		i = 1;
		temp_w = 1;
		while ((a->figure)[i])
		{
			if (((a->figure)[i] == '1' && (a->figure)[i - 1] == '1'))
				temp_w++;
			a->width = (temp_w > a->width ? temp_w : a->width);
			if ((a->figure)[i] == '0')
				temp_w = 1;
			if ((a->figure)[i] == '1' && (a->figure)[i - 1] == '0')
				(a->height)++;
			i++;
		}
	}
}

int		find_positions(t_flist *figures, int edge)
{
	int	temp;
	int positions;

	positions = 0;
	while (figures)
	{
		temp = (edge - (figures->width) + 1) * (edge - (figures->height) + 1);
		if (temp <= 0)
			return (0);
		figures->poss = temp;
		positions = positions + temp;
		figures = figures->next;
	}
	return (positions);
}

void	add_zero(char **figure)
{
	int		i;
	int		j;
	int		t;
	char	*temp;
	int		len;

	i = 0;
	t = 1;
	len = ft_strlen(*figure);
	temp = ft_strdup(*figure);
	if (ft_strequ(*figure, "10111"))
		t++;
	free(*figure);
	*figure = (char *)malloc(sizeof(char) * (len + t + 1));
	if (*figure)
	{
		j = 0;
		(*figure)[len + t] = '\0';
		while (i < t)
			(*figure)[i++] = '0';
		while (j < len)
			(*figure)[i++] = temp[j++];
	}
	free(temp);
}
