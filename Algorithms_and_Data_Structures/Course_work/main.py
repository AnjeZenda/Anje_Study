from random import randint
import matplotlib.pyplot as plt
import hash_table
import btree
import time

tree = btree.BTree(50)
hash = hash_table.HashTable(128)

x = [i for i in range(1_000_000)]
total = []
total_del = []
ins=[]
fnd=[]
dlt=[]

for i in range(1000):
    total.append(i)
    start = time.time_ns()
    # hash.insert(i, [i, 's'])
    for j in x[i * 1000: (i + 1) * 1000]:
        tree.insert([j, j*17])
    end = time.time_ns()
    ins.append(end - start)


for i in range(1000):
    start = time.time_ns()
    # hash.find(i)
    for j in x[i * 1000: (i + 1) * 1000]:
        tree.find(j)
    end = time.time_ns()
    fnd.append(end - start)


for i in range(1000):
    total_del.append(1000 - i)
    start = time.time_ns()
    # hash.delete(i)
    for j in x[i * 1000: (i + 1) * 1000]:
        tree.delete(tree.root, j)
    end = time.time_ns()
    dlt.append(end - start)






plt.title('Операция сложности операций в хеш-таблице в лучшем случае')
plt.xlabel("Число элементов")
plt.ylabel("Время, нс")
plt.grid()
plt.scatter(total, ins, s = 5, color = ["red"])    #Вставка элемента
plt.scatter(total, fnd , s = 5, color = ["green"])  #Поиск элемента
plt.scatter(total_del, dlt , s = 5, color = ["blue"])   #Удаление элемента
plt.legend(['Сложность вставки', 'Сложность поиска', 'Сложность удаления'])
plt.show()
