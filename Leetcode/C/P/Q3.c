/*
這題比較算是情境題，在該情況下依照題目需求解題，因此去深究其中題目的實現的可行性是沒有意義的。(這是我自己的理解，或許是我對題目的掌握不足，因此建議參考就好)
這題會先給一個情境設定如下：

struct ListStruct{
    unsigned int DataH;
    unsigned int DataL;
    unsigned int NextPtr;
};
struct ListStruct ListArray[1000];
#define NULL 0xFFFF
unsigned int ListHead = 0;


//*條件一：ListArray[Entry1].NextPty = ListArray[Entry2]
//*條件二：ListArray[Entry2].DataH << 16 + ListArray[Entry2].DataL > ListArray[Entry1].DataH << 16 + ListArray[Entry1].DataL

請寫一個function(unsigned DATA_A, unsigned DATA_B)，
能在ListArray中找到符合ListArray[Entry].DataH == Data_A 且 ListArray[Entry].DataL == Data_B
並印出其結果。如果沒有找到的話，印出"no found."。

*/
/*
這題我記得不是很清楚，主要是考用Array來做;inked list，題目會給ㄧ個struct
struct node{
  unsigned int Data_H;
  unsigned int Data_L;
  unsigned int next;

}

有一個陣列A[500]，裡面都是存node的struct，假設第一個開頭index叫做listhead，
那我們要access這個list的第一個struct node就是A[listhead]，
然後再透過struct node 裡的next找到下一個struct node，直到next是null，
如果next是null就代表示list最後一個結點。題目會

#define null 0xffff

在來就是要透過給予的兩個值DATA_A和DATA_B來尋找我們要的node有沒有在A[500]裡面。
check是否在陣列裡的方式會用計算Data_A<<4+Data_B會不會等於DATA_H<<4+DATA_L，
另外題目又有說DATA_H<<4+DATA_L會越來越大，所以不用搜尋到最後。
如果找到就是印出找到node的index(FoundEntry)，和它前一個node的index(PreEntry)。如果不在也是要印找不到。
*/

#include <stdio.h>
#include <stdlib.h>

#define null 0xffff
#define listhead 0
#define false 0
#define true 1

struct ListStruct{
    unsigned int DataH;
    unsigned int DataL;
    unsigned int NextPtr;
};

void Q3(struct ListStruct *A, int size, int Data_A, int Data_B){
	struct ListStruct *search = &A[listhead];
	//struct ListStruct sea = A[listhead];
	unsigned int PrePtr;
	int index = listhead;
	int found = false;

	while(index < size){
	   //printf("sea.DataH %u\n",(A[index].DataH));
	   // printf("search->DataL %u\n",(search->DataL));
	   // printf("search->DataH<<4 %u\n",(search->DataH<<4));
	   // printf("search->DataH<<4+search->DataL %u\n",(search->DataH<<4+search->DataL));
		if(search->DataH<<4+search->DataL == Data_A<<4+Data_B){
			found = true;
			if(index == listhead)
				printf("Entry index is listhead, PreEntry is NULL,NextEntry is %d.\n", search->NextPtr);
			else
				printf("Entry index is %d, PreEntry is %d, NextEntry is %d.\n", index, PrePtr, search->NextPtr);

            break;
		}else if(search->DataH << 16 + search->DataL > Data_A << 16 + Data_B){
			break;
		}else{
			PrePtr = index;
			index = search->NextPtr;
			search = &A[index];
		}
	}
	if(!found) printf("Not Found.\n");
}

int main(){
	int size = 20;
	struct ListStruct A[size];
	for(int i =0; i< size; i++){
	    struct ListStruct *new = malloc(sizeof(struct ListStruct));
	    //unsigned int v = i;
	    new->NextPtr = i+1;
	    new->DataH = i;
	    new->DataL = i;
	    A[i] = *new;
	}
	int DATA_A = 4,
		DATA_B = 4;
	Q3(A, size, DATA_A, DATA_B);
	return 0;
}