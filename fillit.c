/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 10:27:16 by ayundina      #+#    #+#                 */
/*   Updated: 2019/04/03 10:27:19 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	go_next_row(char *sqr, char *ttr, int *sc, int *tc)
{
	while (sqr[*sc] != '\n')
	{
		*sc += 1;
	}
	while (ttr[*tc] != '\n')
	{
		*tc += 1;
	}
	*tc += 1;
	*sc += 1;
}

void	erace_ttr(char *sqr, int strt, char *ttr)
{
	char	c;

	c = '.';
	while (*ttr != '\0')
	{
		if (*ttr != '.')
		{
			c = *ttr;
			break ;
		}
		ttr++;
	}
	while (sqr[strt] != '\0')
	{
		if (sqr[strt] == c)
		{
			sqr[strt] = '.';
		}
		strt++;
	}
}

int		ttr_fitting(char *sqr, int *strt, char *ttr)
{
	int	sc;
	int	tc;
	int	block;

	tc = 0;
	sc = 0;
	block = 0;
	while (sqr[sc + *strt] != '\0')
	{
		if (ttr[tc] == '\0' || block == 4)
			return (1);
		if (only_new_line(ttr, tc))
			go_next_row(sqr, ttr, &sc, &tc);
		if (ttr[tc] != '.' && ttr[tc] != '\n' && ttr[tc] != '\0')
			block++;
		if (!(sqr[sc + *strt] != '.' && ttr[tc] != '.'))
		{
			sc++;
			tc++;
		}
		else
			return (0);
	}
	return (0);
}

void	place_ttr(char *sqr, int strt, char *ttr)
{
	int sc;
	int	tc;

	sc = 0;
	tc = 0;
	while (sqr[sc + strt] != '\0')
	{
		if (ttr[tc] == '.')
		{
			tc++;
			sc++;
		}
		if (ttr[tc] != '.' && ttr[tc] != '\n' && \
			ttr[tc] != '\0' && sqr[sc + strt] == '.')
		{
			sqr[sc + strt] = ttr[tc];
			tc++;
			sc++;
		}
		if (only_new_line(ttr, tc))
			go_next_row(sqr, ttr, &sc, &tc);
		if (ttr[tc] == '\0')
			return ;
	}
}

int		try_ttr(char *sqr, char ttr[26][20], int tr)
{
	int	strt;

	strt = 0;
	if (ttr[tr][0] == '\0')
	{
		return (1);
	}
	while (sqr[strt] != '\0')
	{
		if (ttr_fitting(sqr, &strt, ttr[tr]))
		{
			place_ttr(sqr, strt, ttr[tr]);
			if (try_ttr(sqr, ttr, tr + 1))
			{
				return (1);
			}
			else
				erace_ttr(sqr, strt, ttr[tr]);
		}
		strt++;
	}
	if (tr == 0)
		return (0);
	return (0);
}
