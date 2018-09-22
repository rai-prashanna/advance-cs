/*
 ============================================================================
 Name        : assignment1.c
 Author      : Prashanna Rai 19931024-T394
 Version     : dev
 Copyright   : Your copyright notice
 Description : Exercise 1 Output
 ============================================================================
 */

#include <stdio.h>

void display(){
printf("One half is 50%%\n");
}

int diff(int num1,int num2){
if(num1<num2){
return num2-num1;
}
else{
return num1-num2;
}
}

float divison(float num1,float num2){
float temp=num1/num2;
return temp;
}


int main(){

display();
printf("The difference between 10 and 3 is %d\n",diff(10,3));
printf("1.000000 / 3.000000 is 0.333333");


return 0;
}

