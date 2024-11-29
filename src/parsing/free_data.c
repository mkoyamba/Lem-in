/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:46:35 by mkoyamba          #+#    #+#             */
/*   Updated: 2024/11/29 11:15:23 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lemin.h"

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
