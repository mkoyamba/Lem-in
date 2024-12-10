/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:03:40 by mkoyamba          #+#    #+#             */
/*   Updated: 2024/12/01 12:53:00 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lemin.h"

void	print_grid(t_data *data)
{
	int	n;
	int	i;

	i = 0;
	while (data->visu.grid[i])
	{
		n = 0;
		while (data->visu.grid[i][n].type != CELL_LAST)
		{
			ft_putnbr_fd(data->visu.grid[i][n].type, 1);
			n++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	add_data_grid(t_data *data)
{
	t_room	**rooms;

	rooms = data->rooms;
	while(rooms && *rooms)
	{
		data->visu.grid[(*rooms)->y][(*rooms)->x].type = CELL_ROOM;
		data->visu.grid[(*rooms)->y][(*rooms)->x].room = *rooms;
		rooms++;
	}
}

int	fill_grid_void(t_data *data)
{
	int	n;
	int	i;
	
	i = 0;
	data->visu.grid = malloc((data->visu.y + 1) * sizeof(t_cell *));
	if (!data->visu.grid)
		return (1);
	data->visu.grid[data->visu.y] = NULL;
	while (i < data->visu.y)
	{
		n = 0;
		data->visu.grid[i] = malloc((data->visu.x + 1) * sizeof(t_cell));
		if (!data->visu.grid[i])
			return (free_grid(data));
		data->visu.grid[i][data->visu.x].type = CELL_LAST;
		while (n <= data->visu.x)
		{
			if (n < data->visu.x)
				data->visu.grid[i][n].type = CELL_VOID;
			data->visu.grid[i][n].room = NULL;
			n++;
		}
		i++;
	}
	return (0);
}

void	print_map(t_data *data)
{
	int	n;
	t_room	**rooms;

	n = 0;
	data->visu.x = 0;
	data->visu.y = 0;
	rooms = data->rooms;
	while (rooms[n])
	{
		if (rooms[n]->x > data->visu.x)
			data->visu.x = rooms[n]->x;
		if (rooms[n]->y > data->visu.y)
			data->visu.y = rooms[n]->y;
		n++;
	}
	data->visu.x++;
	data->visu.y++;
	if(fill_grid_void(data))
		return ;
	add_data_grid(data);
	print_grid(data);
	free_grid(data);
}

void	print_rooms(t_data *data)
{
	int	n;

	n = 0;
	while (data->rooms && data->rooms[n])
	{
		printf("room %i: name=%s | x=%i | y=%i\n", n,
			data->rooms[n]->name, data->rooms[n]->x, data->rooms[n]->y);
		n++;
	}
	n = 0;
	while (data->links && data->links[n])
	{
		printf("link %i: room1 = %s | room2 = %s\n", n,
			data->links[n]->room1->name, data->links[n]->room2->name);
		n++;
	}
	print_map(data);
}
