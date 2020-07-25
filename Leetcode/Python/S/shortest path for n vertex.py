"""
https://leetcode.com/problems/shortest-path-visiting-all-nodes/
https://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n/0
Shortest path from 1 to n

The task is to find minimum number of edges in a path in G from vertex 1 to vertex 100 such that we can move to either i+1 or 3i from a vertex i.

找出從1到n最短節點數
"""

for _ in range(int(input())):
    n = int(input())
    count = 0
    while n != 1:
        if n%3 == 0:n /= 3
        else:n -= 1
        count += 1
    print(count)
