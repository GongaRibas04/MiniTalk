/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gobarbos <gobarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:06:04 by gobarbos          #+#    #+#             */
/*   Updated: 2023/03/27 11:23:40 by gobarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../minitalk.h"

static int  decoder(char *str){
    int i;
    int rslt;

    i = 0;
    rslt = 0;
    while (str[i]){
        rslt <<= 1;
        if (str[i] == '1')
            rslt += 1;
        i++;
    }
    return rslt;
}

static void handler(int signal){
    static int  i;
    static char  *c;

    if (!c)
        c = (char*)malloc(sizeof(char) * 8);
    if (!i)
        i = 0;
    if (signal == SIGUSR1)
        c[i] = '1';
    else
        c[i] = '0';
    if (++i == 8){
        ft_printf("%c", decoder(c));
        c = 0;
        i = 0;
    }
}

int main(void){
    pid_t   pid;
    struct sigaction sa;

    pid = getpid();
    ft_printf("Server PID: %d\n", pid);
    while(1){
        sa.sa_handler = &handler;
        sa.sa_flags = SA_SIGINFO;
        if (sigaction(SIGUSR1, &sa, NULL) == -1)
            ft_exit_error("Couldn't chande SIGUSR1.");
        if (sigaction(SIGUSR2, &sa, NULL) == -1)
            ft_exit_error("Couldn't chande SIGUSR2.");   
    }
}