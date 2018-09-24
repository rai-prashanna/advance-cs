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


void sleep_ms(int milliseconds) {
	usleep(1000 * milliseconds);
}

int main() {

	if (open_led_matrix() == -1) {
		printf("Failed to initialize LED matrix\n");
		return -1;
	}
	
	clear_leds();

	/* Flash predefined colors */	
	set_leds_single_color(RGB565_WHITE);
	sleep_ms(500);
	set_leds_single_color(RGB565_RED);
	sleep_ms(500);
	set_leds_single_color(RGB565_GREEN);
	sleep_ms(500);
	set_leds_single_color(RGB565_BLUE);
	sleep_ms(500);
	set_leds_single_color(RGB565_CYAN);
	sleep_ms(500);
	set_leds_single_color(RGB565_MAGENTA);
	sleep_ms(500);
	set_leds_single_color(RGB565_YELLOW);
	sleep_ms(500);
	
	clear_leds();

	/* Show gradient */
	int red_val = 63;
	int blue_val = 255;
	uint16_t color;
	for (int row = 0; row < ROW_SIZE; row++) {
		for (int col = 0; col < COL_SIZE; col++) {
			red_val += 3;
			blue_val -= 3;
			color = make_rgb565_color(red_val, 0, blue_val);
			set_led(row, col, color);
			sleep_ms(50);
		}
	}

	sleep_ms(2000);

	/* Do the crab! */
	uint16_t W = RGB565_WHITE;
	uint16_t R = RGB565_RED;
	uint16_t G = RGB565_GREEN;
	uint16_t B = RGB565_BLUE;
	uint16_t Y = RGB565_YELLOW;

	uint16_t crab_image1[NUM_LEDS] = 
		{B, B, W, W, B, W, W, B,
		 B, B, 0, W, B, 0, W, B,
		 B, B, B, R, B, B, R, B,
		 B, B, B, R, B, B, R, B,
		 R, R, B, R, R, R, R, R,
		 B, R, R, R, 0, 0, R, R,
		 R, R, Y, R, R, R, R, R,
		 Y, Y, Y, R, Y, R, Y, R};

	uint16_t crab_image2[NUM_LEDS] = 
		{B, B, W, W, B, W, W, B,
		 B, B, 0, W, B, 0, W, B,
		 B, B, B, R, B, B, R, B,
		 B, B, B, R, B, B, R, B,
		 R, R, B, R, R, R, R, R,
		 R, R, R, R, 0, 0, R, R,
		 Y, Y, Y, R, R, R, R, R,
		 Y, Y, Y, R, Y, R, Y, R};

	for (int i = 0; i < 10; i++) {
		set_leds_image(crab_image1);
		sleep_ms(500);
		set_leds_image(crab_image2);
		sleep_ms(500);
	}
	
	sleep_ms(2000);
	clear_leds();

	if (close_led_matrix() == -1) {
		printf("Could not properly close LED matrix\n");
		return -1;
	}

	return 0;
}

