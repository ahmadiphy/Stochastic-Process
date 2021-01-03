
# coding: utf-8

import random
from collections import Counter
import matplotlib.pyplot as plt

def b(M, dl):
    myl = []
    N = len(dl)
    result = 0
    for i in range(N):
        if dl[i] == M and i != N-1:
            myl.append(dl[i+1])
    if len(myl) != 0:
        c = Counter(myl)
        xs = list(set(myl))
        for i in xs:
            result += i * c[i]/M
    return result/N
def b_list(mydata):
    m_list = list(set(mydata))
    resultx = []
    resulty = []
    for i in m_list:
        bm = b(i, mydata)
        if bm != 0:
            resultx.append(i)
            resulty.append(bm)
    return [resultx, resulty]

random_list = []
for x in range(100000):
  random_list.append(random.randint(1, 1000))

bm=b_list(random_list)

p1,= plt.plot(bm[0], bm[1], linestyle='', marker='s')
plt.show()

p2,= plt.loglog(bm[0], bm[1], linestyle='', marker='s')
plt.show()
