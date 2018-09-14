/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:10:34 by vlvereta          #+#    #+#             */
/*   Updated: 2017/11/17 15:10:41 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_matrix(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
			if (matrix[i][j++] != '0')
				return (0);
		i++;
	}
	return (1);
}

char	**copy_matrix(char **matrix)
{
	int		height;
	char	**copy;

	height = 0;
	while (matrix[height])
		height++;
	copy = (char **)malloc(sizeof(char *) * (height + 1));
	if (copy)
	{
		copy[height] = NULL;
		while (height > 0)
		{
			--height;
			copy[height] = ft_strdup(matrix[height]);
			if (!copy[height])
			{
				matrix_free(copy);
				return (NULL);
			}
		}
	}
	return (copy);
}

char	**clean_matrix(char **matrix, int row)
{
	int	i;
	int	j;

	if (!matrix)
		return (NULL);
	j = 1;
	while (matrix[row][j])
	{
		if (matrix[row][j] == '1')
		{
			i = 0;
			while (matrix[i])
			{
				if (i != row && matrix[i][j] == '1')
				{
					ft_memset(matrix[i] + 1, '0', ft_strlen(matrix[i]) - 1);
					matrix[i][0] += 32;
				}
				i++;
			}
		}
		j++;
	}
	clean_figure(matrix, matrix[row][0]);
	return (matrix);
}

void	clean_figure(char **matrix, char c)
{
	int i;

	if (matrix)
	{
		i = 0;
		while (matrix[i])
		{
			if (matrix[i][0] == c || matrix[i][0] == c + 32)
				ft_memset(matrix[i], '0', ft_strlen(matrix[i]));
			i++;
		}
	}
}

void	matrix_free(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
	matrix = NULL;
}
