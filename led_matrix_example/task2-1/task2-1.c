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

int main()
{
  int n = 8;
  pid_t pids[8];
  int row, col;

  if (open_led_matrix() == -1)
    {
      printf("Failed to initialize LED matrix\n");
      return -1;
    }

  clear_leds();

  /* Start children. */
  for (int i = 0; i < n; ++i)
    {
      if ((pids[i] = fork()) < 0)
        {
          perror("fork");
          abort();
        }
      else if (pids[i] == 0)
        {
          printf("\n inside child process %d  ", i);
          run_child(i);
          exit(0);

        }
    }

  /* Wait for children to exit. */
  int status;
  pid_t pid;
  while (n > 0)
    {
      pid = wait(&status);
      printf("\n Child with PID %ld exited with status 0x%x.\n", (long) pid,
          status);
      --n;  // TODO(pts): Remove pid from the pids array.
    }
  printf("\n inside parent process and about to exit ");

  clear_leds();
  if (close_led_matrix() == -1)
    {
      printf("Could not properly close LED matrix\n");
      return -1;
    }

  return 0;
}


