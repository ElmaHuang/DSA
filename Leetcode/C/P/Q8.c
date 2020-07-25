/*
6.
費式數列 = 11,12,23,35,58,....N 
用一個函數,輸入值是位置的值(index),要找出相對應的值N
*/

#include <stdio.h>
 
int Fib(int index){
	int A0=11,
		A1=12;

	switch(index){
		case 0: return A0;
		case 1: return A1;
		default: return Fib(index-1)+Fib(index-2);
	}
}

int main(){
	int index;
	printf("find ? index val : \n");
	scanf("%d", &index);
	printf("A[%d] = %d", index, Fib(index));

}