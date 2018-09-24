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

#include "led_matrix.h"

void
sleep_ms(int milliseconds)
{
  usleep(1000 * milliseconds);
}

int main()
{

  if (open_led_matrix() == -1)
    {
      printf("Failed to initialize LED matrix\n");
      return -1;
    }
  int row, col;
  clear_leds();

  pid_t pid = fork();
  if (pid == 0)
    {
      row = 0;
      col = 0;
      for (int row = 0; row < 6; row++)
        {
          printf("I’m the child! Lighting LED at (%d, %d).....\n", row, col);
          set_leds_single_color(RGB565_WHITE);
          sleep_ms(2000);
        }
    }
  else
    {
      row = 0;
      col = 0;
      for (int col = 0; col < 6; col++)
        {
          printf("I’m the parent! Lighting LED at (%d, %d).....\n", row, col);
          set_leds_single_color(RGB565_RED);
          wait(NULL);
          sleep_ms(2000);
          clear_leds();

        }
    }

  if (close_led_matrix() == -1)
    {
      printf("Could not properly close LED matrix\n");
      return -1;
    }
  return 0;
}


