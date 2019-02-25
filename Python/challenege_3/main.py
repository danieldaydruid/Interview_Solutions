'''
This problem was asked by Google:

Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.

For example, given the following Node class

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

The following test should pass,

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'

'''
class tree_node:
	def __init__(self, data):
		self.right = None
		self.left = None
		self.data = data
	def insert(self, data):
		if self.data:
			if data < self.data:
				if self.left is None:
					self.left = tree_node(data)
				else:
					self.left.insert(data)
			elif data > self.data:
				if self.right is None:
					self.right = tree_node(data)
				else:
					self.right.insert(data)
		else:
			self.data = data
	def print_tree(self):
		if self.left:
			self.left.print_tree()
		print(self.data)
		if self.right:
			self.right.print_tree()
	#Serialize function implementation, not tested
	def serialize_tree(self):
		if self.left:
			self.left.serialize_tree()
		tree_string = tree_string + str(self.data)
		if self.right:
			self.right.serialize_tree()
def main():
	root = tree_node(12)
	root.insert(1)
	root.insert(2)
	root.insert(100)
	root.insert(39)
	root.print_tree()
main()
