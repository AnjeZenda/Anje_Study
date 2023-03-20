from main import find_heigh, make_children_list

def test():
    children = make_children_list([9, 7, 5, 5, 2, 9, 9, 9, 2, -1], 10)
    assert find_heigh(children, children[-1]) == 4
    children = make_children_list([4, -1, 4, 1, 1], 5)
    assert find_heigh(children, children[-1]) == 3
    children = make_children_list([-1, 0, 4, 0, 3], 5)
    assert find_heigh(children, children[-1]) == 4
    children = make_children_list('-1', 1)
    assert find_heigh(children, children[-1]) == 1
    children = make_children_list('', 0)
    assert find_heigh(children, children[-1]) == 0