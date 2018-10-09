CC = gcc
CFLAGS=-Wall


task2-1 : task2-1.o led_matrix.o
	$(CC) -o task2-1 task2-1.o led_matrix.o

task2-1.o : task2-1.c
	$(CC) -c task2-1.c

led_matrix.o : led_matrix.c
	$(CC) -c led_matrix.c

clean :
	rm *.o task2-1

