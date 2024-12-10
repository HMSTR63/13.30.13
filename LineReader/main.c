/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:14:39 by aperez-b          #+#    #+#             */
/*   Updated: 2024/12/10 17:50:35 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>

int main(void) {
    int fd1;
    int fd2;
    int i = 1;


    fd1 = open("test.txt", O_RDONLY);
    fd2 = open("test2.txt", O_RDONLY);

    char *buf;

    while ((buf = get_next_line(fd1))) {
        printf("Line %d for fd %d: %s\n", i, fd1, buf);
        free(buf);
        i++;
    }

    printf("\n---------------------------\n");

    while ((buf = get_next_line(fd2))) {
        printf("Line %d for fd %d: %s\n", i, fd2, buf);
        free(buf);
        i++;
    }

    close(fd1);
    close(fd2);
}
