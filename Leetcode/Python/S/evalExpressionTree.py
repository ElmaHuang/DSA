'''
+ * - 5 4 100 20
==>100

- 4 7 
==>-3
'''
# bottom up
def setIt(root):
	if root == None:
		return
	if (root.right == None) and (root.left == None):
		return
	evalExpressionTree(root.left)
	evalExpressionTree(root.right)

	if root.data == "*":
		root.data = int(root.left.data) * int(root.right.data)
	elif root.data == "/":
		root.data = int(int(root.left.data) / int(root.right.data))
	elif root.data == "+":
		root.data = int(root.left.data) + int(root.right.data)
	elif root.data == "-":
		root.data = int(root.left.data) - int(root.right.data)

def evalExpressionTree(root):
	setIt(root)
	return root.data