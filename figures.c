#include "libft.h"
#include <stdio.h>
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

int         find_offset(char *src)//находит смещение оставить тут
{
    int		min;
    int		i;
    int		j;

    j = 0;
    while (src[j] != '\0')
        j++;
    i = 2;
    min = src[0];
    while (i < j)
    {
        if(src[i] < min)
            min = src[i];
        i = i + 2;
    }
    return (min - '0');
}

char *change_example(char *example, int x_offset, int y_offset)//16lines//перекинуть ее в утилс и пользоваться при координатах
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
    static char base_of_figures[19][8] = {"00010203", "00102030","00100111","00010212",
                                     "00102001", "00101112", "20011121","10110212",
                                     "00011121", "00100102","00102021","10011121",
                                     "00011102", "00102011", "10011112","10200111",
                                     "00011112", "00101121", "10011102"};
    i = 0;
    while(i <= 18)
    {
        x_offset = find_offset(&our_figure[0]);
        y_offset = find_offset(&our_figure[1]);
        changed_example = change_example(base_of_figures[i], x_offset, y_offset);
        if(ft_strcmp(base_of_figures[i], our_figure) == 0 || ft_strcmp(changed_example, our_figure) == 0)
        {
            printf("validate figures returned 1\n");
            return (1);
        }
        //free(changed_example);
        i++;
    }
    return (-1);
}

int     find_quantity_of_figures(char *str, size_t len)//23lines//нужная функция переместить в мэин или еще куда
{
    size_t size_of_dots;
    size_t size_of_sharps;
    size_t size_of_slashn;
    size_t qual;

    qual = (len - 20) / 21 + 1;
    size_of_dots = 0;
    size_of_sharps = 0;
    size_of_slashn = 0;
    while(*str)
    {
        if(*str == '.')
            size_of_dots++;
        else if(*str == '#')
            size_of_sharps++;
        else if(*str == '\n')
            size_of_slashn++;
        str++;
    }
     if(qual * 4 != size_of_sharps || qual * 12 != size_of_dots || (size_of_slashn != (qual * 5 - 1)))
         return (-1);
    return (qual);
}

char    *make_string(char *arr, char *result)//25lines//написать обратную функцию для печати
{
    int i;
    char x_offset;
    char y_offset;

    y_offset = 0;
    x_offset = 0;
    i = -1;
    while (i++ <= 19)
    {
        if (arr[i] == '#')
        {
            *result++ = x_offset + '0';
            *result++ = y_offset + '0';
        }
        if (arr[i] == '\n')
        {
            y_offset++;
            x_offset = 0;
        }
        else
            x_offset++;
    }
    return (result - 8);
}

int    check_figures(int qual_of_figures, char *arr)//15lines//оставляем тут
{
    char *test_arr;
    while (qual_of_figures >= 0)
    {
        test_arr = make_string(arr, ft_strnew(7));
        if(check_is_figure_is_tetramino(test_arr) == -1)
        {
            printf(RED" error! "RESET);
            return(-1);
        }
        printf(CYAN" ok!\n"RESET);
        if ((qual_of_figures - 1))
            arr+=21;
        qual_of_figures--;
    }
    return (1);
}

int     check_validity(char *av)//9lines//оставляем тут
{
    int qual_of_figures;
    int right_figures;
    qual_of_figures = find_quantity_of_figures(av, ft_strlen(av));
    printf("quantity of figures is : %i\n", qual_of_figures);
    if (qual_of_figures)
        right_figures =  check_figures(qual_of_figures, av);
    printf("right_figures is: %i\n", right_figures);
    if (right_figures > 0 && qual_of_figures > 0 && qual_of_figures <= 26)
        return (1);
    //free(golova spiska)
    return (-1);
}