/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_cheker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:37:52 by vlvereta          #+#    #+#             */
/*   Updated: 2017/11/21 13:40:47 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_file(char *argv, t_flist **res)
{
	int		fd;
	int		ret;
	char	buf[32];
	char	**val;
	int		count;

	if (!(val = valid_figures()))
		return (0);
	count = 0;
	fd = open(argv, O_RDONLY);
	while ((ret = read(fd, buf, 21)) && ++count)
	{
		if (count > 26)
			return (chek_and_clean(count, &(*res), &(*val)));
		buf[ret] = '\0';
		if (validate_square(buf, ft_strlen(buf)) == 0)
			return (chek_and_clean(count, &(*res), &(*val)));
		if (validate_square(buf, ft_strlen(buf)) == 1 && (*res) == 0)
			(*res) = ft_lstcreate(valid_str(buf, val));
		else
			ft_lstback(&(*res), ft_lstcreate(valid_str(buf, val)));
	}
	if (ft_strlen(buf) != 20 || buf[ft_strlen(buf) - 1] != '\n')
		count = 0;
	return (chek_and_clean(count, &(*res), &(*val)));
}

int		validate_square(char *fig, int str_len)
{
	int dot;
	int hesh;
	int len;

	if (fig == 0)
		return (0);
	len = 0;
	dot = 0;
	hesh = 0;
	while (len < str_len)
	{
		if (fig[len] == '.')
			dot++;
		if (fig[len] == '#')
			hesh++;
		if ((len == 4 || len == 9 || len == 14 ||
		len == 19 || len == 20) && fig[len] != '\n')
			return (0);
		++len;
	}
	return (dot == 12 && hesh == 4 ? 1 : 0);
}

char	*valid_str(char *s, char **val)
{
	char	*fig;

	if (!(fig = make_str_fig(s)))
		return (0);
	while (*val != 0)
	{
		if (ft_strcmp(*val, fig) == 0)
		{
			return (fig);
			break ;
		}
		val++;
	}
	free(fig);
	return (0);
}

char	*make_str_fig(char *s)
{
	int		i;
	int		j;
	int		hash;
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) * 14)))
		return (0);
	i = 0;
	j = 0;
	hash = 0;
	while (s[i] != '#')
		i++;
	while (hash < 4)
	{
		if (s[i] == '#')
			hash++;
		if (s[i] != '\n')
			res[j++] = s[i] == '#' ? '1' : '0';
		i++;
	}
	res[j] = '\0';
	return (res);
}

char	**valid_figures(void)
{
	char **valids;

	if (!(valids = (char **)malloc(sizeof(char *) * 20)))
		return (NULL);
	valids[0] = "110011";
	valids[1] = "1000100010001";
	valids[2] = "1111";
	valids[3] = "110010001";
	valids[4] = "1110001";
	valids[5] = "100010011";
	valids[6] = "1000111";
	valids[7] = "1100010001";
	valids[8] = "11101";
	valids[9] = "1000100011";
	valids[10] = "10111";
	valids[11] = "1100011";
	valids[12] = "10011001";
	valids[13] = "11011";
	valids[14] = "1000110001";
	valids[15] = "100111";
	valids[16] = "100011001";
	valids[17] = "111001";
	valids[18] = "100110001";
	valids[19] = 0;
	return (valids);
}
