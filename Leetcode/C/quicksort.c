/*
void sort(int* Nums,int Low,int High)
{
    if(Low<High)
    {
        int i=Low,j=High,temp=Nums[Low];
        while(i!=j)
        {
            while(i<j&&temp<Nums[j])--j;
            if(i<j)Nums[i++]=Nums[j];
            while(i<j&&temp>Nums[i])++i;
            if(i<j)Nums[j--]=Nums[i];
        }
        Nums[i]=temp;
        sort(Nums,Low,i-1);
        sort(Nums,i+1,High);
    }
}

作者：liu-shuo-7
链接：https://leetcode-cn.com/problems/k-diff-pairs-in-an-array/solution/c_shu-zu-zhong-de-k-diffshu-dui-by-liu-shuo-7/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

#include <stdio.h>

void swap(int * a, int *b){
    int *tmp=a;
    a=b;
    b=tmp;    
}

int * quicksort(int * nums, int left_idx, int right_idx){
    int pivot, i, j;
    if(left_idx >= right_idx) return;
    pivot = nums[left_idx];
    i = left_idx + 1;
    j = right_idx;

    while (1){
        while (i <= right_idx){
            if (nums[i] > pivot) break;
            i ++;
        }
        while (j>left_idx){
            if (nums[j] < pivot)break;
            j--;
        }
        if(i > j)break;
        swap(nums+i, nums+j);
    }
    swap(nums+left_idx, nums+right_idx);

    quicksort(nums, left_idx, j-1);
    quicksort(nums, j + 1, right_idx);
    return nums;
}

int main()
{
    int * nums = {3, 1, 4, 1, 5};
    quicksort(nums,0,4);

    return 0;
}
