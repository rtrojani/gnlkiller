/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:31:55 by paszhang          #+#    #+#             */
/*   Updated: 2019/10/28 11:05:39 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		gettext(int fd, char **src)
{
	char	buff[BUFFER_SIZE + 1];
	int		ret;
	char	*dest;

	if (!(dest = malloc(1)))
		return (-1);
	*dest = '\0';
	if (!(dest = allodynamic(dest, *src)))
			return (-1);
	free(*src);
	*src = dest;
	if (ft_check(*src))
		return (1);
	while ((ret = read(fd, buff, BUFFER_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		if (!(dest = allodynamic(dest, buff)))
			return (-1);
		*src = dest;
		if (ft_check(dest))
			return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*tab[BUFFER_SIZE] = {NULL};
	int			result;

	if (fd < 0 || tab[fd] == NULL)
	{
		if (!(*line = malloc(1)))
			return (0);
		*line[0] = '\0';
		tab[fd] = *line;
		if (fd < 0)
			return (0);
	}
	result = gettext(fd, &tab[fd]);
	if (!(*line = returntext(tab[fd])))
		return (-1);
	if (result <= 0)
	{
		free(tab[fd]);
		tab[fd] = NULL;
	}
	else
		tab[fd] = removereturn(tab[fd]);
	return (result);
}

char	*allodynamic(char *src1, char *src2)
{
	int	i;
	int	a;
	char*dest;

	i = 0;
	a = 0;
	while (src1[i])
		i++;
	while (src2[a])
		a++;
	if (!(dest = malloc(sizeof(char) * (i + a + 1))))
		return (0);
	i = 0;
	a = 0;
	while (src1[a])
		dest[i++] = src1[a++];
	a = 0;
	while (src2[a])
		dest[i++] = src2[a++];
	dest[i] = '\0';
	free(src1);
	return (dest);
}
