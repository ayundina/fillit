/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 10:27:50 by ayundina      #+#    #+#                 */
/*   Updated: 2019/04/03 10:27:57 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putstr(char const *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return ((unsigned char *)b);
}

void	*ft_memalloc(size_t size)
{
	char	*memret;

	memret = (char *)malloc(sizeof(char) * size);
	if (!memret)
		return (NULL);
	ft_memset((void *)memret, 0, sizeof(char) * size);
	return ((void *)memret);
}
