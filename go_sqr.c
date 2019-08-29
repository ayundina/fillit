/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   go_sqr.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 10:27:33 by ayundina      #+#    #+#                 */
/*   Updated: 2019/04/03 10:27:37 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	create_sqr(char **sqr, int n_ttrs)
{
	int		i;
	int		j;
	char	*tmp;

	i = 2;
	j = 0;
	n_ttrs *= 4;
	tmp = *sqr;
	while (i * i < n_ttrs)
		i++;
	*sqr = (char *)ft_memalloc(sizeof(char) * (i * i + i + 1));
	if (!*sqr)
		exit(0);
	if (tmp)
		free(tmp);
	ft_memset(*sqr, '.', i * i + i);
	while ((*sqr)[j] != '\0')
	{
		if (j % (i + 1) == i)
		{
			(*sqr)[j] = '\n';
		}
		j++;
	}
}

void	go_sqr(char ttr[26][20], int n_ttrs)
{
	char	*sqr;

	sqr = NULL;
	create_sqr(&sqr, n_ttrs);
	while (!try_ttr(sqr, ttr, 0))
	{
		n_ttrs++;
		create_sqr(&sqr, n_ttrs);
	}
	ft_putstr(sqr);
}
