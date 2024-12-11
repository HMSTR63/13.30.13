/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:14:39 by aperez-b          #+#    #+#             */
/*   Updated: 2024/12/11 00:46:36 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

int main(void) {
    int fd1;
    int fd2;
    int i = 1;


    fd1 = open("test.txt", O_RDONLY);
    fd2 = open("test2.txt", O_RDONLY);

    char *buf;

    while ((buf = get_next_line(fd1))) {
        printf("Line %d for fd %d: %s", i, fd1, buf);
        free(buf);
        i++;
    }

    printf("\n---------------------------\n");
    i = 1;
    while ((buf = get_next_line(fd2))) {
        printf("Line %d for fd %d: %s", i, fd2, buf);
        free(buf);
        i++;
    }

    close(fd1);
    close(fd2);
    system("leaks a.out");
}
