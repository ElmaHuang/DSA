/*
https://www.sitesbay.com/program/c-program-print-triangle-of-star
4.印出
    *
   **
  ***
 ****
*****
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int i,j;
	//char item = "*";
	int level = 5;
	char row[level];
	for(i=1; i<=5; i++){
		memset(row, "\t", level); //init
		memcpy(&j, &i, sizeof(j));
		while(j>0){
			row[level - j] = '*';
			j--;
		}
		printf("%s\n", row);
	}
}