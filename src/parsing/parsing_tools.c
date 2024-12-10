/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:20:15 by mkoyamba          #+#    #+#             */
/*   Updated: 2024/11/30 14:36:39 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lemin.h"

int	add_numbers(t_data *data, int index, char *infos)
{
	char	*numbers[2];
	int		n;

	n = 0;
	while (ft_isalnum(infos[n]))
		n++;
	numbers[0] = ft_substr(infos, 0, n);
	if (!numbers[0])
		return (1);
	infos += n + 1;
	n = 0;
	while (ft_isalnum(infos[n]))
		n++;
	numbers[1] = ft_substr(infos, 0, n);
	if (!numbers[1])
		free(numbers[0]);
	if (!numbers[1])
		return (1);
	data->rooms[index]->x = ft_atoi(numbers[0]);
	data->rooms[index]->y = ft_atoi(numbers[1]);
	free(numbers[0]);
	free(numbers[1]);
	if (data->rooms[index]->x < 0 || data->rooms[index]->y < 0)
		return (1);
	return (0);
}
