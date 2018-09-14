/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:31:30 by vlvereta          #+#    #+#             */
/*   Updated: 2017/11/17 16:31:33 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**matrix_create(t_flist *figures, int edge)
{
	int		height;
	char	**matrix;

	matrix = NULL;
	if ((height = find_positions(figures, edge)))
	{
		matrix = (char **)malloc(sizeof(char *) * (height + 1));
		if (matrix)
		{
			matrix[height] = NULL;
			if (matrix_to_zero(matrix, height, ft_power(edge) + 1))
				write_matrix(matrix, edge, figures);
		}
	}
	return (matrix);
}

char	**matrix_to_zero(char **matrix, int height, int len)
{
	int	i;
	int j;

	i = 0;
	while (i < height)
	{
		matrix[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (matrix[i])
		{
			j = 0;
			matrix[i][len] = '\0';
			while (j < len)
				matrix[i][j++] = '0';
		}
		else
			matrix_free(matrix);
		i++;
	}
	return (matrix);
}

void	write_matrix(char **matrix, int edge, t_flist *figures)
{
	int		i;
	int		row;
	int		tmp;
	char	letter;

	row = 0;
	letter = 'A';
	while (figures)
	{
		i = 0;
		tmp = figures->poss;
		if (ft_strequ(figures->figure, "100010011") ||
			ft_strequ(figures->figure, "10111") ||
			ft_strequ(figures->figure, "10011001") ||
			ft_strequ(figures->figure, "11011") ||
			ft_strequ(figures->figure, "100111") ||
			ft_strequ(figures->figure, "100110001") ||
			ft_strequ(figures->figure, "10111"))
			add_zero(&(figures->figure));
		write_poss(matrix, row, edge, figures);
		while (i++ < tmp)
			matrix[row++][0] = letter;
		letter++;
		figures = figures->next;
	}
}

void	write_poss(char **matrix, int row, int edge, t_flist *f)
{
	int	start;

	start = 1;
	while ((f->poss)--)
	{
		if ((start - 1) % edge > edge - f->width)
			while ((start - 1) % edge)
				start++;
		write_poss_row(&(matrix[row]), start, edge, f->figure);
		row++;
		start++;
	}
}

void	write_poss_row(char **m_row, int start, int edge, char *f)
{
	int i;
	int j;

	j = 0;
	i = start;
	while (f[j])
	{
		if (!((i - 1) % edge))
		{
			while (j % 4)
				j++;
			i += (start - 1) % edge;
		}
		else if (j != 0 && !(j % 4))
		{
			while ((i - 1) % edge)
				i++;
			i += (start - 1) % edge;
		}
		(*m_row)[i++] = f[j++];
	}
}
