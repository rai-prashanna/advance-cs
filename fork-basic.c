/*
 * led_example.c - Shows off how to use the functions declared in led_matrix.h
 *
 * Written by Pontus Ekberg <pontus.ekberg@it.uu.se>
 * Last updated 2018-08-21
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

int main( void )
{
    printf( "[dad] pid %d\n", getpid() );

    for ( int i = 0; i < 4; i++ )
        if ( fork() == 0 )
        {
            printf( "[son] pid %d from pid %d\n", getpid(), getppid() );
            exit( 0 );
        }

    for ( int i = 0; i < 3; i++ )
        wait( NULL );
}

