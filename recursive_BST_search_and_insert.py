class Node(object):
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BST(object):
    def __init__(self, root):
        self.root = Node(root)

    def insert(self, new_val):
        self.insert_helper(self.root, new_val)

    def insert_helper(self, start, new_val):
        if start.value > new_val:
            if start.left != None:
                self.insert_helper(start.left, new_val)
            else:
                start.left = Node(new_val)
        else:
            if start.right != None:
                self.insert_helper(start.right, new_val)
            else:
                start.right = Node(new_val)
            

    def search(self, find_val):
        return self.search_helper(self.root, find_val)
                
    def search_helper(self, start, find_val):
        if start.value == find_val:
            return True
            
        if start.left == None and start.right == None:
            return False
            
        if start.value > find_val:
            if start.left != None:
                return self.search_helper(start.left, find_val)
        else:
            if start.right != None:
                return self.search_helper(start.right, find_val)
        
# Set up tree
tree = BST(4)

# Insert elements
tree.insert(2)
tree.insert(1)
tree.insert(3)
tree.insert(5)

# Check search
# Should be True
print tree.search(1)
# Should be False
print tree.search(6)