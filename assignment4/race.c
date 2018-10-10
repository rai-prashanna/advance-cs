#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define COUNT_PER_THREAD 10 /* Modify this */

int counter = 0; /* The shared counter */

void *loop_increment(void *arg) {
	
	/* Increment the counter COUNT_PER_THREAD times */
	for (int i = 0; i < COUNT_PER_THREAD; i++) {
		counter++;
	}
	
	return NULL;
}

int main() {
	pthread_t thread1, thread2;
	
	/* Create two identical threads, executing the same function */
	if (pthread_create(&thread1, NULL, loop_increment, NULL)) {
		fprintf(stderr, "Error creating thread1.\n");
	}
	if (pthread_create(&thread2, NULL, loop_increment, NULL)) {
		fprintf(stderr, "Error creating thread2.\n");
	}

	/* Wait for the threads to terminate */
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("counter = %d\n", counter);
	return 0;
}

