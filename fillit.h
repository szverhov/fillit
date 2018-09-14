/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:24:43 by vlvereta          #+#    #+#             */
/*   Updated: 2017/11/21 13:03:00 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef	struct		s_flist
{
	char			*figure;
	int				width;
	int				height;
	int				poss;
	struct s_flist	*next;
}					t_flist;

int					check_file(char *argv, t_flist **res);
int					validate_square(char *fig, int str_len);
char				*valid_str(char *s, char **val);
char				*make_str_fig(char *s);
char				**valid_figures(void);
int					chek_and_clean(int count, t_flist **list, char **val);
void				data_creator(t_flist *figures, int edge);
t_flist				*ft_lstcreate(char *content);
void				ft_lstback(t_flist **alst, t_flist *new);
void				lst_free(t_flist **alst);
char				**matrix_create(t_flist *figures, int edge);
int					find_positions(t_flist *figures, int edge);
char				**matrix_to_zero(char **matrix, int height, int len);
void				write_matrix(char **matrix, int	edge, t_flist *figures);
void				write_poss(char **matrix, int row, int edge, t_flist *f);
void				write_poss_row(char **m_row, int start, int edge, char *f);
char				*square_create(char **matrix, char *result, char letter);
int					check_matrix(char **matrix);
char				**copy_matrix(char **matrix);
char				**clean_matrix(char **matrix, int row);
void				clean_figure(char **matrix, char c);
void				matrix_free(char **matrix);
char				*write_figure(char **matrix, char *result, char *row);
void				print_result(char *result, int edge);
int					edge_finder(int fig_amount);
void				add_zero(char **figure);
void				add_wh(t_flist *a);
void				result_dot(char *result, int len);

#endif
