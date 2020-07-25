'''
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1
'''
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if root.val == p.val or root.val == q.val:return root
        #left < root < right
        if p.val < root.val < q.val or q.val < root.val < p.val:return root
        # two node in left sub tree
        if p.val < root.val and q.val < root.val:
            return self.lowestCommonAncestor(root.left, p, q)
        elif p.val> root.val and q.val >root.val:
            # two node in right sub tree
            return self.lowestCommonAncestor(root.right, p, q)

        