#include "libft.h"
#include <stdio.h>
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

char *change_example(char *example, int x_offset, int y_offset)//16lines
{
    char *changed_example;
    int i;

    i = 0;
    changed_example = ft_strnew(7);
    while(i<= 7)
    {
       if ((i % 2) == 1)
           changed_example[i] = example[i] + '0' + y_offset - '0';
       else
           changed_example[i] = example[i] + '0' + x_offset - '0';
        i++;
    }
    return (changed_example);
}

int     check_is_figure_is_tetramino(char *our_figure)//22lines
{
    int i;
    char *changed_example;
    int x_offset;
    int y_offset;
    char   base_of_figures[19][8] = {"00010203", "00102030","00100111","00010212",
                                     "00102001", "00101112", "20011121","10110212",
                                     "00011121", "00100102","00102021","10011121",
                                     "00011102", "00102011", "10011112","10200111",
                                     "00011112", "00101121", "10011102"};
    i = 0;
    while(i <= 18)
    {
/*        printf(RED"origin: %c", base_of_figures[i][0]);
        printf("%c", base_of_figures[i][1]);
        printf("%c", base_of_figures[i][2]);
        printf("%c", base_of_figures[i][3]);
        printf("%c", base_of_figures[i][4]);
        printf("%c", base_of_figures[i][5]);
        printf("%c", base_of_figures[i][6]);
        printf("%c\n", base_of_figures[i][7]);
        x_offset = find_offset(&our_figure[0]);
        y_offset = find_offset(&our_figure[1]);*/
        changed_example = change_example(base_of_figures[i], our_figure[0] -'0', our_figure[1] - '0');
        printf(YELLOW"our: %s\n"RESET, our_figure);
        printf(GREEN"changed: %s\n",changed_example);
        if(ft_strcmp(base_of_figures[i], our_figure) == 48 || ft_strcmp(changed_example, our_figure) == 48)
        {
            printf("validate figures returned 1\n");
            return (1);
        }
        free(changed_example);
        i++;
    }
    return (-1);
}
/*
int     find_quantity_of_figures(char *str)//27lines
{
    int quantity_of_figures;
    size_t i;
    int symb_check;

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
            quantity_of_figures+=1;
            symb_check = 0;
        }
        i++;
    }
    return (quantity_of_figures);
}
*/

int     find_quantity_of_figures(char *str, size_t len)
{
    int quantity;
    size_t size_of_dots;
    size_t size_of_sharps;
    size_t size_of_slashn;

    size_of_dots = 0;
    size_of_sharps = 0;
    size_of_slashn = 0;

    if (len == 20)
        return (1);
    while(str++)
    {
        if()
    }


    return (quantity);
}

char    *make_string(char *arr)//34lines
{
    char *our_figure;

    our_figure =ft_strnew(7);
    int i;
    int j;
    char x_offset;
    char y_offset;

    y_offset = 0;
    x_offset = 0;
    i = 0;
    j = 0;

    while (i <= 19)
    {
        if (arr[i] == '#')
        {
            our_figure[j] = x_offset + '0';
            j++;
            our_figure[j] = y_offset + '0';
            j++;
        }
        if (arr[i] == '\n')
        {
            y_offset++;
            x_offset = 0;
        }
        else
            x_offset++;
        i++;
    }
    return (our_figure);
}

int    check_figures(int qual_of_figures, char *arr)//15lines
{
    char *test_arr;
    while (qual_of_figures)
    {
        test_arr = make_string(arr);
        printf(YELLOW"%s\n"RESET, test_arr);
        if(check_is_figure_is_tetramino(test_arr) == -1)
        {
            printf(RED" ! "RESET);
            return(-1);
        }
        printf(CYAN" ! "RESET);
        if ((qual_of_figures-1))
            arr+=21;
        qual_of_figures--;
    }
    return (1);
}

int     check_validity(char *av)//9lines
{
    int qual_of_figures;
    int right_figures;
   // qual_of_figures = find_quantity_of_figures(av);
    qual_of_figures = find_quantity_of_figures(av, ft_strlen(av));
    printf("quantity of figures is : %i\n", qual_of_figures);
    right_figures =  check_figures(qual_of_figures, av);
    printf("right_figures is: %i\n", right_figures);
    if (right_figures > 0 && qual_of_figures > 0 && qual_of_figures <= 26)
        return (1);
    return (-1);
}