"""
https://www.geeksforgeeks.org/total-number-of-possible-binary-search-trees-with-n-keys/
https://www.geeksforgeeks.org/program-nth-catalan-number/
countBST(n) = Catalan number Cn = (2n)! / ((n + 1)! * n!)
Convert a normal BST to Balanced BST

countBT(n) = countBST(n) * n!
"""
def factorial(n):
	base = 1
	for i in range(1,n+1):
		base = base*i
	return base

def catalan(n):
	#(1*2*...*2n)/(1*2*....*n)(1*2*...*n+1)
	return factorial(2*n)/(factorial(n)*factorial(n+1))

'''
def binomialCoefficient(n, k): 
    # since C(n, k) = C(n, n - k) 
    if (k > n - k): 
        k = n - k 
    # initialize result 
    res = 1  
    # Calculate value of [n * (n-1) *---* (n-k + 1)] / [k * (k-1) *----* 1] = (n!/k!) /(n-k)!
    for i in range(k):
        res = res * (n - i) 
        res = res / (i + 1) 
    return res 
  
# A Binomial coefficient based function to find nth catalan number in O(n) time 
def catalan(n):
	# Cn = (1/n+1)(2n!/n!*n!) = 2n!/n!(n+1)!
    c = binomialCoefficient(2*n, n) 
    return c/(n + 1) 
'''
def countBST(n): 
  
    # find nth catalan number  
    count = catalan(n)  
    # return nth catalan number  
    return count

