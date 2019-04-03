/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   only_nl.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 10:28:29 by ayundina      #+#    #+#                 */
/*   Updated: 2019/04/03 10:40:44 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		only_new_line(char *ttr, int tc)
{
	if (ttr[tc] == '\n')
		return (1);
	if (ttr[tc + 1] != '\0')
	{
		if (ttr[tc] == '.' && ttr[tc + 1] == '\n')
		{
			return (1);
		}
	}
	if (ttr[tc + 2] != '\0')
	{
		if (ttr[tc] == '.' && ttr[tc + 1] == '.' && ttr[tc + 2] == '\n')
		{
			return (1);
		}
	}
	if (ttr[tc + 3] != '\0')
	{
		if (ttr[tc] == '.' && ttr[tc + 1] == '.' && ttr[tc + 2] == '.' && \
				ttr[tc + 3] == '\n')
		{
			return (1);
		}
	}
	return (0);
}
