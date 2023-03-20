from main import process_2

def test():
    answer = process_2(num_1=2, num_2=5, string='1 2 3 4 5')
    assert answer == '0 0\n1 0\n0 1\n1 2\n0 4\n'
    answer = process_2(4, 10, '3 0 9 2 8 1 9 8 8 4')
    assert answer == '0 0\n1 0\n1 0\n2 0\n3 0\n2 2\n0 3\n2 3\n3 8\n1 9\n'
    answer = process_2(2, 15, '0 0 1 0 0 0 2 1 2 3 0 0 0 2 1')
    assert answer == '0 0\n0 0\n0 0\n1 0\n1 0\n1 0\n1 0\n0 1\n0 2\n1 2\n0 4\n0 4\n0 4\n0 4\n1 5\n'