/*
  給你一個sort好的陣列a[20]，然後請你印出0~500的數字，如果數字在a[20]裡面，則不要印出，請你用最少的cpu和memory
*/

#include <stdio.h>

void Q1(int *a, int size){
	int *search = a;
	for(int i=0; i<=size; i++){
		if(*search == i)
			search++;
		else
			printf("%d\t", i);
	}

}

int main()
{
    int size = 500;
    int a[] = {1,7,8,13,17,20,21,23,34,35,
    		   44,56,66,67,68,99,100,145,155,200};
    Q1(a, size);
    return 0;
}
