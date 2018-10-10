/*
 * Calculate an estimate of pi using a Monte Carlo method.
 *
 * This program is multithreaded using pthreads for a possible speed-up.
 * (But don't use a Monte Carlo method in the first place if you actually
 * require an efficient algorithm for computing digits of pi.)
 *
 * Written by Pontus Ekberg <pontus.ekberg@it.uu.se>
 * Lat updated: 2018-09-26
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS	1
#define NUM_TRIALS	100000000

/* Define a data type for the arguments to pass to the functions of threads. */
struct thread_arg_t {
	/* The index of the thread, from 0 to NUM_THREADS-1. */
	unsigned int index;
	/* The result of the thread's approximation of pi. 
	 * The thread puts its return value here. */
	double result; 
};


/* Generate a random double in the range [min, max]. 
 * 
 * Uses the thread_safe rand_r() instead of rand(), so we need to also pass
 * a pointer to the seed state as an argument. */
double rand_range(double min, double max, unsigned int *seed) {
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand_r(seed) / div);
}


/* 
 * The function each new thread should call.
 *
 * By the pthreads standard this needs to take and return a void pointer.
 * The pointer we pass to this function is really a pointer to a struct
 * thread_arg_t, and so we safely cast it to that type in the function.
 */
void *approximate_pi_pthread_runnable(void *arg) {
	/* Cast the argument from void* to its proper type. */
	struct thread_arg_t *targ = arg; 
	/* Add index to seed to make sure that different threads get different
	 * seeds even if they are created so close in time that time() returns 
	 * the same value. */
	unsigned int random_seed = time(NULL) + targ->index;

	int trials_per_thread = NUM_TRIALS / NUM_THREADS;
	double x, y;
	int hits = 0;
	
	for (int i = 0; i < trials_per_thread; i++) {
		/* Get a uniformly random coordinate in the square from with
		 * cornerns in (-1, -1) and (1, 1). */
		x = rand_range(-1, 1, &random_seed);
		y = rand_range(-1, 1, &random_seed);
		/* Count the number of random coordinates that are also within the
		 * maximal inscribed circle. */
		if (x*x + y*y <= 1) {
			hits++;
		}
	}

	/* We approximate pi as 4 times the fraction of random coordinates that
	 * were inside the inscribed unit circle. */
	targ->result = 4.0 * hits / trials_per_thread;
	return NULL;
}

int main() {
	pthread_t threads[NUM_THREADS]; /* An array of the threads. */
	struct thread_arg_t args[NUM_THREADS]; /* One argument struct per thread. */
	
	/* Create (and run) all the threads. */
	for (int i = 0; i < NUM_THREADS; i++) {
		args[i].index = i;
		if (pthread_create(&threads[i], NULL, 
				approximate_pi_pthread_runnable, &args[i])) {
			fprintf(stderr, "Error creating thread #%d!\n", i);
			exit(1);
		}
	}

	/* Block until all threads are finished. */
	for (int i = 0; i < NUM_THREADS; i++) {
		pthread_join(threads[i], NULL);
	}

	/* Sum the results of the individual threads. */
	double pi = 0;
	for (int i = 0; i < NUM_THREADS; i++) {
		pi += args[i].result;
	}
	/* The average of the threads' approximations is the same as the
	 * approximation that a single thread doing all the trials itself would
	 * have gotten. (Convince yourselves of this.) */
	pi = pi / NUM_THREADS;

	printf("pi ~= %lf calculated with %d trials split on %d threads\n",
		   	pi, NUM_TRIALS, NUM_THREADS);
}
