# Data structure to store the special binary tree node with random pointer
'''
Inorder traversal of original binary tree is:
[4 1], [2 NULL], [5 3], [1 5], [3 NULL],

Inorder traversal of cloned binary tree is:
[4 1], [2 NULL], [5 3], [1 5], [3 NULL],

Inorder traversal of original binary tree is:
[5 9], [6 7], [7 NULL], [8 10], [9 7], [10 6], [11 9], [12 8], [13 NULL],

Inorder traversal of cloned binary tree is:
[5 9], [6 7], [7 NULL], [8 10], [9 7], [10 6], [11 9], [12 8], [13 NULL],
'''
class Node:
	# Constructor
	def __init__(self, data, left=None, right=None, random=None):
		self.data = data
		self.left = left
		self.right = right
		self.random = random


# Function to print the preorder traversal of a binary tree
def preorder(root):

	if root is None:
		return

	# print data
	print(root.data, end=" -> ( ")

	# print left child's data
	print((root.left.data if root.left else "X"), end=", ")

	# print right child's data
	print((root.right.data if root.right else "X"), end=", ")

	# print random child's data
	print((root.random.data if root.random else "X"), ")")

	# recur for the left and right subtree
	preorder(root.left)
	preorder(root.right)


# Recursive function to copy random pointers from the original binary tree
# into the cloned binary tree using the dict
def updateRandomPointers(root, dict):

	# base case
	if dict.get(root) is None:
		return

	# update the random pointer of cloned node
	dict.get(root).random = dict.get(root.random)

	# recur for left and right subtree
	updateRandomPointers(root.left, dict)
	updateRandomPointers(root.right, dict)


# Recursive function to clone the data, left and right pointers for
# each node of a binary tree into a given dict
def cloneLeftRightPointers(root, dict):

	# base case
	if root is None:
		return None

	# clone all fields of the root node except the random pointer

	# create a node with same data as root node
	dict[root] = Node(root.data)

	# clone the left and right subtree
	dict[root].left = cloneLeftRightPointers(root.left, dict)
	dict[root].right = cloneLeftRightPointers(root.right, dict)

	# return cloned root node
	return dict[root]


# Main function to clone a special binary tree with random pointers
def cloneSpecialBinaryTree(root):

	# create a dictionary to store mappings from a node to its clone
	dict = {}

	# clone data, left and right pointers for each node of the original
	# binary tree and put references into the dict
	cloneLeftRightPointers(root, dict)

	# update random pointers from the original binary tree into the dict
	updateRandomPointers(root, dict)

	# return the cloned root node
	return dict[root]


if __name__ == '__main__':

	root = Node(1)
	root.left = Node(2)
	root.right = Node(3)
	root.left.left = Node(4)
	root.left.right = Node(5)
	root.right.left = Node(6)
	root.right.right = Node(7)

	root.random = root.right.left.random
	root.left.left.random = root.right
	root.left.right.random = root
	root.right.left.random = root.left.left
	root.random = root.left

	print("Preorder traversal of the original tree:")
	preorder(root)

	clone = cloneSpecialBinaryTree(root)

	print("\nPreorder traversal of the cloned tree:")
	preorder(clone)
