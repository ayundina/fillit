/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 10:28:10 by ayundina      #+#    #+#                 */
/*   Updated: 2019/04/03 10:28:17 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error_n_exit(void)
{
	ft_putstr("error\n");
	exit(0);
}

void	read_n_check_len(int fd)
{
	int		n_trms;
	int		ret;
	char	buf[546];
	char	ttr[26][20];

	n_trms = 0;
	if (fd > 0)
	{
		ret = (int)read(fd, buf, 546);
		if (ret < 0 || ret % 21 != 20 || ret > 545)
		{
			error_n_exit();
		}
		buf[ret] = '\0';
		check_ttrs(buf);
		fill_ttrs_arr(buf, ttr);
	}
	else
	{
		error_n_exit();
	}
}

int		main(int argc, const char **argv)
{
	int fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		read_n_check_len(fd);
	}
	else
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0]);
		ft_putstr(" input_file\n");
	}
	return (0);
}
