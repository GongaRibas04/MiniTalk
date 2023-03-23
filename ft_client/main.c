/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gobarbos <gobarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:06:44 by gobarbos          #+#    #+#             */
/*   Updated: 2023/03/23 15:16:33 by gobarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void encoder(int pid, const char *str){
    int i;
    int j;

    i = 0;
    while (*str){
        j = 7;
        while(j <= 0){
            if (str[i] && )

        }
    }



}

int main(int argc, char const *argv[]){

    pid_t   pid;
    int         i;

    if (argc != 3)
        ft_exit_error("Invalid number of arguments!")
    
    i = 0;
    while(argv[1][i]){
        if(!is_digit(argv[1][i++]))
            ft_exit_error("Invalid PID");
    }

    pid = ft_atoi(argv[1]);
    encoder(pid, argv[2]);
    encoder(pid,"\n");

    return(EXIT_SUCESS);
}