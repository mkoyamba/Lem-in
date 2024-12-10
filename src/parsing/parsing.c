/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:42:28 by mkoyamba          #+#    #+#             */
/*   Updated: 2024/12/01 13:13:54 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lemin.h"

int	is_link(char **line_s, int result)
{
	char	*line;

	line = *line_s;
	while (line[0] && line[0] != '\n')
	{
		while (line[0] && ft_isalnum(line[0]))
			line++;
		if (line[0] != '-')
			return (0);
		line++;
		if (!line[0] || !ft_isalnum(line[0]))
			return (0);
		while (line[0] && ft_isalnum(line[0]))
			line++;
		if (line[0] && line[0] != '\n' && line[0] != ' ')
			return (0);
		if (line[0])
			line++;
		result++;
	}
	return (result);
}

int	is_room(char **line_s)
{
	char	*line;

	if (!line_s || !line_s[0])
		return (0);
	line = *line_s;
	if (line[0] == '\0' || line[0] == '#' || line[0] == '\n')
		return (0);
	while (line[0] && line[0] != ' ')
		line++;
	if (line[0])
		line++;
	while (line[0] && line[0] != ' ' && ft_isdigit(line[0]))
		line++;
	if (line[0] != ' ')
		return (0);
	if (line[0])
		line++;
	while (line[0] && line[0] != ' ' && ft_isdigit(line[0]))
		line++;
	if (line[0] == '\0' || line[0] == '\n')
		return (1);
	else
		return (0);
}

int	is_valid_line(char **line)
{
	if (!line || !*line || *line[0] == '\0')
		return (0);
	else if (*line[0] == '#' && *(*line + 1) != '#')
		return (1);
	else if (is_room(line))
		return (1);
	else if (is_link(line, 0))
		return (1);
	else if (*line[0] == '#'
		&& (ft_strncmp(*line, "##end", 5) || ft_strncmp(*line, "##start", 7)))
	{
		line++;
		if (is_room(line))
			return (1);
	}
	return (0);
}

int	is_valid_file(t_data *data)
{
	char	**test;

	test = data->file;
	while (*(test) != NULL)
	{
		if (!is_valid_line(test))
			return (0);
		test++;
	}
	return (1);
}

int	parsing(t_data *data)
{
	if (!is_valid_file(data))
		return (free_file(data));
	if (add_data(data))
		return (free_file(data));
	free_file(data);
	return (0);
}
