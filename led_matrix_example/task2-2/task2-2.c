/*
 ============================================================================
 Name        : task2.2.c
 Author      : prashanna-rai
 Version     : dev
 Copyright   : Your copyright notice
 Description : fork() with nice value
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "led_matrix.h"

void run_child(int row)
{
    for (int col = 0; col < 8; ++ col)
    {
        pointless_calculation () ;
        printf("inside child process  (%d,%d) \n", row, col);
        set_led (row, col, RGB565_GREEN );
    }
}

void pointless_calculation()
{
    int x = 0;
    int amount_of_pointlessness = 100000000;
    for (int i = 0; i < amount_of_pointlessness ; ++ i)
        x += i;
}


int main ()
{
    int n = 8;
    pid_t pid;
    int row, col;
    if (open_led_matrix() != 0)
   {
        perror (" Failed to initialize LED matrix \n") ;
        exit(-1) ;
    }
    else
    {
        for (int num_children = 0; num_children < n; ++ num_children )
        {
            for (int n = 0; n < num_children ; ++ n )
            {
                pid_t pid = fork () ;

                while ( pid < 0)
                {
                    perror (" error creating fork \n");
                    pid = fork () ;
                }

                if ( pid == 0)
                {
                    run_child ( n);
                    exit (0) ;
                }
            }

            for (int n = 0; n < num_children ; ++ n )
            {
                wait(NULL);
            }

            usleep(1000000) ;
            clear_leds() ;
        }

        if ( close_led_matrix () != 0)
        {
            perror ("Could not properly close LED matrix\n");
            exit(-1) ;
        }
    }

    return 0;

}

