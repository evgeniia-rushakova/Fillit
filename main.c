/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:21:51 by jslave            #+#    #+#             */
/*   Updated: 2019/10/08 16:21:58 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "../libft/includes/libft.h"
#include <fcntl.h>
#define BUF_SIZE 4096

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

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

int		push(char *coords)
{
    t_tet *stet;

    if (!(stet = (t_tet *)malloc(sizeof(t_tet))))
        return (0);
    stet->x1 = coords[0] - '0';
    stet->y1 = coords[1] - '0';
    stet->x2 = coords[2] - '0';
    stet->y2 = coords[3] - '0';
    stet->x3 = coords[4] - '0';
    stet->y3 = coords[5] - '0';
    stet->x4 = coords[6] - '0';
    stet->y4 = coords[7] - '0';
    stet->next = NULL;
    return (1);
}

int         check_validity(char *av);

void     make_list_of_figures(*str, int q_of_figures, t_tet *head)
{
    t_tet *new;
    char *result;

    new = head;
    while (qual_of_figures > 0)
    {
        result = make_string(str, result);
        push(result);
        new = new->next;
        str+=21;
    }

}

int         main(int ac, char **av)
{
    int res;
    int result_of_validity;
    char	buf[BUF_SIZE + 1];
    t_tet *head;

/*    if (ac == 2)
    {
        res = read(open(av[1], O_RDONLY), buf, BUF_SIZE);
        buf[res] = '\0';
        result_of_validity  = check_validity(buf);
        if (result_of_validity > 0)
            find_solution(av[1]);

    }*/
   res = read(open("../test", O_RDONLY), buf, BUF_SIZE);
   buf[res] = '\0';
   result_of_validity  = check_validity(buf);
   if (result_of_validity > 0)
   {
       printf(GREEN "result of check_validity is ok: %i\n" RESET, result_of_validity);
       //make_list_of_figures(av,q_of_figures, head);
   }

   else
       printf(RED "result of check_validity is bad: %i\n" RESET, result_of_validity);
   return (0);
}
