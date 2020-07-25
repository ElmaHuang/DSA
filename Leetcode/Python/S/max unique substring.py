'''
https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring/0
Given a string, find the length of the longest substring without repeating characters. For example, the longest substrings without repeating characters for “ABDEFGABEF” are “BDEFGA” and “DEFGAB”, with length 6.
Input:
2
geeksforgeeks
qwertqwer

Output:
7
5

For Input:
1
werfvbjisrgvbn

Your Output is:
9

Input:
1
qwertyuioplkjhgfdsazxcvbn

Output:
25

Input :
1
ashdfkjahdjkfbbnmbuicae

Output:
8
@@ wrong answer @@@@@@@@@@@@@@@@@
'''
def uniqueSubString(input_str):
	size = len(input_str)
	if size <=1: return size
	max_len = 0
	start_idx = 0
	while start_idx < size:
		for end_idx in range(start_idx+1,size):
			#get repeat
			if input_str[end_idx] in input_str[start_idx:end_idx]:
				max_len = max(max_len, end_idx-start_idx)
				break
		start_idx+=1
	return max_len if max_len !=0 else size
'''	
if __name__=="__main__":
    input_size = input()
    for _ in range(int(input_size)):
        input_str = input()
        print(uniqueSubString(input_str))
'''