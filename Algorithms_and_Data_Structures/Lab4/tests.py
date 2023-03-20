from main import rabin_karp_algorithm_array

def test():
    answer = []
    rabin_karp_algorithm_array('ababaaaba', 'aba', answer)
    assert answer == [0, 2, 6]
    answer.clear()
    rabin_karp_algorithm_array('AAABBBCCCKEKEKEKEKeaasasdKEKasfsdxvcxcasjdfnnKEKKEKEK', 'KEK', answer)
    assert answer == [9, 11, 13, 15, 25, 45, 48, 50]
    answer.clear()
    rabin_karp_algorithm_array('afsdjjxcbjasdfhjbvcxlsdfjkcvnsdfjcxvbjfdadsjfkaaaa', 'a', answer)
    assert answer == [0, 10, 40, 46, 47, 48, 49]