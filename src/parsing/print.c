/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:03:40 by mkoyamba          #+#    #+#             */
/*   Updated: 2024/11/29 12:16:32 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lemin.h"

void	print_rooms(t_data *data)
{
	int	n;

	n = 0;
	while (data->rooms && data->rooms[n] && data->rooms[n])
	{
		printf("%i: name=%s\n", n, data->rooms[n]->name);
		n++;
	}
}
