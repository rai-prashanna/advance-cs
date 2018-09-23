/*
 ============================================================================
 Name        : test.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 * led_example.c - Shows off how to use the functions declared in led_matrix.h
 *
 * Written by Pontus Ekberg <pontus.ekberg@it.uu.se>
 * Last updated 2018-08-21
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
pid_t pid = fork();
/* Do error handling for fork() */
if (pid == 0) {
printf("I'm the child!\n");
/* #execl("/bin/ls", "ls", "-l", "/home/sork/", (char *) NULL); */
execl("/bin/ls", "ls", "-l", "/home/", (char *) NULL);

perror("Failed to exec new program");
} else {
printf("I'm the parent! Waiting for %d...\n", pid);
wait(NULL);
printf("Child has terminated.\n");
}
return 0;
}

