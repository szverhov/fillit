/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:28:16 by vlvereta          #+#    #+#             */
/*   Updated: 2017/10/26 15:31:48 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f)(char *))
{
	unsigned int i;

	if (s && f)
	{
		i = 0;
		while (s[i])
		{
			f(s + i);
			i++;
		}
	}
}
