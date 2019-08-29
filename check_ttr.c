/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_ttr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 10:26:32 by ayundina      #+#    #+#                 */
/*   Updated: 2019/04/03 10:26:38 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	check_ttr_blocks(char *buf, int touch, int block, int i)
{
	while (buf[i] != '\0' && i < 20)
	{
		if (buf[i] == '#')
		{
			if (i + 1 < 20)
				if (buf[i + 1] == '#')
					touch++;
			if (i + 5 < 20)
				if (buf[i + 5] == '#')
					touch++;
			if (i - 1 >= 0 && i - 1 < 20)
				if (buf[i - 1] == '#')
					touch++;
			if (i - 5 >= 0 && i - 5 < 20)
				if (buf[i - 5] == '#')
					touch++;
			block++;
		}
		i++;
	}
	if (touch != 6 && touch != 8)
		error_n_exit();
	if (block != 4)
		error_n_exit();
}

void	check_new_lines(char *buf)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
		{
			n++;
			if (buf[i + 1] == '\n' || buf[i + 1] == '\0')
			{
				if (n == 4)
				{
					n = -1;
					check_ttr_blocks(buf + i - 19, 0, 0, 0);
				}
				else
				{
					error_n_exit();
				}
			}
		}
		i++;
	}
}

void	check_ttrs(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
		{
			error_n_exit();
		}
		i++;
	}
	check_new_lines(buf);
}
