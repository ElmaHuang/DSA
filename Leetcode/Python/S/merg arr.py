"""
https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/
Efficiently merging two sorted arrays with O(1) extra space
Input: ar1[] = {10};
       ar2[] = {2, 3};
Output: ar1[] = {2}
        ar2[] = {3, 10}  

Input: ar1[] = {1, 5, 9, 10, 15, 20};
       ar2[] = {2, 3, 8, 13};
Output: ar1[] = {1, 2, 3, 5, 8, 9}
        ar2[] = {10, 13, 15, 20} 
"""
'''
https://www.geeksforgeeks.org/merge-two-sorted-arrays-o1-extra-space/
# Merge ar1[] and ar2[] with O(1) extra space 
def merge(ar1, ar2, m, n):  
    # Iterate through all elements of ar2[] starting from  the last element 
    # Find the smallest element greater than ar2[i]. Move all elements one position ahead 
    # till the smallest greater element is not found  
    for i in range(n-1, -1, -1):       
        last = ar1[m-1] 
        j= m-2
        while j >= 0 and ar1[j] > ar2[i] : 
            ar1[j+1] = ar1[j] 
            j-=1
   
        # If there was a greater element 
        if j != m-2 or last > ar2[i]:          
            ar1[j+1] = ar2[i] 
            ar2[i] = last 
'''
import math

def  mergesort(a1,a2,n, m):
	#get two pointer
	size = n+m
	mid = size/2
	while mid > 0:
	    i = 0
	    #j = 0
	    while mid+i < n:
	        if a1[i] > a1[mid+i]:a1[i], a1[mid+i] = a1[mid+i],a1[i]
	        i += 1
        j = mid - n if mid > n else 0
        while i < n and j < m: 
            if a1[i] > a2[j]:a1[i], a2[j] = a2[j], a1[i]
            i += 1
            j += 1
    	#if i = n
    	if i>=n and j < m:
    	    # comparing elements in the second array. 
    	    i = 0
    	    while j < m : 
    	        if (a2[i] > a2[j]): 
    	            a2[j], a2[i] = a2[i], a2[j]
                j += 1
        print(str(a1))
        print(str(a2))
        print("\n")
        mid = mid/2
                  
    
			
mergesort([3,27,38,43],[9,10,82],4,3)