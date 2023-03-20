from main import Matrix, merge, create_matrix_list_from_str

def test():
    string = '3\n2\n1 2\n1 31\n3\n1 1 1\n1 11 1\n1 1 -1\n5\n1 2 0 1 -1\n1 2 0 1 -1\n1 2 0 1 -1\n1 2 0 1 -1\n1 2 0 1 -1'
    matrix_list = create_matrix_list_from_str(string)
    merge(matrix_list)
    expected_result = [Matrix(5, 2), Matrix(3, 1), Matrix(2, 0)]
    expected_result[0].set_diag(3)
    expected_result[1].set_diag(11)
    expected_result[2].set_diag(32)
    assert matrix_list == expected_result