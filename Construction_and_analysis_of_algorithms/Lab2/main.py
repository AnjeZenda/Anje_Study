class Graph:
    def __init__(self, arcs_kit, start_node, finish_node) -> None:
        self.start_node = start_node
        self.arcs_kit = arcs_kit
        self.finish_node = finish_node

    def get_neighbours(self, node):
        return self.arcs_kit[node] if node in self.arcs_kit else None
    
    def heuristic_function(self, node):
        return ord(self.finish_node) - ord(node)
    
    def a_star_algorithm(self):
        open_set = set(self.start_node) 
        closed_set = set() 
        
        distance = {} 
        distance[self.start_node] = 0

        adjacent_nodes = {} 
        adjacent_nodes[self.start_node] = self.start_node

        while len(open_set) > 0:
            current_node = None
            
            for node in open_set:
                if current_node == None or\
                    distance[node] + self.heuristic_function(node) <\
                    distance[current_node] + self.heuristic_function(current_node):
                    current_node = node
            
            if not current_node:
                return None
            
            if current_node == self.finish_node:
                reverse_path = ''
                while adjacent_nodes[current_node] != current_node:
                    reverse_path += current_node
                    current_node = adjacent_nodes[current_node]
                reverse_path += current_node
                return reverse_path[::-1]
            
            neighbours = self.get_neighbours(current_node)
            if neighbours == None:
                open_set.remove(current_node)
                closed_set.add(current_node)
                continue

            for (node, weight) in neighbours:
                if node not in open_set and node not in closed_set:
                    open_set.add(node)
                    adjacent_nodes[node] = current_node
                    distance[node] = distance[current_node] + weight
                elif distance[node] > distance[current_node] + weight:
                    distance[node] = distance[current_node] + weight
                    adjacent_nodes[node] = current_node
                    if node in closed_set:
                        closed_set.remove(node)
                        open_set.add(node)
            open_set.remove(current_node)
            closed_set.add(current_node)
        
        return None
    
    def greedy_algorithm(self):
        for node in self.arcs_kit:
            self.arcs_kit[node].sort(key=lambda x: x[1])
        
        path = self.start_node
        while path[-1] != self.finish_node:
            current_last_node = path[-1]
            if self.arcs_kit[current_last_node][0][0] not in self.arcs_kit \
                and self.arcs_kit[current_last_node][0][0] != self.finish_node:
                self.arcs_kit[current_last_node].pop(0)
            path += self.arcs_kit[current_last_node][0][0]
        return path


def solve():
    start_node, finish_node = input().split()
    arcs_kit = {}

    while True:
        try:
            arc = input().split()
            if arc[0] in arcs_kit:
                arcs_kit[arc[0]].append([arc[1], float(arc[2])])
            else:
                arcs_kit[arc[0]] = [[arc[1], float(arc[2])]]
        except:
            break

    graph = Graph(arcs_kit, start_node, finish_node)
    print(graph.greedy_algorithm())
    print(graph.a_star_algorithm())

def main():
    solve()

main()