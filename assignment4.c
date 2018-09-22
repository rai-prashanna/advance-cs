/*
 ============================================================================
 Name        : Assignment4.c
 Author      : Prashanna Rai 19931024-T394
 Version     : dev
 Copyright   : Your copyright notice
 Description : Exercise 4 Loops
 ============================================================================
 */



#include <stdio.h>
#include <stdlib.h>

void displayEvenNumbers(){
printf("Even numbers between 0 and 40:");
printf("\n");
for(int i=0;i<=40;i++){
if(i%2==0){
	printf("%d ",i);
}
}
printf("\n");
}

void displayNumbersInRow(){

int i=1;
printf("Numbers 1 to 100:\n");
while(i<=100){
for(int j=0;j<10;j++){
printf("%2d ",i);
i++;
}
	printf("\n");
}
}


void displaySquare(){
	while(1){
	printf("Give a number: ");
	int x;
	scanf("%d", &x);
	if(x==0){
	printf("You entered zero.");
	break;
	}
	else {
		printf("The square of %d is %d \n",x,x*x);
	}

	}
}


int main(){
displayEvenNumbers();
displayNumbersInRow();
displaySquare();
return 0;

}

