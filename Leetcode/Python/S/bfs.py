"""
BFS to find every level tree node for BST 
"""
from collections import deque

def bfs(head):
	node_queue = deque()
	max_node_num = 0
	#level 0
	node_queue.append(head)
	while node_queue:
		if len(node_queue) > max_node_num:
			max_node_num = len(node_queue)
		#push child
		for node in node_queue: 
			head = node_queue.popleft()
			node_queue.append(head.left)
			node_queue.append(head.right)

