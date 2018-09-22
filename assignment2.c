/*
 ============================================================================
 Name        : assignment2.c
 Author      : Prashanna Rai 19931024-T394
 Version     : dev
 Copyright   : Your copyright notice
 Description : Exercise 2 Input
 ============================================================================
 */

#include <stdio.h>

void product(float a,float b)
{
printf("You entered %f and %f, their product is: %f \n",a,b,a*b);
}

void sum(int a,int b){
printf("You entered %d and %d, their sum is: %d \n",a,b,a+b);
}

void display(char* input){
printf("%s %s",input ,input);
}

int main()
{

int num1,num2;
float a,b;
char word[23];
printf("Give two integers: ");
scanf("%d %d",&num1,&num2);
sum(num1,num2);
printf("Give two floats: ");
scanf("%f %f",&a,&b);
product(a,b);

printf("Give a word: ");
scanf("%s", word);
display(word);


return 0;
}
