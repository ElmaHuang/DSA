/*
  類似上題，function給一個數字b=0,1,2,3,4時，
  分別印出0~99,100~199,200~299,300~399,400~499之中，
  不在a[20]裡面的數字，
  也是用最少的CPU跟memory。
  (我認為不需要用到switch case)
  (500要比較 ???)
*/
#include <stdio.h>

void Q2(int *a, int size, int b){
	//int idx = 0;
	int *search = a;
	//array sorting過
	//小於直接++
	while(*search < b*100){
		search++;
	}
	//開始比較
	for(int i = b*100; i<(b+1)*100; i++){
		if(*search != i)
		    printf("%d\t", i);
		else
		    search++;
	}
	//compare 500
	// while(idx<size && b ==4)
	//     if(*search != 500){
	//         printf("%d\t",500);
	//         break;
	//     }
	//     idx++;
	    
	printf("\n");
}

int main(){
    int size = 20;
	int a[] = {1,7,8,13,17,20,21,23,34,35,
              44,56,66,67,68,99,100,145,155,499};
    for(int j = 0; j<5; j++)
        Q2(a, size, j);
    return 0;
}