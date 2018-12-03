[922. Sort Array By Parity II](https://leetcode.com/problems/sort-array-by-parity-ii/)

```c++
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A){
        int size = A.size();
        int even_index = 0, odd_index =1;
        //the latest index is odd.        
        while(even_index < size){
           if(is_even(A[even_index])){
               even_index+=2;//符合即加2
               continue;
           }else if(is_odd(A[odd_index])){
               odd_index+=2; 
               continue;
           }else{
               swap_item(A,even_index,odd_index);
               even_index+=2;
               odd_index+=2;
           }
        }
        return A;
    }    
    bool is_odd(int num){
        return num &1;        
    }    
    bool is_even(int num){
        return !(num & 1);
    }    
    void swap_item(vector<int>& A,int i,int j){
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    
};

//total.assign(A.begin(),A.end());
```
[183. Customers Who Never Order](https://leetcode.com/problems/customers-who-never-order/)

```mysql
# Write your MySQL query statement below
SELECT A.Name as 'Customers' from Customers A
WHERE A.Id NOT IN (
    SELECT B.CustomerId from Orders B
)

```
[643. Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/)
