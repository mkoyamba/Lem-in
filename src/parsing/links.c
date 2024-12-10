/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:41:54 by mkoyamba          #+#    #+#             */
/*   Updated: 2024/12/01 13:32:07 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lemin.h"

int	is_room_data(t_data *data, char *name)
{
	t_room	**temp;
	int		n;

	temp = data->rooms;
	n = 0;
	while (temp[n])
	{
		if (!ft_strncmp(temp[n]->name, name, ft_strlen(name)))
			return (n);
		n++;
	}
	return (-1);
}

int	add_both_rooms_link(t_data *data, int index, char *names[3])
{
	if (!names[0] || !names[1] || is_room_data(data, names[0]) < 0
		|| is_room_data(data, names[1]) < 0
		|| !ft_strncmp(names[0], names[1], ft_strlen(names[0])))
		return (free_names(names));
	data->links[index] = malloc(sizeof(t_link));
	if (!data->links[index])
		return (free_names(names));
	data->links[index]->room1 = data->rooms[is_room_data(data, names[0])];
	data->links[index]->room2 = data->rooms[is_room_data(data, names[1])];
	free_names(names);
	return (0);
}

int	add_link(char **line, t_data *data, int index)
{
	char	*names[3];
	int		iter[2];

	names[2] = *line;
	iter[1] = -1;
	while (names[2][0] && names[2][0] != '\n' && iter[1]++ > -2)
	{
		iter[0] = 0;
		while (names[2][iter[0]] && ft_isalnum(names[2][iter[0]]))
			iter[0]++;
		names[0] = ft_substr(names[2], 0, iter[0]);
		names[2] += iter[0] + 1;
		iter[0] = 0;
		while (names[2][iter[0]] && ft_isalnum(names[2][iter[0]]))
			iter[0]++;
		names[1] = ft_substr(names[2], 0, iter[0]);
		if (add_both_rooms_link(data, index + iter[1], names))
			return (free_links(data));
		if (names[2][0])
			names[2]++;
		if (names[2][0] == ' ')
			names[2]++;
	}
	return (0);
}

int	set_null_links(t_data *data, int number)
{
	int	n;

	n = 0;
	data->links = malloc((number + 1) * sizeof(t_link *));
	if (!data->links)
		return (1);
	while (n <= number)
	{
		data->links[n] = NULL;
		n++;
	}
	return (0);
}

int	add_links(t_data *data)
{
	char	**temp;
	int		number;

	temp = data->file;
	number = 0;
	while (*(temp) != NULL)
	{
		if (is_link(temp, 0))
			number += is_link(temp, 0);
		temp++;
	}
	if (set_null_links(data, number))
		return (1);
	temp = data->file;
	number = 0;
	while (*(temp) != NULL)
	{
		if (is_link(temp, 0) && add_link(temp, data, number))
			return (1);
		number += is_link(temp, 0);
		temp++;
	}
	return (0);
}
