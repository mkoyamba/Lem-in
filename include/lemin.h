/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:59:06 by mkoyamba          #+#    #+#             */
/*   Updated: 2024/11/26 12:54:44 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

//          ----------========== {   INCLUDES   } ==========----------

# include "../lib/libft/include/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <fcntl.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define E_FILE "No such file"

//          ----------========== {    STRUCT    } ==========----------

typedef struct s_room
{
	char	*name;
	int		x;
	int		y;
}				t_room;

typedef struct s_link
{
	t_room	*room1;
	t_room	*room2;
}				t_link;

typedef struct s_data
{
	char	**file;
	int		scale;
	t_room	*rooms;
	t_link	*links;
}				t_data;

//          ----------========== {     FCTS     } ==========----------

char	**split_file(char *s, char c);
char	**read_file(int fd);
void	error_out(char *str, int code);
int		parsing(t_data *data);

#endif