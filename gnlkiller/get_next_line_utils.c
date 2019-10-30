/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:23:00 by paszhang          #+#    #+#             */
/*   Updated: 2019/10/27 22:23:39 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*removereturn(char *src)
{
	int	i;
	int a;
	char*dest;

	a = 0;
	i = 0;
	while (src[a] != '\0')
		a++;
	while (src[i] != '\n' && src[i] != '\0')
		i++;
	if (!(dest = malloc(sizeof(char) * (a - i + 1))))
		return (0);
	a = 0;
	if (*src != '\0')
		i++;
	while (src[i])
		dest[a++] = src[i++];
	dest[a] = '\0';
	free(src);
	return (dest);
}

int		ft_check(char *src)
{
	while (*src)
	{
		if (*src == '\n')
			return (1);
		src++;
	}
	return (0);
}

char	*returntext(char *src)
{
	int i;
	char*tmp;

	i = 0;
	while (src[i] && src[i] != '\n')
		i++;
	if (!(tmp = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
