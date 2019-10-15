/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:23:54 by tollivan          #+#    #+#             */
/*   Updated: 2019/10/15 20:01:14 by tollivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# define BUF_SIZE 4096

int				find_offset(char *src);
char			*change_example(char *example, int x_offset, int y_offset);
int				check_if_figure_is_tetramino(char *our_figure);
int				find_quantity_of_figures(char *str, size_t len);
char			*make_string(char *arr, char *result);
int    			check_figures(int qual_of_figures, char *arr);
int				check_validity(char *av);
int				push(char *coords);
void     		make_list_of_figures(char *str, int q_of_figures, t_tet *head);

typedef struct	s_tet
{
    int				x1;
    int				y1;
    int				x2;
    int				y2;
    int				x3;
    int				y3;
    int				x4;
    int				y4;
    int				x_d;
    int				y_d;
    char			sym;
    struct s_tet	*next;
}				t_tet;

#include <stdio.h>
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

#endif