/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gathering_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:31:17 by mkoyamba          #+#    #+#             */
/*   Updated: 2024/11/30 14:17:16 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lemin.h"

int	set_null_rooms(t_data *data, int number)
{
	int	n;

	n = 0;
	data->rooms = malloc((number + 1) * sizeof(t_room *));
	if (!data->rooms)
		return (1);
	while (n < number + 1)
	{
		data->rooms[n] = NULL;
		n++;
	}
	return (0);
}

t_room	*set_null_room(void)
{
	t_room	*result;

	result = malloc(sizeof(t_room));
	if (!result)
		return (NULL);
	result->name = NULL;
	return (result);
}

int	add_room(char **line, t_data *data, int index)
{
	int		n;
	char	*infos;

	infos = *line;
	n = 0;
	data->rooms[index] = set_null_room();
	if (!data->rooms[index])
		return (1);
	while (ft_isalnum(*infos))
	{
		infos++;
		n++;
	}
	data->rooms[index]->name = ft_substr(*line, 0, n);
	if (!data->rooms[index]->name)
		return (1);
	if (add_numbers(data, index, ++infos))
		return (1);
	return (0);
}

int	add_rooms(t_data *data)
{
	int		number[2];
	char	**temp;

	number[0] = 0;
	temp = data->file;
	while (*(temp) != NULL)
	{
		if (is_room(temp))
			number[0]++;
		temp++;
	}
	number[1] = number[0];
	if (set_null_rooms(data, number[0]))
		return (1);
	temp = data->file;
	while (*(temp) != NULL && number[0] > -1)
	{
		if (is_room(temp) && add_room(temp, data, number[1] - number[0]))
			return (free_rooms(data));
		if (is_room(temp))
			number[0]--;
		temp++;
	}
	return (0);
}

int	add_data(t_data *data)
{
	if (add_rooms(data))
		return (1);
	if (add_links(data))
		return (free_rooms(data));
	return (0);
}
