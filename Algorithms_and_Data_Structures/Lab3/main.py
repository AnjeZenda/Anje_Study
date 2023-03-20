class MinHeap:
    def __init__(self, size) -> None:
        self.size = size
        self.view = [[0, i] for i in range(size)]

    def parent(self, index):
        return (index - 1) // 2
    def left_child(self, index):
        return 2 * index + 1
    def right_child(self, index):
        return 2 * index + 2

    def sift_down(self, index):
        left = self.left_child(index)
        right = self.right_child(index)
        if left >= self.size and right >= self.size:
            return
        ind = index
        if left < self.size and self.view[left] < self.view[ind]:
            ind = left
        if right < self.size and self.view[right] < self.view[ind]:
            ind = right

        if ind != index:
            self.view[ind], self.view[index] = self.view[index], self.view[ind]
            self.sift_down(ind)

def process_1():
    n, m = map(int, input().split())
    arr = list(map(int, input().split()))[:m]
    min_heap = MinHeap(n)
    for elem in arr:
        print(min_heap.view[0][1], min_heap.view[0][0])
        min_heap.view[0][0] += elem
        min_heap.sift_down(0)


def process_2(num_1 : int, num_2 : int, string : str):
    n, m = num_1, num_2
    arr = list(map(int, string.split()))[:m]
    answer = ''
    min_heap = MinHeap(n)

    for elem in arr:
        answer += f'{min_heap.view[0][1]} {min_heap.view[0][0]}\n'
        min_heap.view[0][0] += elem
        min_heap.sift_down(0)
    
    return answer
