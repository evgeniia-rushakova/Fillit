/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:02:25 by jslave            #+#    #+#             */
/*   Updated: 2019/10/08 17:02:29 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

void    print_figure(int *figure, int col)//udalit
{
    int i;
    i = 0;
    if (col == 1)
        printf(MAGENTA"given figure: "RESET);
    else if (col == 7)
        printf(CYAN"this is equal figure: "RESET);
    else
        printf(YELLOW"our figure: "RESET);

    while (i <= 7)
    {
        if (col == 1)
            printf(MAGENTA "%d " RESET, figure[i]);
        else
            printf(YELLOW "%d " RESET, figure[i]);
        i++;
    }
    printf("\n");
}

int     check_right_symbols(char *str, int q_of_fig)
{
    int i;
    int q_of_dot;
    int q_of_sharp;

    q_of_dot = 0;
    q_of_sharp = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] == '.')
            q_of_dot++;
        if (str[i] == '#')
            q_of_sharp++;
        if (str[i] != '\n' && str[i] != '.' && str[i] != '#')
            return (-1);
        i++;
    }
    if(!q_of_fig || (q_of_sharp/4 != q_of_fig) || (q_of_dot/12 != q_of_fig))
        return (-1);
    return (1);
}

int     validate_figure(int *example, int *our_figure, int x_offset, int y_offset)
{
    int i;
    int count;

    i = 0;
    count = 0;

       while (i <= 7)
       {
        //   print_figure(example,1);
       if ((i % 2 == 1) && ((example[i] + y_offset) == our_figure[i]))
       {
           printf(YELLOW"y.our: %i  ", our_figure[i]);
           printf(YELLOW"y.ex: %i\n", (example[i] + y_offset));
           count++;
       }

       else if ((example[i] + x_offset) == our_figure[i])
       {
           printf(YELLOW"x.our: %i  ", our_figure[i]);
           printf(YELLOW"x.ex: %i\n"RESET, (example[i] + x_offset));
           count++;
       }
       i++;
       }
    if (count == i && count != 0 && i != 0)
    {
        printf("FIGURE IS FOUND\n");
        return (1);
    }
    return (-1);
}

int     check_defined_figures(int *figure, int x_offset, int y_offset)
{
    int i;
    int    base_of_figures[19][8] = {{0,0,0,1,0,2,0,3}, {0,0,1,0,2,0,3,0},{0,0,1,0,0,1,1,1},{0,0,0,1,0,2,1,2},
                                  {0,0,1,0,2,0,0,1}, {0,0,1,0,1,1,1,2}, {2,0,0,1,1,1,2,1},{1,0,1,1,0,2,1,2},
                                  {0,0,0,1,1,1,2,1}, {0,0,1,0,0,1,0,2},{0,0,1,0,2,0,2,1},{1,0,0,1,1,1,2,1},
                                  {0,0,0,1,1,1,0,2}, {0,0,1,0,2,0,1,1}, {1,0,0,1,1,1,1,2},{1,0,2,0,0,1,1,1},
                                  {0,0,0,1,1,1,1,2},{0,0,1,0,1,1,2,1}, {1,0,0,1,1,1,0,2}};
    i = 0;
    printf(RED"x_offset is: %i    ", x_offset);
    printf(RED"y_offset is: %i\n"RESET, y_offset);
    while(i <= 19)
    {
        if ((validate_figure(base_of_figures[i], figure, x_offset, y_offset)) == 1) {
            print_figure(base_of_figures[i], 7);
            printf("validate figures returned 1\n");
            return (1);
        }
        i++;
    }
    return (-1);
}

int     check_figure(char *str)
{
    int i;
    int j;
    int x_offset;
    int y_offset;
    y_offset = 0;
    x_offset = 0;
    i = 0;
    j = 0;
    int our_figure [8] = {0};

    while (i <= 19)
    {
        if (str[i] == '#')
        {
            our_figure[j] = x_offset;
            j++;
            our_figure[j] = y_offset;
            j++;
        }
        if (str[i] == '\n')
        {
            y_offset++;
            x_offset = 0;
        }
        else
            x_offset++;
        i++;
    }
    print_figure(our_figure, 8);
   x_offset = our_figure[0];
   y_offset = our_figure[1];
    if (check_defined_figures(our_figure, x_offset, y_offset) == -1)
    {
        printf(RED"NO_FIGURE\n"RESET);
        return (-1);
    }
    else
    {
        printf("check_figure returned 1\n");
        return (1);
    }
    return (-1);
}

int     find_quantity_of_figures(char *str)
{
    int quantity_of_figures;
    int i;
    int symb_check;
    int valid_figure;

    i = 0;
    symb_check = 0;
    quantity_of_figures = 0;
    while (str[i])
    {
        if (symb_check == 4)
        {
            if (str[i] != '\n')
                return (-1);
            symb_check = 0;
        }
        if (str[i] == '.' || str[i] == '#')
            symb_check++;
        if (str[i] == '\n' && (i % 20 == 0 || !str[i + 1]))
        {
            if (!quantity_of_figures)
                valid_figure = check_figure(&(str[i - 20]));
            else
                valid_figure = check_figure(&(str[i - 19]));
            if (valid_figure > 0)
            {
                quantity_of_figures+=1;
                symb_check = 0;
            }
            else
                return (-1);
        }
        i++;
    }
    return (quantity_of_figures);
}

int     check_validity(char *av)
{
    int qual_of_figures;
    int right_symbols;
    qual_of_figures = find_quantity_of_figures(av);
    right_symbols = check_right_symbols(av, qual_of_figures);
    printf("quantity of figures is : %i\n", qual_of_figures);
    if (right_symbols > 0)
        printf("right_symbols is ok. is: %i\n", right_symbols);
    if (qual_of_figures == -1 || right_symbols == -1)
        return (-1);
    return (1);
}
