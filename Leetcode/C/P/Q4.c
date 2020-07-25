/*
https://www.itread01.com/content/1499684526.html

1. 寫function return這個整數是不是2的次方 
(除了常見解法，還可以了解一下log解法)。
*/

/*gcc Q4.c -o Q4 
* .Q4 100
*/
#include <stdio.h>
#define false 1 
#define true 0 

int main(int argc, char *argv[]){ 
	//int val = argv[1];
	int val = 4;
	if(val & (val-1))
		return false;
	return true;
}