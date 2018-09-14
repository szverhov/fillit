/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:10:34 by vlvereta          #+#    #+#             */
/*   Updated: 2017/11/17 15:10:41 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		chek_and_clean(int count, t_flist **list, char **val)
{
	int		i;
	t_flist	*tmp;

	tmp = (*list);
	i = 0;
	while (tmp && ++i)
		tmp = tmp->next;
	if (i != count || count > 26)
		lst_free(&(*list));
	free(val);
	val = 0;
	return (i == count && count < 27) ? count : 0;
}

t_flist	*ft_lstcreate(char *content)
{
	t_flist *new;

	if (content == 0)
		return (0);
	new = (t_flist *)malloc(sizeof(t_flist));
	if (new)
	{
		new->figure = ft_strdup(content);
		new->width = 1;
		new->height = 1;
		new->poss = 0;
		new->next = NULL;
		add_wh(new);
	}
	free(content);
	return (new);
}

void	ft_lstback(t_flist **alst, t_flist *new)
{
	t_flist *tmp;

	if (alst)
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	lst_free(t_flist **alst)
{
	if (alst && *alst)
	{
		if ((*alst)->next)
			lst_free(&(*alst)->next);
		free((*alst)->figure);
		free(*alst);
	}
}
