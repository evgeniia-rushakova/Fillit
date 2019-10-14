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



int     check_validity(char *av);

int     main(int ac, char **av)
{
    int res;
    int result_of_validity;
    char	buf[BUF_SIZE + 1];
   res = read(open("../test", O_RDONLY), buf, BUF_SIZE);
   buf[res] = '\0';
   result_of_validity  = check_validity(buf);
   if (result_of_validity > 0)
       printf(GREEN "result of check_validity is ok: %i\n" RESET, result_of_validity);
   else
       printf(RED "result of check_validity is bad: %i\n" RESET, result_of_validity);
   return (0);
}
