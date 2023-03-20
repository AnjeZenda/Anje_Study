def find_heigh(tree, root):
    queue = []
    length = 0
    while root:
        queue = root
        root = []
        for elem in queue:
            root += tree[elem]
        length += 1
    return length

def make_children_list(parents, n):
    children_list = [[] for x in range(n+1)]
    if type(parents) == list:
        for i in range(n):  
            children_list[parents[i]].append(i)
    elif type(parents) == str:
        if parents == '':
            return children_list
        parents_list = list(map(int, parents.split(' ')))
        for i in range(n):  
            children_list[parents_list[i]].append(i)
    return children_list

n = int(input())
parents = input()

print(find_heigh(make_children_list(parents, n), make_children_list(parents, n)[-1]))

