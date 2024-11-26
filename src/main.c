/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:53:32 by mkoyamba          #+#    #+#             */
/*   Updated: 2024/11/26 12:57:46 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

void	error_out(char *str, int code)
{
	ft_putstr_fd("Error\nlem-in: ", STDERR);
	ft_putendl_fd(str, STDERR);
	exit(code);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;

	if (argc != 2 || !argv[1] || !argv[1][0])
		error_out("Usage -> ./lem-in [config file path]", 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\ncub3d: ", STDERR);
		ft_putstr_fd(argv[1], STDERR);
		ft_putstr_fd(": ", STDERR);
		ft_putendl_fd(E_FILE, STDERR);
		exit(1);
	}
	data.file = read_file(fd);
	close(fd);
	if (!data.file || parsing(&data))
		error_out("Incorrect config file", 1);
	return (0);
}
