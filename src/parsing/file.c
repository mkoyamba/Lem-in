/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:33:54 by mkoyamba          #+#    #+#             */
/*   Updated: 2024/11/26 12:35:30 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lemin.h"

char	**read_file(int fd)
{
	char	*result;
	char	*trash;
	char	buf[10001];
	ssize_t	rd;
	char	**to_return;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	rd = 10000;
	while (rd == 10000)
	{
		rd = read(fd, buf, 10000);
		buf[rd] = '\0';
		trash = result;
		result = ft_strjoin(result, buf);
		free(trash);
	}
	to_return = split_file(result, '\n');
	free(result);
	return (to_return);
}
