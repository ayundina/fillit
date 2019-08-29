/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   crt_ttr_arr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 10:26:54 by ayundina      #+#    #+#                 */
/*   Updated: 2019/04/03 10:42:33 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	assign_letter(char ttr[26][20], int n_ttrs)
{
	int	i;
	int	letter;

	n_ttrs = 0;
	while (ttr[n_ttrs][0] != 0)
	{
		i = 0;
		while (ttr[n_ttrs][i] != 0)
		{
			letter = n_ttrs + 'A';
			if (ttr[n_ttrs][i] == '#')
			{
				ttr[n_ttrs][i] = letter;
			}
			i++;
		}
		n_ttrs++;
	}
}

void	move_blocks(char *ttr, int min)
{
	int	i;

	i = 0;
	while (ttr[i] != '\0' && min > 0)
	{
		if (ttr[i] == '#')
		{
			ttr[i - min] = '#';
			ttr[i] = '.';
		}
		i++;
	}
}

void	trim_arr(char ttr[26][20], int n_ttrs, int i, int min)
{
	while (n_ttrs >= 0)
	{
		i = 0;
		min = 5;
		while (ttr[n_ttrs][i + 1] != '\0')
		{
			if (i == 0 && ttr[n_ttrs][i] == '#')
				min = 0;
			if ((ttr[n_ttrs][i] == '.' && ttr[n_ttrs][i + 1] == '#') || \
					(ttr[n_ttrs][i] == '\n' && ttr[n_ttrs][i + 1] == '#'))
				if (min > (i + 1) % 5)
					min = (i + 1) % 5;
			i++;
		}
		i = 0;
		if (min > 0)
			move_blocks(ttr[n_ttrs], min);
		n_ttrs--;
	}
}

void	fill_ttr_str(char **buf, char *ttr)
{
	int	i;
	int	block;

	i = 0;
	block = 0;
	while (block < 4)
	{
		ttr[i] = **buf;
		if (**buf == '#')
		{
			block++;
		}
		(*buf)++;
		i++;
	}
	ttr[i] = '\0';
}

void	fill_ttrs_arr(char *buf, char ttr[26][20])
{
	int	strt;
	int	n_ttrs;

	strt = 0;
	n_ttrs = 0;
	while (*buf != '\0' && *(buf + 1) != '\0' && *(buf + 2) != '\0' && \
			*(buf + 3) != '\0' && *(buf + 4) != '\0')
	{
		if ((*buf == '#' || *(buf + 1) == '#' || *(buf + 2) == '#' || \
					*(buf + 3) == '#') && *(buf + 4) == '\n')
		{
			fill_ttr_str(&buf, ttr[n_ttrs]);
			n_ttrs++;
		}
		buf++;
	}
	ttr[n_ttrs][0] = 0;
	trim_arr(ttr, n_ttrs - 1, 0, 0);
	assign_letter(ttr, n_ttrs);
	go_sqr(ttr, n_ttrs);
}
