/*
 ============================================================================
 Name        : task2.1.c
 Author      : prashanna-rai
 Version     : dev
 Copyright   : Your copyright notice
 Description : fork()
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "led_matrix.h"

void sleep_ms(int milliseconds)
{
    usleep(1000 * milliseconds);
}

/*
 * Do some pointless CPU - heavy computations . Takes about 1 second
 * to complete on a single core of the ARM Cortex A53 processor of
 * the Raspberry Pi 3 model B with default gcc 6.3.0 op tim iz at io ns .
 */
void pointless_calculation()
{
    int amount_of_pointlessness = 100000000;
    int x = 0;
    for (int i = 0; i < amount_of_pointlessness; i++)
    {
        x += i;
    }
}

void run_child(int row)
{

    for (int col = 0; col < 8; col++)
    {
        pointless_calculation();
        printf("inside child process  (%d,%d) \n", row, col);
        set_led(row, col, RGB565_GREEN);
    }
}

int main ()
{
    if ( open_led_matrix () != 0)
    {
        printf("Failed to initialize LED matrix\n");
        exit (-1) ;

    }

    run_child (0) ; // Argument corresponds to row ...

    usleep (1000000) ;
    clear_leds () ;

    if ( close_led_matrix () != 0)
    {
        printf("Could not properly close LED matrix\n");
        exit (1) ;

    }

    return 0;

}



 
