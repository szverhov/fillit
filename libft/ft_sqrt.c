/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 10:22:02 by vlvereta          #+#    #+#             */
/*   Updated: 2017/10/25 10:23:50 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int	tmp;
	int	odd;
	int	root;

	tmp = nb;
	odd = 1;
	root = 0;
	while (1)
	{
		if (!tmp)
			if ((root * root == nb))
				return (root);
		if (tmp < 0)
			return (0);
		tmp -= odd;
		odd += 2;
		root++;
	}
}
