/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:46:35 by mkoyamba          #+#    #+#             */
/*   Updated: 2024/12/01 12:27:47 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lemin.h"

int	free_grid(t_data *data)
{
	int	n;

	n = 0;
	while (data->visu.grid && data->visu.grid[n])
	{
		free(data->visu.grid[n]);
		n++;
	}
	if (data->visu.grid)
		free(data->visu.grid);
	return (1);
}

int	free_names(char *names[2])
{
	if (names[0])
		free(names[0]);
	if (names[1])
		free(names[1]);
	return (1);
}

int	free_rooms(t_data *data)
{
	int	n;

	n = 0;
	while (data->rooms[n])
	{
		if (data->rooms[n] && data->rooms[n]->name)
			free(data->rooms[n]->name);
		if (data->rooms[n])
			free(data->rooms[n]);
		n++;
	}
	free(data->rooms);
	return (1);
}

int	free_links(t_data *data)
{
	int	n;

	n = 0;
	while (data->links && data->links[n])
	{
		if (data->links[n])
			free(data->links[n]);
		n++;
	}
	free(data->links);
	return (1);
}

int	free_file(t_data *data)
{
	int	n;

	n = 0;
	while (data->file[n])
	{
		free(data->file[n]);
		n++;
	}
	free(data->file);
	return (1);
}