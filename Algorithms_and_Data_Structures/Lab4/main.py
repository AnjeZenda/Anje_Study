Q = 257
X = 17

def hash_string(string: str) -> int:
    global X, Q
    l = len(string)
    result = 0
    for i in range(l):
        result = (X * result + ord(string[i])) % Q
    return result

def rabin_karp_algorithm(text: str, pattern: str) -> int:
    global Q, X
    text_len = len(text)
    pattern_len = len(pattern)

    multiplier = 1
    for i in range(1, pattern_len):
        multiplier = (multiplier * X) % Q
    
    pattern_hash = hash_string(pattern)
    substring_hash = hash_string(text[:pattern_len])

    count = 0
    for i in range(text_len - pattern_len + 1):
        if pattern_hash == substring_hash and text[i : i+pattern_len] == pattern:
            count += 1
            print(i, end=' ')

        if i < text_len - pattern_len:
            substring_hash = ((substring_hash - ord(text[i]) * multiplier) * X + ord(text[i + pattern_len])) % Q
            
            if substring_hash < 0:
                substring_hash += Q
    
    return count

def rabin_karp_algorithm_array(text: str, pattern: str, answer: list) -> None:
    global Q, X
    text_len = len(text)
    pattern_len = len(pattern)

    multiplier = 1
    for i in range(1, pattern_len):
        multiplier = (multiplier * X) % Q
    
    pattern_hash = hash_string(pattern)
    substring_hash = hash_string(text[:pattern_len])

    for i in range(text_len - pattern_len + 1):
        if pattern_hash == substring_hash and text[i : i+pattern_len] == pattern:
            answer.append(i)

        if i < text_len - pattern_len:
            substring_hash = ((substring_hash - ord(text[i]) * multiplier) * X + ord(text[i + pattern_len])) % Q
            
            if substring_hash < 0:
                substring_hash += Q