import sys
sys.setrecursionlimit(100000)

class BTreeNode:
    def __init__(self, leaf=False) -> None:
        self.leaf = leaf
        self.keys = []
        self.child = []

    def __len__(self):
        return len(self.keys)

    def __search_index(self, key):
        left = -1
        right = len(self)
        while right - left > 1:
            middle = (left + right) // 2
            if self.keys[middle][0] < key:
                left = middle
            else:
                right = middle
        return right

    def find(self, key):
        return self.__search_index(key)
    

class BTree:
    def __init__(self, t=4) -> None:
        self.root = BTreeNode(True)
        self.t = t

    def insert(self, data):
        root = self.root
        if len(root.keys) == 2 * self.t - 1:
            temp = BTreeNode()
            self.root = temp
            temp.child.insert(0, root)
            self.split_child(temp, 0)
            self.insert_non_full(temp, data)
        else:
            self.insert_non_full(root, data)

    def insert_non_full(self, node: BTreeNode, data):
        i = len(node.keys) - 1
        if node.leaf:
            node.keys.append([None, None])
            while i >= 0 and data[0] < node.keys[i][0]: # Insert if key less that current key
                node.keys[i + 1] = node.keys[i]
                i -= 1
            node.keys[i + 1] = data
        else:
            while i >= 0 and data[0] < node.keys[i][0]:
                i -= 1
            i += 1
            if len(node.child[i].keys) == 2 * self.t - 1:
                self.split_child(node, i)
                if data[0] > node.keys[i][0]:
                    i += 1
            self.insert_non_full(node.child[i], data)
    
    def split_child(self, node, i):
        t = self.t
        left_children = node.child[i]
        right_children = BTreeNode(left_children.leaf)
        node.child.insert(i + 1, right_children)
        node.keys.insert(i, left_children.keys[t - 1])
        right_children.keys = left_children.keys[t: (2 * t) - 1]
        left_children.keys = left_children.keys[0: t - 1]
        if not left_children.leaf:
            right_children.child = left_children.child[t: 2 * t]
            left_children.child = left_children.child[0: t]

    def print_tree(self, node, level=0):
        print("Level ", level, " ", len(node.keys), end=":")
        for i in node.keys:
            print(i, end=" ")
        print()
        level += 1
        if len(node.child) > 0:
            for i in node.child:
                self.print_tree(i, level)

    def find(self, key: int, node: None|BTreeNode=None):
        if node is not None:
            i = 0
            while i < len(node.keys) and key > node.keys[i][0]:
                i += 1
            if i < len(node.keys) and key == node.keys[i][0]:
                return node.keys[i]
            elif node.leaf:
                return None
            else:                
                return self.find(key, node.child[i])
        else:
            return self.find(key, self.root)

    def __remove(self, node: BTreeNode, index: int):
        if node.leaf:
            node.keys.pop(index)
            return
        left = node.child[index]
        right = node.child[index + 1]
        if max(len(left), len(right)) == self.t - 1:
            new_index = len(left)
            new_node = self.merge_children(node, index)
        elif len(left) > len(right):
            new_node = self.move_key_right(node, index)
            new_index = 0
        else:
            new_node = self.move_key_left(node, index)
            new_index = len(new_node) - 1
        self.__remove(new_node, new_index)


    def delete(self, node: BTreeNode, key: int):
        if self.find(key) == None:
            return
        current_node = self.root
        while current_node:
            index = current_node.find(key)
            if index < len(current_node) and current_node.keys[index][0] == key:
                self.__remove(current_node, index)
                break
            
            next_node = current_node.child[index]
            if len(next_node) == self.t - 1:
                if index != len(current_node) and \
                    (index == 0 or len(current_node.child[index + 1]) > len(current_node.child[index - 1])):
                    if len(next_node) == len(current_node.child[index + 1]):
                        next_node = self.merge_children(current_node, index)
                    else:
                        next_node = self.move_key_left(current_node, index)
                else:
                    if len(next_node) == len(current_node.child[index - 1]):
                        next_node = self.merge_children(current_node, index - 1)
                    else:
                        next_node = self.move_key_right(current_node, index - 1)
            current_node = next_node
        
        if not len(self.root) and len(self.root.child) != 0:
            self.root = self.root.child[0]
            
    def merge_children(self, node: BTreeNode, index: int):
        left = node.child[index]
        right = node.child[index + 1]
        new_node = BTreeNode(left.leaf)
        new_node.keys = left.keys + [node.keys[index]] + right.keys
        new_node.child = left.child + right.child
        node.keys.pop(index)
        node.child.pop(index)
        node.child[index] = new_node
        return new_node

    def move_key_left(self, node: BTreeNode, index: int) -> BTreeNode:
        left = node.child[index]
        right = node.child[index + 1]
        left.keys.append(node.keys[index])
        if not right.leaf:
            left.child.append(right.child[0])
        node.keys[index] = right.keys[0]
        right.keys.pop(0)
        if not right.leaf:
            right.child.pop(0)
        return left
    
    def move_key_right(self, node: BTreeNode, index: int) -> BTreeNode:
        left = node.child[index]
        right = node.child[index + 1]
        right.keys.insert(0, node.keys[index])
        if not left.leaf:
            right.child.insert(0, left.child[-1])
        node.keys[index] = left.keys[-1]
        left.keys.pop()
        if not left.leaf:
            left.child.pop()
        return right
