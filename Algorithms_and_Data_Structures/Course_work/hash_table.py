class HashTable:
    def __init__(self, size=128) -> None:
        self.size = size
        self.table = [[], ] * self.size
        self.element = 0
    
    def first_hash_func(self, key):
        return 23 # key * 19 % self.size
    
    def second_hash_func(self, key):
        h = key * 19 % self.size
        if h % 2:
            return h
        return (h - 1 + self.size) % self.size
    
    def find(self, key):
        first_hash = self.first_hash_func(key)
        if len(self.table[first_hash]) != 0 and key == self.table[first_hash][0]:
            return self.table[first_hash][1]
        second_hash = self.second_hash_func(key)
        elem_hash = (first_hash + second_hash) % self.size
        i = 1
        while len(self.table[elem_hash]) != 0 and i != self.size:
            if self.table[elem_hash][0] == key:
                return self.table[elem_hash][1]
            i += 1
            elem_hash = (first_hash + i * second_hash) % self.size
        return None
    
    def _find(self, key):
        first_hash = self.first_hash_func(key)
        if len(self.table[first_hash]) != 0 and key == self.table[first_hash][0]:
            return first_hash
        second_hash = self.second_hash_func(key)
        elem_hash = (first_hash + second_hash) % self.size
        i = 1
        while i != self.size:
            if len(self.table[elem_hash]) != 0 and self.table[elem_hash][0] == key:
                return elem_hash
            i += 1
            elem_hash = (first_hash + i * second_hash) % self.size
        return None

    def _insert(self, key, data):
        first_hash = self.first_hash_func(key)
        if len(self.table[first_hash]) == 0:
            self.table[first_hash] = data
            return
        second_hash = self.second_hash_func(key)
        elem_hash = (first_hash + second_hash) % self.size
        i = 1
        while len(self.table[elem_hash]) != 0:
            i += 1
            elem_hash = (first_hash + i * second_hash) % self.size
        if len(self.table[elem_hash]) == 0:
            self.table[elem_hash] = data
            return
            

    def insert(self, key, data):
        first_hash = self.first_hash_func(key)
        if len(self.table[first_hash]) == 0:
            self.table[first_hash] = data
            self.element += 1
            self.resize()
            return
        second_hash = self.second_hash_func(key)
        elem_hash = (first_hash + second_hash) % self.size
        i = 1
        while len(self.table[elem_hash]) != 0 and i != self.size:
            i += 1
            elem_hash = (first_hash + i * second_hash) % self.size
        if len(self.table[elem_hash]) == 0:
            self.table[elem_hash] = data
            self.element += 1
            self.resize()
            return
        print('No place to insert')
    
    def delete(self, key):
        index = self._find(key)
        if index != None:
            self.table[index] = []
            self.element -= 1
            self.resize(True)
            return
        print('No such element')

    def resize(self, delete=False):
        alpha = self.element / self.size * 100
        if alpha > 70:
            info = self.table
            self.size *= 2
            self.table = [[], ] * self.size
            for elem in info:
                if len(elem) != 0:
                    self._insert(elem[0], elem)
        elif alpha < 30 and delete and self.size > 128:
            info = self.table
            self.size //= 2
            self.table = [[], ] * self.size
            for elem in info:
                if len(elem) != 0:
                    self._insert(elem[0], elem)
