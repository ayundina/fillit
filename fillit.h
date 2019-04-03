/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 10:30:02 by ayundina      #+#    #+#                 */
/*   Updated: 2019/04/03 10:30:04 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

void	read_n_check_len(int fd);
void	error_n_exit(void);
void	check_ttrs(char *buf);
void	check_new_lines(char *buf);
void	check_ttr_blocks(char *buf, int touch, int block, int i);
void	fill_ttrs_arr(char *buf, char ttr[26][20]);
void	fill_ttr_str(char **buf, char *ttr);
void	trim_arr(char ttr[26][20], int n_ttrs, int i, int min);
void	move_blocks(char *ttr, int min);
void	assign_letter(char ttr[26][20], int n_ttrs);
void	go_sqr(char ttr[26][20], int n_ttrs);
void	create_sqr(char **sqr, int n_ttrs);
int		try_ttr(char *sqr, char ttr[26][20], int tr);
void	place_ttr(char *sqr, int strt, char *ttr);
int		ttr_fitting(char *sqr, int *strt, char *ttr);
void	erace_ttr(char *sqr, int strt, char *ttr);
void	go_next_row(char *sqr, char *ttr, int *sc, int *tc);
int		only_new_line(char *ttr, int tc);

void	*ft_memalloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putstr(char const *s);

#endif
