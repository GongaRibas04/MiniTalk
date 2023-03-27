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
    result = 0;
    while (str[i]){
        rslt <<= 1;
        if (str[i] == '1')
            result++;
        i++;
    }
    return rslt;
}

static void handler(int signal, siginfo_t *info, void *cont){
    static int  i;
    static char  *c;


    (void)cont;
    (void)info;

    if (!c)
        c = (char*)malloc(sizeof(char) * 8);
    if (!i)
        i = 0;
    if (signal == SIGUSR1)
        c[i] = '1';
    else
        c[i] = '0';
    if (++i == 8)
        ft_printf("%c", decoder(c))
}

int main(void){
    pid_t   pid;
    struct sigaction sa;

    pid = getpid();
    ft_printf("Server PID: %d\n", pid);
    while(1){
        sa.sa_sigaction = &handler;
        sa.sa_flags = SA_SIGINFO;
    }
}