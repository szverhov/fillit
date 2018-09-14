/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:20:38 by vlvereta          #+#    #+#             */
/*   Updated: 2017/11/17 13:21:05 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char *argv[])
{
	int		edge;
	int		fig_amount;
	t_flist	*figures;

	figures = NULL;
	if (argc != 2)
	{
		ft_putstr("Usage: ./fillit source_file\n");
		exit(0);
	}
	fig_amount = check_file(argv[1], &figures);
	if (!fig_amount)
	{
		ft_putstr("error\n");
		exit(0);
	}
	edge = edge_finder(fig_amount);
	data_creator(figures, edge);
	return (0);
}

void	data_creator(t_flist *figures, int edge)
{
	int		square_len;
	char	*result;
	char	**matrix;

	square_len = ft_power(edge);
	result = (char *)malloc(sizeof(char) * (square_len + 1));
	if (result)
	{
		result_dot(result, square_len);
		matrix = matrix_create(figures, edge);
		if (matrix && square_create(matrix, result, 'A'))
		{
			lst_free(&figures);
			print_result(result, edge);
		}
		else
			data_creator(figures, ++edge);
		free(result);
	}
}

char	*square_create(char **matrix, char *result, char letter)
{
	int	row;

	if (matrix)
	{
		if (check_matrix(matrix))
		{
			matrix_free(matrix);
			return (result);
		}
		row = 0;
		while (matrix[row])
		{
			if (matrix[row][0] == letter &&
	square_create(clean_matrix(copy_matrix(matrix), row), result, letter + 1))
				return (write_figure(matrix, result, matrix[row]));
			row++;
		}
		matrix_free(matrix);
	}
	return (NULL);
}

char	*write_figure(char **matrix, char *result, char *row)
{
	int	i;

	if (row && result)
	{
		i = 0;
		while (row[i])
		{
			if (row[i] == '1')
				result[i - 1] = row[0];
			i++;
		}
	}
	matrix_free(matrix);
	return (result);
}

void	print_result(char *result, int edge)
{
	int	i;

	i = 0;
	while (result[i])
	{
		if (i != 0 && !(i % edge))
			ft_putchar('\n');
		ft_putchar(result[i]);
		i++;
	}
	ft_putchar('\n');
}
