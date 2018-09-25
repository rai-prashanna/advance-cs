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

    for( int col=0; col<8; col++)
      {
        pointless_calculation();
printf("inside child process  (%d,%d) \n",row,col);
        set_led(row, col, RGB565_GREEN);
exit(0);
      }
  }


int main()
{
int num_of_child=8;
  if (open_led_matrix() == -1)
    {
      printf("Failed to initialize LED matrix\n");
      return -1;
    }
  int row, col;
  clear_leds();


for(int num_child=0;num_child<8;num_child++){
    for(int n=0;n<num_child;n++){
        if(fork()==0)
          {
          
            run_child(n);
exit(0);
          }
        else{
while(1){
if(num_of_child==0){
    break;
}
printf("inside parent process \n");
wait(NULL);
sleep_ms(1000);
--num_of_child;
}
printf("inside parent process and clearing all leds \n");
clear_leds();
 
        }
    }
}
  if (close_led_matrix() == -1)
    {
      printf("Could not properly close LED matrix\n");
      return -1;
    }
  return 0;
}


