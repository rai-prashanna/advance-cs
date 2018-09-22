/*
 ============================================================================
 Name        : assignment3.c
 Author      : Prashanna Rai 19931024-T394
 Version     : dev
 Copyright   : Your copyright notice
 Description : Exercise 3 Conditionals
 ============================================================================
 */

#include <stdio.h>

void checkZero(int a){
if(a!=0){
printf("The number you entered does not equal zero\n");
}
else{
printf("The number you entered equals zero\n");
}
}

void findGrt(float a, float b){
if(a>b){
printf("%f is the largest\n",a);
}
else{
printf("%f is the largest\n",b);
}
}

int task(int a){
if(a%2==0){
return a/2;
}
else{
return a*3;
}
}


void comp(int a,int b,int c)
{
if((a==b || b==c || a==c)){
printf("Some numbers are equal\n");
}
else
{
printf("All are unique\n");
}
}
int main(){

int input1;
printf("Give an integer: ");
scanf("%d",&input1);
checkZero(input1);

float num1,num2;
printf("Give two floats: ");
scanf("%f %f",&num1,&num2);
findGrt(num1,num2);

printf("Give an integer: ");
int p;
int out;
scanf("%d",&p);

out=task(p);
printf("Result is: %d\n",out);

printf("Give three integers: ");
int x,y,z;
scanf("%d %d %d", &x,&y,&z);
comp(x,y,z);
return 0;
}
