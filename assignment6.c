/*
 ============================================================================
 Name        : Assignment6.c
 Author      : Prashanna Rai 19931024-T394
 Version     : dev
 Copyright   : Your copyright notice
 Description : Exercise 6 Functions
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

float findMin(float f1,float f2){
	if(f1<f2){
		return f1;
	}
	else{
		return f2;
	}
}

float findMinWithFour(float f1, float f2, float f3,float f4){
	float temp1=findMin(f1,f2);
	float temp2=findMin(f3,f4);
	return findMin(temp1,temp2);
}

float findMax(float f1,float f2){
	if(f1>f2){
		return f1;
	}
	else{
		return f2;
	}
}

float findMaxWithFour(float f1, float f2, float f3,float f4){
	float temp1=findMax(f1,f2);
	float temp2=findMax(f3,f4);
	return findMax(temp1,temp2);
}

float findSumFour(float f1, float f2, float f3,float f4){

	return f1+f2+f3+f4;
}


int main(void) {
	float f1,f2,f3,f4;
	printf("Give four floats: "); /* prints assignmet4 */
	scanf("%f %f %f %f",&f1,&f2,&f3,&f4);
	printf("min: %f\n",findMinWithFour(f1,f2,f3,f4));
	printf("max: %f\n",findMaxWithFour(f1,f2,f3,f4));
	float temp=findSumFour(f1,f2,f3,f4)/4;
	printf("sum: %f\n",findSumFour(f1,f2,f3,f4));
	printf("mean: %f",temp);
	return 0;
}
