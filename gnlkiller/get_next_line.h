/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:24:33 by paszhang          #+#    #+#             */
/*   Updated: 2019/10/27 22:24:09 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*allodynamic(char *src1, char *src2);
int		get_next_line(int fd, char **line);
int		gettext(int fd, char **src);
char	*returntext(char *src);
char	*removereturn(char *src);
int		ft_check(char *src);

#endif
