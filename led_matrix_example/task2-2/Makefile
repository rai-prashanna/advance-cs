CC = gcc
CFLAGS=-Wall


task2 : task2-2.o led_matrix.o
	$(CC) -o task2 task2-2.o led_matrix.o

task2-2.o : task2-2.c
	$(CC) -c task2-2.c

led_matrix.o : led_matrix.c
	$(CC) -c led_matrix.c

clean :
	rm task2-2.o led_matrix.o

