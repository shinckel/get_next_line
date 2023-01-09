/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:28:14 by shinckel          #+#    #+#             */
/*   Updated: 2022/12/16 13:04:20 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			i;

	i = 0;
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		while (buf[i])
			buf[i++] = 0;
		return (NULL);
	}
	tmp = NULL;
	while (buf[0] || read(fd, buf, BUFFER_SIZE) > 0)
	{
		tmp = ft_join(tmp, buf);
		if (ft_check(buf))
			break ;
	}
	return (tmp);
}
