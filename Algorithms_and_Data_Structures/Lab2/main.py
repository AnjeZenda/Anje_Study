class Matrix:
    def __init__(self, size, number):
        self.size = size
        self.diag = 0
        self.num = number

    def set_diag(self, diag):
        self.diag = diag

    def __eq__(self, other) -> bool:
        return self.diag == other.diag

    def __lt__(self, other):
        return self.diag < other.diag
    def __le__(self, other):
        return self.diag <= other.diag
    def __ne__(self, other):
        return self.diag != other.diag
    def __gt__(self, other):
        return self.diag > other.diag
    def __ge__(self, other):
        return self.diag >= other.diag

    def __str__(self) -> str:
        return f'{self.num}'

def merge(arr):
    if len(arr) == 1:
        return
    middle = len(arr) // 2
    left, right = arr[:middle], arr[middle:]
    merge(left)
    merge(right)
    index_left = index_right = index = 0
    result = [0] * (len(left) + len(right))
    while index_left < len(left) and index_right < len(right):
        if left[index_left] <= right[index_right]:
            result[index] = left[index_left]
            index_left += 1
        else:
            result[index] = right[index_right]
            index_right += 1
        index += 1
    while index_left < len(left):
        result[index] = left[index_left]
        index_left += 1
        index += 1
    while index_right < len(right):
        result[index] = right[index_right]
        index_right += 1
        index += 1
    for i in range(len(arr)):
        arr[i] = result[i]
    for elem in arr:
        print(elem, end=' ')
    print()
    return arr

def create_matrix_list_from_str(string:str):
    arr = string.split('\n')
    matrix_list = []
    n = int(arr[0])
    arr = arr[1:]
    for i in range(n):
        size = int(arr[0])
        matrix_list.append(Matrix(size, i))
        diag = 0
        matrix = []
        for j in range(size):
            elem = list(map(int, arr[j+1].split()))
            matrix.append(elem)
            diag += matrix[j][j]
        matrix_list[i].set_diag(diag)
        arr = arr[size + 1:]
    return matrix_list


if __name__ == '__main__':
    n = int(input())
    matrix_list = []

    for i in range(n):
        size = int(input())
        matrix_list.append(Matrix(size, i))
        diag = 0
        matrix = []
        for j in range(size):
            elem = list(map(int, input().split()))
            matrix.append(elem)
            diag += matrix[j][j]
        matrix_list[i].set_diag(diag)

    merge(matrix_list)

    print(' '.join(list(map(str, matrix_list))))
