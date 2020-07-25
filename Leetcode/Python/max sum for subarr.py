"""
https://www.youtube.com/watch?v=86CQq3pKSUw
https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
Kadane's Algorithm to Maximum Sum Subarray Problem : O(n)

tow for loop scan every items: brute force  solution : O(n^2)
"""

# Python program to find maximum contiguous subarray 

# Function to find the maximum contiguous subarray 
#from sys import maxint 
def maxSubArraySum(a,size):	
	max_sum = max(a)
	max_curr = 0	
	for i in range(0, size): 
		max_curr = max(a[i], max_curr+a[i]) # Kadane's algorithm
		max_sum = max(max_sum, max_curr) 
	return max_sum 

# Driver function to check the above function 
#a = [-13, -3, -25, -20, -3, -16, -23, -12, -5, -22, -15, -4, -7] 
#a = [1,2,3,-2,5] 
a = [-1,-2,-3,-4] 
print "Maximum contiguous sum is", maxSubArraySum(a,len(a)) 